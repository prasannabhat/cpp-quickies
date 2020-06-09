cmake_minimum_required(VERSION 3.5)

project(gmock-turtle)

add_executable(gmock-turtle tests/turtle-test.cpp)
include_directories(turtle)
include_directories(mocks)
target_link_libraries(gmock-turtle gtest_main gmock)