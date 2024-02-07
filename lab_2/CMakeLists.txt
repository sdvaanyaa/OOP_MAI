cmake_minimum_required(VERSION 3.10)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tests)

add_executable(laba2 src/main.cpp src/HexArray.cpp)