cmake_minimum_required(VERSION 3.10)
project(WebProxySuite)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(webproxy
    src/main.cpp
    src/proxy_server.cpp
    src/http_parser.cpp
    src/logger.cpp
    src/web_server.cpp
)

target_include_directories(webproxy PRIVATE include)
target_link_libraries(webproxy pthread)  # For potential threading extensions
