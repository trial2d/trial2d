project(trial2d-engine)

set(SOURCES
    sources/trial2d.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-vendor-boost.di
    PUBLIC trial2d-vendor-defer.hpp
    PUBLIC trial2d-vendor-enum.hpp
    PUBLIC trial2d-vendor-flat.hpp
    PUBLIC trial2d-vendor-idgen.hpp
    PUBLIC trial2d-vendor-vmath.hpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
