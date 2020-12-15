project(trial2d-vendor-glfw3)

add_library(${PROJECT_NAME} INTERFACE)

if(EMSCRIPTEN)
    target_link_options(${PROJECT_NAME} INTERFACE "-s USE_GLFW=3")
else()
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} INTERFACE glfw)
endif()
