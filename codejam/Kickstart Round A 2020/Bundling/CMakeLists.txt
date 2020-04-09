cmake_minimum_required(VERSION 3.15)
project(Bundling)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bundling main.cpp)

add_definitions(-D LOCAL)
