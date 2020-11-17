project(trial2d-sample)

set(SOURCES
    sources/sample.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    trial2d-addons
    trial2d-engine)
