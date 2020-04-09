cmake_minimum_required(VERSION 3.13)
project(Contention)

set(CMAKE_CXX_STANDARD 14)

add_executable(Contention main.cpp)

add_definitions(-D LOCAL)
