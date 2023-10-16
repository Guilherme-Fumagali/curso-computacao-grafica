project(mat)

set(HEADER_FILES
        mat2.h
        mat3.h
        mat4.h)

add_library(mat_lib STATIC ${HEADER_FILES})
set_target_properties(mat_lib PROPERTIES LINKER_LANGUAGE CXX)