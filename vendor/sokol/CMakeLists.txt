project(trial2d-vendor-sokol)

if(APPLE)
    set(SOURCES sources/sokol.mm)
else()
    set(SOURCES sources/sokol.cpp)
endif()

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
