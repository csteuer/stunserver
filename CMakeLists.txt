cmake_minimum_required(VERSION 3.2.2 FATAL_ERROR)
project(stuntman VERSION 1.2.16 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

add_subdirectory(common)
add_subdirectory(networkutils)
add_subdirectory(resources)
add_subdirectory(stuncore)
add_subdirectory(testcode)
add_subdirectory(server)
add_subdirectory(client)
