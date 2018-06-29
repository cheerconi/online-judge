cmake_minimum_required(VERSION 3.10)
project(Printer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Printer main.cpp)

add_definitions(-D LOCAL)
