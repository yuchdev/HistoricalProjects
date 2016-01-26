#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "telemetry.h"
#include "raw_binary_archive.h"

using boost::asio::ip::udp;

enum {
    max_length = 1024
};

/** @brief Asynchronuous UDP echo-client */
class udp_async_client : public boost::enable_shared_from_this<udp_async_client> {
public:

    /** @brief Constructor without any actions instead of init */
    udp_async_client(boost::asio::io_service& io_service, std::string& host, std::string port)
    : _exit_flag(false)
    , _packet_counter()
    , _host(host), _port(port)
    , _reply()
    , _io_service(io_service)
    , _work(io_service)
    , _sock(io_service, udp::endpoint(udp::v4(), 0)) { 
        outbound_data_.reserve(max_length);
    }

    /** @brief Use separate thread to put async task to io_service queue */
    void start_message_loop() {
        boost::thread t(&udp_async_client::message_loop, this);
    }

    /** @brief Thread method sending requests with timeout */
    void message_loop() {
        while (!_exit_flag) {
            _io_service.post(boost::bind(&udp_async_client::send_request, this));
            boost::this_thread::sleep(boost::posix_time::millisec(500));
        }
    }

    /** @brief Cleanup io_service to dismiss already putted tasks */
    ~udp_async_client() {
        _io_service.stop();
    }

    /** @brief Async request to server */
    void send_request() {

        udp::resolver resolver(_io_service);
        udp::resolver::query query(udp::v4(), _host, _port);
        udp::resolver::iterator iterator = resolver.resolve(query);

        // send request packet here
        boost::mutex::scoped_lock some_lock(cout_mutex1);
        TelemetryRequest t;
        size_t request_length = TelemetryRequest::telemetryRequestPacketSize;
        std::cout << "Request is: ";// << t.get_debug_info() << std::endl;
        t.print_debug_info(std::cout);

        // serialize it to network packet
        std::ostringstream archive_stream;
        raw_binary_oarchive archive(archive_stream);
        archive << t;
        outbound_data_ = archive_stream.str();

        // send to server
        _sock.send_to(boost::asio::buffer(&outbound_data_[0], request_length)
                , *iterator);

        // handle responce
        udp::endpoint sender_endpoint;
        _sock.async_receive_from(boost::asio::buffer(_reply)
                , sender_endpoint
                , boost::bind(&udp_async_client::handle_responce
                , this, boost::asio::placeholders::error
                , boost::asio::placeholders::bytes_transferred));
    }

    /** @brief Handle async responce from server */
    void handle_responce(const boost::system::error_code& error
            , std::size_t bytes_transferred) {
        if (!error || error == boost::asio::error::message_size) {

            // lock for appropriate debug output while several clients procesing
            boost::mutex::scoped_lock some_lock(cout_mutex2);
            try {
                _packet_counter++;
                std::cout << "Handled " << _packet_counter << " packets" << std::endl;

                // deserialize response here
                TelemetryResponse t;
                std::string archive_data(_reply.elems
                        , _reply.elems + TelemetryResponse::telemetryResponsePacketSize);

                // show response information
                std::istringstream archive_stream(archive_data, std::ios::binary);
                raw_binary_iarchive archive(archive_stream);
                archive >> boost::serialization::make_nvp("Test_Object", t);
                t.print_debug_info(std::cout);

            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }

        }
    }

private:

    /** @brief Debug output synchronisation */
    boost::mutex cout_mutex1;
    boost::mutex cout_mutex2;

    /** @brief Just said that exit should be handled */
    bool _exit_flag;

    /** @brief Handled packets counter - just additional information */
    unsigned _packet_counter;

    /** @brief Server host */
    std::string _host;

    /** @brief Server UDP port */
    std::string _port;

    /** @brief It's better to use boost::array for data buffer insted of arrays */
    boost::array<char, max_length> _reply;

    /** @brief Async services wrapper (must be started in separate thread) */
    boost::asio::io_service& _io_service;

    /** @brief Work wrapper to prevent io_service.stop() after queue empty */
    boost::asio::io_service::work _work;

    /** @brief UDP socket */
    udp::socket _sock;

    /** @brief Buffer for request */
    std::string outbound_data_;
};

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Usage: nonblocking_udp_echo_client <host> <port1> <port2>\n";
            return 1;
        }

        std::string host(argv[1]);
        std::string port1(argv[2]);
        std::string port2(argv[3]);

        boost::asio::io_service io_service;

        // async client
        udp_async_client c1(io_service, host, port1);
        udp_async_client c2(io_service, host, port2);


        // io_service::run must be performed
        // 1. After client creation (to let him put something to queue)
        // 2. In separate thread
        boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));

        // start sending requests
        c1.start_message_loop();
        c2.start_message_loop();
        t.join();

    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}