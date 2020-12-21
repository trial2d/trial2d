project(trial2d-vendor-miniaudio)

if(APPLE)
    set(SOURCES sources/miniaudio.mm)
else()
    set(SOURCES sources/miniaudio.cpp)
endif()

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
