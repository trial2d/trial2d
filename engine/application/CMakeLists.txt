project(trial2d-engine-application)

if(APPLE)
    set(SOURCES
        sources/sokol/impl/sokol_impl.mm
        sources/sokol/sokol_base.hpp
        sources/sokol/sokol_main.cpp
        sources/application.cpp)
else()
    set(SOURCES
        sources/sokol/impl/sokol_impl.cpp
        sources/sokol/sokol_base.hpp
        sources/sokol/sokol_main.cpp
        sources/application.cpp)
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
    PUBLIC trial2d-vendor-sokol
    PUBLIC trial2d-vendor-native)
