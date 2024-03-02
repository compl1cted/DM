cmake_minimum_required(VERSION 3.27)
project(DM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DM
        set.cpp
        set.h
        main.cpp)
