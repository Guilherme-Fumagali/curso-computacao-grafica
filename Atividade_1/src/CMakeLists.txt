find_program(MAGICK_CONFIG "Magick++-config")
execute_process(COMMAND "${MAGICK_CONFIG}" "--cxxflags" OUTPUT_VARIABLE MAGICK_CXX_FLAGS)
execute_process(COMMAND "${MAGICK_CONFIG}" "--libs" OUTPUT_VARIABLE MAGICK_LD_FLAGS)
string(STRIP "${MAGICK_CXX_FLAGS}" MAGICK_CXX_FLAGS)
string(STRIP "${MAGICK_LD_FLAGS}" MAGICK_LD_FLAGS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${MAGICK_CXX_FLAGS} ${MAGICK_LD_FLAGS}")

add_library(MatrixIOImage MatrixIOImage.cpp)

add_executable(main
    MatrixIOImage.hpp
    main.cpp
)

target_link_libraries(main MatrixIOImage)

add_subdirectory(utils)