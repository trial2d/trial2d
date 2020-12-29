project(trial2d-engine)

file(GLOB_RECURSE SOURCES sources/*.*)
file(GLOB_RECURSE HEADERS headers/*.*)
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC trial2d-core)

target_include_directories(${PROJECT_NAME}
    PUBLIC headers)
