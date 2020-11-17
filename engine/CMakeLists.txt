project(trial2d-engine)

set(SOURCES
    sources/trial2d.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
