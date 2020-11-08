cmake_minimum_required(VERSION 3.17)
project(TypeSI)

set(CMAKE_CXX_STANDARD 11)

add_executable(generalTest.out test/general.cpp)

enable_testing()
add_test(NAME generalTest COMMAND generalTest.out)
