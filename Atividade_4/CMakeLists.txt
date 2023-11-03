cmake_minimum_required(VERSION 3.26)
project(Atividade_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../Atividade_2/src)
include_directories(../Atividade_2/src/vec_lib)
include_directories(../Atividade_2/src/mat_lib)
include_directories(../Atividade_3/src)

include_directories(.)
include_directories(./src)

add_executable(sphere
    src/ray.h
    src/sphere.cpp
)

add_executable(triangle
    src/ray.h
    src/triangle.cpp
)

add_executable(render
    src/obj_render.cpp
)