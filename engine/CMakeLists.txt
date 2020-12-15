project(trial2d-engine)

set(SOURCES
    sources/trial2d.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-vendor-defer.hpp
    PUBLIC trial2d-vendor-enum.hpp
    PUBLIC trial2d-vendor-flat.hpp
    PUBLIC trial2d-vendor-idgen.hpp
    PUBLIC trial2d-vendor-vmath.hpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
