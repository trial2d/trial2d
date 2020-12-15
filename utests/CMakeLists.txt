project(trial2d-utests)

set(SOURCES
    sources/utests.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE trial2d-addons
    PRIVATE trial2d-editor
    PRIVATE trial2d-engine
    PRIVATE trial2d-vendor-doctest)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
