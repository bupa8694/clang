cmake_minimum_required(VERSION 3.24)
project(clang)

set(CMAKE_CXX_STANDARD 23)

add_executable(clang main.cpp logger.h hype.cpp logger.cpp hype.h)
