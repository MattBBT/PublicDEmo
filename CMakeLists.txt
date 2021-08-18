cmake_minimum_required(VERSION 3.17)
project(Demo)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_NAME Demo)

get_filename_component(root ${PROJECT_ROOT_DIR} ABSOLUTE)
add_executable(${EXECUTABLE_NAME}
    ${root}/main.c)
