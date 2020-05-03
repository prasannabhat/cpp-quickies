cmake_minimum_required(VERSION 3.5)
project(c++17)

# set(CMAKE_CXX_COMPILER "g++")
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(CXX_WARNING_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX17_FLAGS   "-std=c++17")
set(CMAKE_CXX_FLAGS  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX17_FLAGS} ${GCC_WARNING_FLAGS})

message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message("CXX compiler : ${CMAKE_CXX_COMPILER}")

add_subdirectory(ext/googletest)

add_subdirectory(src/gtest-example/gtest)
add_subdirectory(src/gtest-example/gmock)
add_subdirectory(src/threads)

add_executable(nest-namespace src/c++17/nested-namespace.cpp)
add_executable(init-list src/advanced/init-list.cpp)
add_executable(hello-world src/hello-world.cpp)


add_executable(constructor src/constructor/constructor.cpp src/constructor/construction-order.hpp)
set(TARGET_CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-Xlinker -Map=constructor.map")
set_target_properties(constructor PROPERTIES CMAKE_EXE_LINKER_FLAGS ${TARGET_CMAKE_EXE_LINKER_FLAGS})
# target_link_options(constructor ${TARGET_CMAKE_EXE_LINKER_FLAGS})

# for verbose option in make use make VERBOSE=1
