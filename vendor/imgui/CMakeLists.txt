project(trial2d-vendor-imgui)

set(SOURCES
    sources/imgui_demo.cpp
    sources/imgui_draw.cpp
    sources/imgui_stdlib.cpp
    sources/imgui_tables.cpp
    sources/imgui_widgets.cpp
    sources/imgui.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers
    PRIVATE headers/imgui)
