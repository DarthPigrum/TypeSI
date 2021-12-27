include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(internal internal.cpp)
target_link_libraries(internal gtest_main)
gtest_discover_tests(internal)

add_executable(base base.cpp)
target_link_libraries(base gtest_main)
gtest_discover_tests(base)

add_executable(derived derived.cpp)
target_link_libraries(derived gtest_main)
gtest_discover_tests(derived)

add_executable(math math.cpp)
target_link_libraries(math gtest_main)
gtest_discover_tests(math)

add_executable(prefix prefix.cpp)
target_link_libraries(prefix gtest_main)
gtest_discover_tests(prefix)

add_executable(special special.cpp)
target_link_libraries(special gtest_main)
gtest_discover_tests(special)

add_subdirectory(malformed)
