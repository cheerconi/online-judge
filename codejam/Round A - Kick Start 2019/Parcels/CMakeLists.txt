cmake_minimum_required(VERSION 3.13)
project(Parcels)

set(CMAKE_CXX_STANDARD 14)

add_executable(Parcels main.cpp)

add_definitions(-D LOCAL)
