cmake_minimum_required(VERSION 3.17)
project(TypeSI)

set(CMAKE_CXX_STANDARD 11)

add_executable(internal.out test/internal.cpp)
add_executable(base.out test/base.cpp)

enable_testing()
add_test(NAME CoreLogicTest COMMAND internal.out)
add_test(NAME BaseUnitsTest COMMAND base.out)
