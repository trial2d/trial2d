project(trial2d-physics)

set(SOURCES
    sources/physics.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-engine)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
