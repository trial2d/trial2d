project(trial2d-sample-editor)

set(SOURCES
    sources/editor.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    trial2d-editor
    trial2d-sample-common)
