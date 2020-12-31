project(trial2d-vendor-imgui)

set(SOURCES
    sources/imgui_demo.cpp
    sources/imgui_draw.cpp
    sources/imgui_stdlib.cpp
    sources/imgui_tables.cpp
    sources/imgui_widgets.cpp
    sources/imgui.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_library(${PROJECT_NAME} OBJECT EXCLUDE_FROM_ALL ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-vendor)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers
    PRIVATE headers/imgui)
