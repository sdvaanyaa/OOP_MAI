cmake_minimum_required(VERSION 3.10)
project(lab_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tests)

add_executable(lab3 src/main.cpp src/trapezoid.cpp src/point.cpp src/square.cpp src/rectangle.cpp)