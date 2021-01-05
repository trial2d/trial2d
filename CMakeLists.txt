cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(NOT DEFINED PROJECT_NAME)
    set(T2D_STANDALONE ON)
endif()

project(trial2d)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include("t2d_executable")
include("t2d_platform")

add_subdirectory(engine)
add_subdirectory(vendor)

if(T2D_DESKTOP)
    add_subdirectory(editor)
endif()

if(T2D_STANDALONE)
    add_subdirectory(sample)
endif()

if(T2D_DESKTOP AND T2D_STANDALONE)
    enable_testing()
    add_subdirectory(utests)
endif()
