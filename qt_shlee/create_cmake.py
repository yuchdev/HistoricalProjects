import os, sys, shutil

solution_name = 'qt_shlee'
path = '.'

###########################################################################
def on_rm_error(*args):
    '''
    In case the file or directory is read-only and we need to delete it
    this function will help to remove 'read-only' attribute
    :param args: (func, path, exc_info) yuple
    '''
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    _, path, _ = args
    os.chmod(path, stat.S_IWRITE)
    os.unlink(path)


base_cmake_text = '''cmake_minimum_required(VERSION 3.0)
project({0} CXX)
set(TARGET {1})

if(UNIX)
  message("Unix configuration")

elseif("WIN32")
  message("Windows configuration")
  set(CMAKE_CXX_FLAGS "/EHa")

endif()


########################################################

# CMake policies
cmake_policy(SET CMP0015 NEW)
'''

cmake_text = '''cmake_minimum_required(VERSION 3.0)
project({0} CXX)
set(TARGET {1})

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5Test REQUIRED)
find_package(Qt5WebKit REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)
find_package(Qt5Script REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Declarative REQUIRED)


file(GLOB project_SRCS *.cpp *.h *.qml *.qrc *.ts)

include_directories(${{PROJECT_SOURCE_DIR}})

set(target_qml "${{PROJECT_NAME}}_qml")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable({1} ${{project_SRCS}})

target_link_libraries({1} Qt5::Core Qt5::Widgets {2})
'''

def create_cmake(path, project):
    '''
    :param path: path to the solution
    :param project: project name
    '''
    project_path = os.path.join(path, project)
    f = open(os.path.join(project_path, 'CMakeLists.txt'), 'w')
    if project == 'ch_10_text_edit':
        f.write(cmake_text.format(project, project, "Qt5::PrintSupport"))
    elif project == 'ch_46_qt_test':
        f.write(cmake_text.format(project, project, "Qt5::Test"))
    elif project == 'ch_47_webkit':
        f.write(cmake_text.format(project, project, "Qt5::WebKitWidgets"))
    elif project == 'ch_50_qtscript_basics':
        f.write(cmake_text.format(project, project, "Qt5::Script"))
    elif project == 'ch_53_qml_basics':
        f.write(cmake_text.format(project, project, "Qt5::Quick Qt5::Declarative"))
    else:
        f.write(cmake_text.format(project, project, ""))
    f.close()


def create_base_cmake(root_path, solution_name, projects_list):
    '''
    :param root_path: path to the solution
    :param solution_name: string name of the solution
    :param projects_list: list of projects (subdirectory names)
    '''
    f = open(os.path.join(root_path, 'CMakeLists.txt'), 'w')
    f.write(base_cmake_text.format(solution_name, solution_name))
    for project in projects_list:
        f.write('add_subdirectory({0})\n'.format(project))
    f.close()

def mass_create_cmake(root_path, solution_name):
    '''
    :param root_path: path to the solution
    :param solution_name: string name of the solution
    '''
    projects_list = []
    for project in os.listdir(root_path):
        if os.path.isdir(project):
                create_cmake(root_path, project)
                projects_list.append(project)

    create_base_cmake(root_path, solution_name, projects_list)


def main(argv):
    try:
        if os.path.isdir('build-cmake'):
            shutil.rmtree('build-cmake', onerror=on_rm_error)
        mass_create_cmake(path, solution_name)
        os.mkdir('build-cmake')
        os.chdir('build-cmake')
        return os.system('cmake .. -DCMAKE_PREFIX_PATH=C:/Qt/5.5/msvc2013')
    except IndexError:
        print("Usage: python create_cmake.py <solution_name> <solution_path>")
#    except Exception as e:
#        print('Exception: {0}'.format(e))
    # return non-zero if here
    return 1

###################################
if __name__ == "__main__":
    sys.exit(main(sys.argv))
