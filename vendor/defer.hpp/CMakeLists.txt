project(trial2d-vendor-defer.hpp)

add_subdirectory(defer.hpp)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE defer.hpp)
