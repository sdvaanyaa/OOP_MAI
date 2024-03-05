cmake_minimum_required(VERSION 3.10)
project(gtest_lab5)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)

include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(testslab5  main.cpp) 
target_link_libraries(testslab5 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests5)

