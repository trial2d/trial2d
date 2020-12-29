project(trial2d-application)

file(GLOB_RECURSE SOURCES sources/*.*)
file(GLOB_RECURSE HEADERS headers/*.*)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-addons)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-core
    PUBLIC trial2d-debug
    PUBLIC trial2d-memory
    PUBLIC trial2d-vendor-sokol
    PUBLIC trial2d-vendor-native)
