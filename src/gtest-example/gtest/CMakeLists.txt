cmake_minimum_required(VERSION 3.5)

project(gtest-example)

add_library(math src/math.cpp)
include_directories(src)
add_executable(testmath test/mathtest.cpp)
target_link_libraries(testmath math gtest_main)