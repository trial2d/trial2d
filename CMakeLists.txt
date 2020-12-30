#target_link_options: 3.13
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT DEFINED PROJECT_NAME)
    set(T2D_STANDALONE_BUILD ON)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(trial2d)

option(T2D_BUILD_EDITOR "Build trial2d editor" ON)
option(T2D_BUILD_SAMPLE "Build trial2d sample" ${T2D_STANDALONE_BUILD})
option(T2D_BUILD_UTESTS "Build trial2d utests" ${T2D_STANDALONE_BUILD})

add_subdirectory(engine)
add_subdirectory(vendor)

if(T2D_BUILD_EDITOR)
    add_subdirectory(editor)
endif()

if(T2D_BUILD_SAMPLE)
    add_subdirectory(sample)
endif()

if(T2D_BUILD_UTESTS)
    enable_testing()
    add_subdirectory(utests)
endif()
