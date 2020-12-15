project(trial2d-vendor-vmath.hpp)

add_subdirectory(vmath.hpp)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE vmath.hpp)
