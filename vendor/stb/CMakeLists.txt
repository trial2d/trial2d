project(trial2d-vendor-stb)

set(SOURCES
    sources/stb.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC headers)
