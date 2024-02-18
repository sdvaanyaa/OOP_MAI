cmake_minimum_required(VERSION 3.10)
project(gtest_lab3)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)

include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
add_executable(pointTest main.cpp pointTest.cpp ../src/point.cpp)
target_link_libraries(pointTest ${GTEST_LIBRARIES})

add_executable(squareTest main.cpp squareTest.cpp ../src/point.cpp ../src/square.cpp)
target_link_libraries(squareTest ${GTEST_LIBRARIES})

add_executable(trapezoidTest main.cpp trapezoidTest.cpp ../src/point.cpp ../src/trapezoid.cpp)
target_link_libraries(trapezoidTest ${GTEST_LIBRARIES})

add_executable(rectangleTest main.cpp rectangleTest.cpp ../src/point.cpp ../src/rectangle.cpp)
target_link_libraries(rectangleTest ${GTEST_LIBRARIES})

add_executable(testslab3  main.cpp squareTest.cpp trapezoidTest.cpp rectangleTest.cpp ../src/point.cpp ../src/square.cpp ../src/trapezoid.cpp ../src/rectangle.cpp ) 
target_link_libraries(testslab3 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests3)

