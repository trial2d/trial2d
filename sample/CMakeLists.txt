project(trial2d-sample)

add_subdirectory(common)
add_subdirectory(launch)

if(T2D_DESKTOP)
    add_subdirectory(editor)
endif()
