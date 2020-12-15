project(trial2d-vendor-sdl2)

add_library(${PROJECT_NAME} INTERFACE)

if(EMSCRIPTEN)
    target_link_options(${PROJECT_NAME} INTERFACE "-s USE_SDL=2")
else()
    find_package(SDL2 REQUIRED)
    target_link_libraries(${PROJECT_NAME} INTERFACE SDL2::SDL2)
endif()
