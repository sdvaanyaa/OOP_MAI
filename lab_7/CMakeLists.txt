cmake_minimum_required(VERSION 3.10)
project(Lab7)

find_package(GTest REQUIRED)

add_compile_options(-Wall -Werror)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

file(GLOB SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

# add_library(Lab7_lib ${SOURCES})
add_executable(Lab7_exe ${SOURCE_DIR}/main.cpp ${SOURCES})
# add_executable(Lab7_tests_exe ${TESTS_DIR}/tests.cpp )

# target_link_libraries(Lab7_exe SHARED Lab7_lib)
# target_link_libraries(Lab7_tests_exe PRIVATE Lab7_lib ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# enable_testing()
# add_test(Lab7_tests Lab7_tests_exe)