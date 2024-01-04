cmake_minimum_required(VERSION 3.26)
project(Atividade_6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(MAGICK_CONFIG "Magick++-config")
execute_process(COMMAND "${MAGICK_CONFIG}" "--cxxflags" OUTPUT_VARIABLE MAGICK_CXX_FLAGS)
execute_process(COMMAND "${MAGICK_CONFIG}" "--libs" OUTPUT_VARIABLE MAGICK_LD_FLAGS)
string(STRIP "${MAGICK_CXX_FLAGS}" MAGICK_CXX_FLAGS)
string(STRIP "${MAGICK_LD_FLAGS}" MAGICK_LD_FLAGS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${MAGICK_CXX_FLAGS} ${MAGICK_LD_FLAGS}")

include_directories(../Atividade_1/src)
include_directories(../Atividade_2/src)
include_directories(../Atividade_2/src/vec_lib)
include_directories(../Atividade_2/src/mat_lib)
include_directories(../Atividade_3/src)

include_directories(.)
include_directories(./src)

add_library(MatrixIOImage ../Atividade_1/src/MatrixIOImage.cpp)

add_executable(material_spheres
        src/headers/material.h
        src/headers/hittable/HittableList.h
        src/headers/hittable/HittableSphere.h
        src/headers/camera/view_direction_camera.h
        src/utils/utils.h
        src/material_spheres.cpp
)
target_link_libraries(material_spheres MatrixIOImage)

add_executable(dieletrics_spheres
        src/headers/material.h
        src/headers/hittable/HittableList.h
        src/headers/hittable/HittableSphere.h
        src/headers/camera/view_direction_camera.h
        src/utils/utils.h
        src/dieletrics_spheres.cpp
)
target_link_libraries(dieletrics_spheres MatrixIOImage)