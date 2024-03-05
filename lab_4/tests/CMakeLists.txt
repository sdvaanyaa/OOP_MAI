cmake_minimum_required(VERSION 3.10)
project(gtest_lab4)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)

include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
add_executable(TemplatePointTest main.cpp pointTest.cpp)
target_link_libraries(TemplatePointTest ${GTEST_LIBRARIES})

add_executable(TemplateSquareTest main.cpp squareTest.cpp)
target_link_libraries(TemplateSquareTest ${GTEST_LIBRARIES})

add_executable(TemplateTrapezoidTest main.cpp trapezoidTest.cpp)
target_link_libraries(TemplateTrapezoidTest ${GTEST_LIBRARIES})

add_executable(TemplateRectangleTest main.cpp rectangleTest.cpp)
target_link_libraries(TemplateRectangleTest ${GTEST_LIBRARIES})

add_executable(testslab4  main.cpp pointTest.cpp squareTest.cpp trapezoidTest.cpp rectangleTest.cpp) 
target_link_libraries(testslab4 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests4)

