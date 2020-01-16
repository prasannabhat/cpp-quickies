cmake_minimum_required(VERSION 3.5)

project(gtest-example)

add_library(math gtest/src/math.cpp)
include_directories(gtest/src)
add_executable(testmath gtest/test/mathtest.cpp)
target_link_libraries(testmath math gtest_main)