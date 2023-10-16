project(vec)

set(HEADER_FILES
        vec2.h
        vec3.h
        vec4.h)

add_library(vec_headers STATIC ${HEADER_FILES})
set_target_properties(vec_headers PROPERTIES LINKER_LANGUAGE CXX)
