project(trial2d-sample-launch)

set(SOURCES
    sources/launch.cpp)

file(GLOB_RECURSE HEADERS headers/*.*)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-sample)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

include("t2d_setup_executable")
t2d_setup_executable(${PROJECT_NAME}
    BUNDLE_IDENTIFIER "me.matov.trial2d-sample-launch"
    TEMPLATES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/support)

target_link_libraries(${PROJECT_NAME}
    trial2d-sample-common)
