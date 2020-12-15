project(trial2d-vendor-glew)

set(glew-cmake_BUILD_STATIC ON CACHE INTERNAL "" FORCE)
set(glew-cmake_BUILD_SHARED OFF CACHE INTERNAL "" FORCE)

add_subdirectory(glew)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE libglew_static)
