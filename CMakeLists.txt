# 3.8 version is required for `cxx_std_17`
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

if(NOT DEFINED PROJECT_NAME)
    set(T2D_STANDALONE ON)
endif()

project(trial2d)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include("t2d_platform")

add_subdirectory(editor)
add_subdirectory(engine)
add_subdirectory(vendor)

if(T2D_STANDALONE)
    add_subdirectory(sample)
endif()

if(T2D_STANDALONE AND T2D_DESKTOP)
    enable_testing()
    add_subdirectory(utests)
endif()
