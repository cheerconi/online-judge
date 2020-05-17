cmake_minimum_required(VERSION 3.15)
project(Security_Update)

set(CMAKE_CXX_STANDARD 14)

add_executable(Security_Update main.cpp)

add_definitions(-D LOCAL)
