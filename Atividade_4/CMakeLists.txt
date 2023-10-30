cmake_minimum_required(VERSION 3.26)
project(Atividade_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../Atividade_2/src)
include_directories(../Atividade_2/src/vec_lib)
include_directories(../Atividade_2/src/mat_lib)

include_directories(.)
include_directories(./src)

add_executable(main
    src/ray.h
        src/sphere.cpp
)

set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)