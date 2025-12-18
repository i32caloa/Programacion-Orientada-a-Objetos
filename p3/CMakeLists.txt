cmake_minimum_required(VERSION 3.10)
project(p3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
enable_testing()

add_subdirectory(tests)
add_subdirectory(src)
