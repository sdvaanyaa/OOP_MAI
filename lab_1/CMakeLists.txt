cmake_minimum_required(VERSION 3.10)
project(lab1)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

file(GLOB SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab1_lib ${SOURCES})
add_executable(lab1_exe ${SOURCE_DIR}/main.cpp)
add_executable(lab1_tests_exe ${TESTS_DIR}/tests.cpp )

target_link_libraries(lab1_exe PRIVATE lab1_lib)
target_link_libraries(lab1_tests_exe PRIVATE lab1_lib ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(lab1_tests lab1_tests_exe)