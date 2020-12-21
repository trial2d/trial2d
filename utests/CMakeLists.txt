project(trial2d-utests)

set(SOURCES
    sources/utests.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

include("t2d_setup_executable")
t2d_setup_executable(${PROJECT_NAME}
    BUNDLE_IDENTIFIER "me.matov.trial2d-untests"
    TEMPLATES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/support)

target_link_libraries(${PROJECT_NAME}
    PRIVATE trial2d-addons
    PRIVATE trial2d-editor
    PRIVATE trial2d-engine
    PRIVATE trial2d-vendor-doctest)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
