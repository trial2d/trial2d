project(trial2d-vendor-opengl)

add_library(${PROJECT_NAME} INTERFACE)

if(EMSCRIPTEN)
    target_link_options(${PROJECT_NAME} INTERFACE "-s MIN_WEBGL_VERSION=1 -s MAX_WEBGL_VERSION=2")
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} INTERFACE OpenGL::GL)

    if(APPLE)
        target_compile_definitions(${PROJECT_NAME} INTERFACE GL_SILENCE_DEPRECATION)
    endif()
endif()
