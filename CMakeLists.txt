cmake_minimum_required(VERSION 3.5)
project(c++17)

include(cmake/project-config.cmake)


add_subdirectory(ext/googletest)

add_subdirectory(src/gtest-example/gtest)
add_subdirectory(src/gtest-example/gmock/swami)
add_subdirectory(src/gtest-example/gmock/turtles)

add_subdirectory(src/threads)
add_subdirectory(src/memory-management)

add_executable(nest-namespace src/c++17/nested-namespace.cpp)
add_executable(init-list src/advanced/init-list.cpp)
add_executable(hello-world src/hello-world.cpp)

add_executable(constructor src/constructor/constructor.cpp src/constructor/construction-order.hpp)
set(TARGET_CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-Xlinker -Map=constructor.map")
set_target_properties(constructor PROPERTIES CMAKE_EXE_LINKER_FLAGS ${TARGET_CMAKE_EXE_LINKER_FLAGS})
# target_link_options(constructor ${TARGET_CMAKE_EXE_LINKER_FLAGS})

# for verbose option in make use make VERBOSE=1
