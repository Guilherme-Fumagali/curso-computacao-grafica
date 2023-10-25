cmake_minimum_required(VERSION 3.26)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
        triangleTest.cpp
        LoaderTest.cpp
)

target_link_libraries(tests GTest::gtest_main)
