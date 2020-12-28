project(trial2d-core)

set(SOURCES
    sources/core.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-addons)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-vendor-boost.di
    PUBLIC trial2d-vendor-defer.hpp
    PUBLIC trial2d-vendor-enum.hpp
    PUBLIC trial2d-vendor-flat.hpp
    PUBLIC trial2d-vendor-idgen.hpp
    PUBLIC trial2d-vendor-vmath.hpp)
