cmake_minimum_required(VERSION 3.26)
project(Atividade_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../Atividade_2/src/vec_lib)

add_executable(main
        src/Loader.h
        src/main.cpp)
