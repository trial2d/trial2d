project(trial2d-utests)

set(SOURCES
    sources/utests.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    PRIVATE trial2d-vendor-doctest)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
