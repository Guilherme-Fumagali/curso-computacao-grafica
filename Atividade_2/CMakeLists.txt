cmake_minimum_required(VERSION 3.26)
project(Atividade_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(vec_lib)
add_subdirectory(vec_lib)

include_directories(mat_lib)
add_subdirectory(mat_lib)

add_subdirectory(tests)

add_executable(main
        "vec_lib/vec3.h"
        "vec_lib/vec2.h"
        "vec_lib/vec4.h"
        "mat_lib/mat2.h"
        "mat_lib/mat3.h"
        "mat_lib/mat4.h"
        color.h
        main.cpp
)

set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)