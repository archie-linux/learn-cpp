cmake_minimum_required(VERSION 3.10)
project(SimpleShell)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(simple_shell
    src/main.cpp
    src/shell.cpp
    src/parser.cpp
    src/executor.cpp
)
