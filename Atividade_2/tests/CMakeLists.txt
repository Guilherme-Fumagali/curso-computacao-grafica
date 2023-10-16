project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run Vec_lib/Vec2Test.cpp
        Vec_lib/Vec3Test.cpp
        Vec_lib/Vec3Test.cpp
        Vec_lib/Vec4Test.cpp
        Mat_lib/mat2Test.cpp)

# linking Google_Tests_run with Vec_lib which will be tested
target_link_libraries(Google_Tests_run vec_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)