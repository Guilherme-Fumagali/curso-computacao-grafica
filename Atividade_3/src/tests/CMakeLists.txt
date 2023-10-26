include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(static)

add_executable(tests
        ../Loader.h
        LoaderTest.cpp
)

target_link_libraries(tests GTest::gtest_main)
target_link_libraries(tests GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(tests)
