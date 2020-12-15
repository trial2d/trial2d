project(trial2d-vendor-idgen.hpp)

add_subdirectory(idgen.hpp)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE idgen.hpp)
