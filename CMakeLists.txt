cmake_minimum_required(VERSION 3.17)
project(TypeSI)

set(CMAKE_CXX_STANDARD 11)

add_executable(internal.out test/internal.cpp)
add_executable(base.out test/base.cpp)
add_executable(derived.out test/derived.cpp)
add_executable(math.out test/math.cpp)
add_executable(prefix.out test/prefix.cpp)

enable_testing()
add_test(NAME CoreLogicTest COMMAND internal.out)
add_test(NAME BaseUnitsTest COMMAND base.out)
add_test(NAME DerivedUnitsTest COMMAND derived.out)
add_test(NAME MathFunctionsTest COMMAND math.out)
add_test(NAME PrefixTest COMMAND prefix.out)
