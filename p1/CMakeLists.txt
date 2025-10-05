cmake_minimum_required(VERSION 3.10)
project(p1)
add_executable(user-main user-main.cc user.cc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)