project(trial2d-vendor-flat.hpp)

add_subdirectory(flat.hpp)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE flat.hpp)
