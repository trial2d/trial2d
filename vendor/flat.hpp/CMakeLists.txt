project(trial2d-vendor-flat.hpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_library(${PROJECT_NAME} INTERFACE EXCLUDE_FROM_ALL ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-vendor)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADERS})

target_compile_features(${PROJECT_NAME}
    INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME}
    INTERFACE headers)
