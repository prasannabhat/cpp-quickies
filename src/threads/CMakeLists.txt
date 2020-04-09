add_executable(pthreads pthreads.cpp)
target_link_libraries(pthreads pthread)

add_executable(std-threads std-threads-wrapper.cpp)
target_link_libraries(std-threads pthread)

add_executable(account account.cpp)
target_link_libraries(account pthread)