project(trial2d-vendor-enum.hpp)

add_subdirectory(enum.hpp)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE enum.hpp)
