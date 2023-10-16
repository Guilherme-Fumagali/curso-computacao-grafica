project(vec)

set(HEADER_FILES
        vec2.h
        vec3.h
        vec4.h)

add_library(vec_lib STATIC ${HEADER_FILES})
set_target_properties(vec_lib PROPERTIES LINKER_LANGUAGE CXX)
