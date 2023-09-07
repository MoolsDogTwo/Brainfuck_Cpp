cmake_minimum_required(VERSION 3.26)
project(BrainFuck)

set(CMAKE_CXX_STANDARD 23)

add_executable(BrainFuck main.cpp
        syntax.h
        include.h
        operations.cpp
        operations.h
        etc.cpp
        etc.h)
