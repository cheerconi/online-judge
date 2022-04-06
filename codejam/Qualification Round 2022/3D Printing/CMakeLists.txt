cmake_minimum_required(VERSION 3.21)
project(3D_Printing)

set(CMAKE_CXX_STANDARD 17)

add_executable(3D_Printing main.cpp)

add_definitions(-D LOCAL)
