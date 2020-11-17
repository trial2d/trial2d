project(trial2d-inspector)

set(SOURCES
    sources/inspector.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-engine)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
