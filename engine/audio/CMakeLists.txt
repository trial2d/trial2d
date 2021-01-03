project(trial2d-engine-audio)

if(APPLE)
    set(SOURCES
        sources/miniaudio/impl/miniaudio_impl.mm
        sources/miniaudio/miniaudio_base.hpp
        sources/audio.cpp)
else()
    set(SOURCES
        sources/miniaudio/impl/miniaudio_impl.cpp
        sources/miniaudio/miniaudio_base.hpp
        sources/audio.cpp)
endif()

file(GLOB_RECURSE HEADERS headers/*.*)
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-engine)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-engine-core
    PUBLIC trial2d-engine-debug
    PUBLIC trial2d-engine-memory
    PUBLIC trial2d-vendor-miniaudio
    PUBLIC trial2d-vendor-stb)
