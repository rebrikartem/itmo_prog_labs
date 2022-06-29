cmake_minimum_required(VERSION 3.15.3)
project(lab2)

include_directories(json-3.10.5/include)

set(CMAKE_CXX_STANDARD 17)

add_library(classes classes.h classes.cpp)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

add_executable(lab2 lab2.cpp)

include_directories(${CURL_INCLUDE_DIR})

target_link_libraries(lab2 ${CURL_LIBRARIES} classes)