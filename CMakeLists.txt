cmake_minimum_required(VERSION 3.17)
project(TypeSI)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

enable_testing()
add_subdirectory(test)
