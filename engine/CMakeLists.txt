project(trial2d-engine)

#
# library
#

set(SOURCES
    sources/trial2d.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)

#
# modules
#

add_subdirectory(modules/defer.hpp)
add_subdirectory(modules/enum.hpp)
add_subdirectory(modules/vmath.hpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC defer.hpp
    PUBLIC enum.hpp
    PUBLIC vmath.hpp)
