cmake_minimum_required(VERSION 3.26)
project(Atividade_2)

set(CMAKE_CXX_STANDARD 14)

include_directories("/src")
add_subdirectory("tests")

add_executable(Atividade_2
        "src/vec3.h"
        "src/vec2.h"
        "src/vec4.h"
        "src/mat2.h"
        "src/mat3.h"
        "src/mat4.h"
)

set_target_properties(Atividade_2 PROPERTIES LINKER_LANGUAGE CXX)