cmake_minimum_required(VERSION 3.5)

project(gmock-example)

add_library(mobile src/Camera.cpp src/Mobile.cpp)

add_executable(testmobile test/MobileTest.cpp)
include_directories(src)
target_link_libraries(testmobile mobile gtest_main gmock)