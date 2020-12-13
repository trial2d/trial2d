project(trial2d-application)

set(SOURCES
    sources/application.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-engine)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
