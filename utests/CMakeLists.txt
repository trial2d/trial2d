project(trial2d-utests)

set(SOURCES
    sources/utests.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    trial2d-addons
    trial2d-engine)

target_include_directories(${PROJECT_NAME}
    PRIVATE modules)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
