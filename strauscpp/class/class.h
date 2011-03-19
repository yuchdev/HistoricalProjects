#pragma once
#include <string>

// � ������ ������ ��������������� ��������� �������� ������
// � ��������, ������������ � ������������ �������
// ������������ � �������� ��������
// ������ ������ ������������, ������������ mutable

class A{

public:

	// �.�. ����� �������� ����������� �����
	// ����������� �� ��������� �� ����� ���� ������
	//A(); (�� �� ��� ������)

	A() : a1(10), a5(0), a8(0), cp1(0){}
	
	// ��� ������������� ����� ����� ���� ��������� ����� ������ ()
	A(int a) : a1(a), a5(), a8(), cp1(){}
	A(int, int, int);
	
	int get_int1() const;
	int get_int6() const;
	
	void set_a5(int);

	void set_a6_mutable(int) const;

// ����� ����� �������� ��������� ������ � �����, 
// ����� ������� ������ �� �������� ������ ����������
// � ���� ������ ���������� ������ ����� ��������� 
// �� ��������� ���������� ������ � ��� �� ������
private:
	const int a1; // ����������� ����, �.�. ���������������� � ������������
	static const int a2 = 10; // ����������� ����������� ���� �.�. ����. � ����������
	static const int a3;       // �.�. ����. � cpp
	static const double a4;    // �.�. ����. � cpp
	

	int a5;
	// ������������� ����������� �����
	static int a6;
	static double a7;

	// !!! � �������� �������� ����� ������ ������������ 
	// ����� ������������� ������������
	enum{ c1 = 5, c2 = 7, c3 = 12 };

	// ���� ���� �������� mutable, �� �� ������� ������
	// ���� ������� ������ ������������ �������
	mutable int a8;

	// ������������� ����������
	char *const cp1; // ����������� ���������
	char const* cp2; // ��������� �� ���������
	const char* cp3; // ��������� �� ���������

	// ���������� ������������� �������, ����������� ����� ���������, 
	// � ���� ��������� const. ���� �������� ����� ����� "*", ���� const �����, 
	// �� ��� ��������� � �������� ������; ���� ������ - � �������� ���������.
	
	// ����� ����� ������ ���������� "������ ������" - 
	// char *const cp1 - ����������� ��������� �� char
	// char const* cp2 - ��������� �� ����������� char
	// const char* cp3 - ��������� �� char �����������
};


// ����������� ����� - ������ �� ������ � ������
// ����� ���� ������ ��� ��� ������������, ��� � ��� �������������� ����������.
inline int A::get_int1() const	
{ return a1; }

inline int A::get_int6() const	
{ return a6; }


// ������������� ����� - ����� ���� ������ ������
// ��� �������������� ���������� ������
inline void A::set_a5(int i)	
{ a5 = i; }

// ����������� �����, ���������� mutable-����
// ����� ���� ������ ��� ������������ ����������
inline void A::set_a6_mutable(int i)const
{ a8 = i; }


// ������ ����� ����� �������� �����������,
// ���� ��� �������� ������� ������, ��� ������ ���������� ������, 
// � �� ������������� ��������� �������
struct AA{
	int a;
	int b;
};

// ������� �� ������ ������ ����� ����� �������� � ������������ ����

// �������� ��������� ��������, ������� ������
class good_weekday_t{

// ������� - �������� ���������
public:
	
	// ������������ � ������
	enum Wday{ mon = 1, tus, wed, thr, frd, sat, sun };

	// ����� - ����� ���������� � ������ ��������� ������
	class bad_weekday_t{};

	// ������������
	good_weekday_t(int day = mon) : _wday(day){}
	good_weekday_t(std::string& sday){/*����� �������������� ������ � ���� ������*/}

	// ����������� ������ ������� � ������
	Wday get_weekday() const;
	std::string get_weekday_str() const;

	// ��������� ���� ����
	bool operator==(const good_weekday_t& w);
	bool operator!=(const good_weekday_t& w);
	// ... � ������ ���������

	// �������-���������
	bool is_weekend() const;
	int diff(const good_weekday_t& w) const;
	
	// ������������� ������������
	void set_weekday(int day);

private:
	int _wday;
	std::string _string_day;
}; 
