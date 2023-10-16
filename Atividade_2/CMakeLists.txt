cmake_minimum_required(VERSION 3.26)
project(Atividade_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/vec_lib)
add_subdirectory(src/vec_lib)

include_directories(src/mat_lib)
add_subdirectory(src/mat_lib)

add_subdirectory(tests)

add_executable(main
        "src/vec_lib/vec3.h"
        "src/vec_lib/vec2.h"
        "src/vec_lib/vec4.h"
        "src/mat_lib/mat2.h"
        "src/mat_lib/mat3.h"
        "src/mat_lib/mat4.h"
        src/color.h
        src/main.cpp
)

set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)