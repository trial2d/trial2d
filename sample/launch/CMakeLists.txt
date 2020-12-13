project(trial2d-sample-launch)

set(SOURCES
    sources/launch.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    trial2d-sample-common)
