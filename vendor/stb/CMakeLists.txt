project(trial2d-vendor-stb)

set(SOURCES
    sources/stb.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
