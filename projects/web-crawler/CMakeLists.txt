cmake_minimum_required(VERSION 3.10)
project(WebCrawler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)
find_package(Threads REQUIRED)

include_directories(${CURL_INCLUDE_DIRS} include)

add_executable(web_crawler
    src/main.cpp
    src/Crawler.cpp
    src/HttpClient.cpp
    src/Parser.cpp
    src/RobotsTxt.cpp
    src/QueueManager.cpp
    src/Visualizer.cpp
)

target_link_libraries(web_crawler ${CURL_LIBRARIES} Threads::Threads)
