cmake_minimum_required(VERSION 3.10)
project(MiniContainer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(mini_container
    src/main.cpp
    src/container.cpp
    src/namespaces.cpp
    src/executor.cpp
)
