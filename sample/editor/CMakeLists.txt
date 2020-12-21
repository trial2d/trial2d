project(trial2d-sample-editor)

set(SOURCES
    sources/editor.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-sample)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    trial2d-editor
    trial2d-sample-common)
