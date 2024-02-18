cmake_minimum_required(VERSION 3.10)
project(gtest_lab1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


enable_testing()
add_executable(testslab2 test.cpp ../src/HexArray.cpp) 
target_link_libraries(testslab2 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests1)

