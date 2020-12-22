project(trial2d-addons)

option(T2D_ENABLE_APPLICATION_ADDON "Enable trial2d application addon" ON)
option(T2D_ENABLE_AUDIO_ADDON "Enable trial2d audio addon" ON)
option(T2D_ENABLE_DEBUG_ADDON "Enable trial2d debug addon" ON)
option(T2D_ENABLE_INSPECTOR_ADDON "Enable trial2d inspector addon" ON)
option(T2D_ENABLE_PARTICLES_ADDON "Enable trial2d particles addon" ON)
option(T2D_ENABLE_PHYSICS_ADDON "Enable trial2d physics addon" ON)
option(T2D_ENABLE_WIDGETS_ADDON "Enable trial2d widgets addon" ON)

add_library(${PROJECT_NAME} INTERFACE)

if(T2D_ENABLE_APPLICATION_ADDON)
    add_subdirectory(trial2d-application)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-application)
endif()

if(T2D_ENABLE_AUDIO_ADDON)
    add_subdirectory(trial2d-audio)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-audio)
endif()

if(T2D_ENABLE_DEBUG_ADDON)
    add_subdirectory(trial2d-debug)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-debug)
endif()

if(T2D_ENABLE_INSPECTOR_ADDON)
    add_subdirectory(trial2d-inspector)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-inspector)
endif()

if(T2D_ENABLE_PARTICLES_ADDON)
    add_subdirectory(trial2d-particles)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-particles)
endif()

if(T2D_ENABLE_PHYSICS_ADDON)
    add_subdirectory(trial2d-physics)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-physics)
endif()

if(T2D_ENABLE_WIDGETS_ADDON)
    add_subdirectory(trial2d-widgets)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-widgets)
endif()
