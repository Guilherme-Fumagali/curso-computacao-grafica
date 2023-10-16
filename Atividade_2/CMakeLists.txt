cmake_minimum_required(VERSION 3.26)
project(Atividade_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(Vec_lib)
add_subdirectory(Vec_lib)

include_directories(Mat_lib)
add_subdirectory(Mat_lib)

add_subdirectory(tests)

add_executable(Atividade_2
        "Vec_lib/vec3.h"
        "Vec_lib/vec2.h"
        "Vec_lib/vec4.h"
        "Mat_lib/mat2.h"
        "Mat_lib/mat3.h"
        "Mat_lib/mat4.h"
        color.h
        main.cpp
)

set_target_properties(Atividade_2 PROPERTIES LINKER_LANGUAGE CXX)