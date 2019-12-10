cmake_minimum_required(VERSION 3.5)

# set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX17_FLAGS   "-std=c++17")
set(CMAKE_CXX_FLAGS  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX17_FLAGS})
message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")

project(c++17)

add_executable(nest-namespace src/c++17/nested-namespace.cpp)
add_executable(hello-world src/hello-world.cpp)

# for verbose option in make use make VERBOSE=1