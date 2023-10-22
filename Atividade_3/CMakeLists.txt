cmake_minimum_required(VERSION 3.26)
project(Atividade_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../Atividade_2/src/vec_lib)
add_subdirectory(../Atividade_2/src/vec_lib vec_lib)

add_executable(obj_loader
        "../Atividade_2/src/vec_lib/vec2.h"
        "../Atividade_2/src/vec_lib/vec3.h"
        objLoader.cpp)

target_link_libraries(obj_loader vec_lib)