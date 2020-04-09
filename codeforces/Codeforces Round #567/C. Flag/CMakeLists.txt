cmake_minimum_required(VERSION 3.14)
project(C__Flag)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__Flag main.cpp)

add_definitions(-D LOCAL)
