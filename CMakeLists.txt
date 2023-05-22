cmake_minimum_required(VERSION 3.25)
project(cos)

set(CMAKE_CXX_STANDARD 17)

add_executable(cos main.cpp similarity.h similarity.cpp utils.h)
