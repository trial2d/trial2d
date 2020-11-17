cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

if(NOT DEFINED PROJECT_NAME)
    set(T2D_STANDALONE_BUILD ON)
endif()

option(T2D_BUILD_EDITOR "Build trial2d editor" ON)
option(T2D_BUILD_SAMPLE "Build trial2d sample" ${T2D_STANDALONE_BUILD})
option(T2D_BUILD_UTESTS "Build trial2d utests" ${T2D_STANDALONE_BUILD})

project(trial2d)

add_subdirectory(addons)
add_subdirectory(engine)

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
