cmake_minimum_required(VERSION 3.30)
project(SO2_Project1)

set(CMAKE_CXX_STANDARD 20)

add_executable(SO2_Project1 main.cpp
        philosopher.h
        philosopher.cpp)
