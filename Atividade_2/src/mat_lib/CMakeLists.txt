project(mat)

set(HEADER_FILES
        mat2.h
        mat3.h
        mat4.h)

add_library(mat_headers STATIC ${HEADER_FILES})
set_target_properties(mat_headers PROPERTIES LINKER_LANGUAGE CXX)