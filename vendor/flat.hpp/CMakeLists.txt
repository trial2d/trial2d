project(trial2d-vendor-flat.hpp)

add_subdirectory(flat.hpp)

file(GLOB_RECURSE HEADERS flat.hpp/headers/*.*)
add_library(${PROJECT_NAME} INTERFACE EXCLUDE_FROM_ALL ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-vendor)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/flat.hpp FILES ${HEADERS})

target_link_libraries(${PROJECT_NAME} INTERFACE flat.hpp)
