project(trial2d-vendor-defer.hpp)

add_subdirectory(defer.hpp)

file(GLOB_RECURSE HEADERS defer.hpp/headers/*.*)
add_library(${PROJECT_NAME} INTERFACE EXCLUDE_FROM_ALL ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-vendor)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/defer.hpp FILES ${HEADERS})

target_link_libraries(${PROJECT_NAME} INTERFACE defer.hpp)
