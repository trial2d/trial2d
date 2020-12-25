project(trial2d-sample-editor)

file(GLOB_RECURSE SOURCES sources/*.*)
file(GLOB_RECURSE HEADERS headers/*.*)

include("t2d_add_executable")
t2d_add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}
    BUNDLE_IDENTIFIER "me.matov.trial2d-sample-editor"
    TEMPLATES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/support)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER trial2d-sample)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    trial2d-editor
    trial2d-sample-common)
