project(trial2d-editor)

set(SOURCES
    sources/editor.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    trial2d-addons
    trial2d-engine)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
