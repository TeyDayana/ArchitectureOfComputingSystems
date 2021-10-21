cmake_minimum_required(VERSION 3.16)
project(abc_hw2)

set(CMAKE_CXX_STANDARD 14)

add_executable(abc_hw2 main.cpp container.cpp rectangle.cpp circle.cpp shape.cpp triangle.cpp container.h rectangle.h triangle.h circle.h random.h shape.h)
