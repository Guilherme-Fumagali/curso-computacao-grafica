include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# adding the Google_Tests_run target
add_executable(tests
        vec_lib/vec2Test.cpp
        vec_lib/vec3Test.cpp
        vec_lib/vec4Test.cpp
        mat_lib/mat2Test.cpp
        mat_lib/mat3Test.cpp
        mat_lib/mat4Test.cpp)

target_link_libraries(tests GTest::gtest_main)
target_link_libraries(tests vec_headers)
target_link_libraries(tests mat_headers)

include(GoogleTest)
gtest_discover_tests(tests)


