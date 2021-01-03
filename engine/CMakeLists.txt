project(trial2d-engine)

option(T2D_ENABLE_AUDIO_MODULE "Enable trial2d audio module" ON)
option(T2D_ENABLE_CORE_MODULE "Enable trial2d core module" ON)
option(T2D_ENABLE_DEBUG_MODULE "Enable trial2d debug module" ON)
option(T2D_ENABLE_IMAGE_MODULE "Enable trial2d image module" ON)
option(T2D_ENABLE_INPUT_MODULE "Enable trial2d input module" ON)
option(T2D_ENABLE_MEMORY_MODULE "Enable trial2d memory module" ON)
option(T2D_ENABLE_STARTER_MODULE "Enable trial2d starter module" ON)
option(T2D_ENABLE_STORAGE_MODULE "Enable trial2d storage module" ON)

add_library(${PROJECT_NAME} INTERFACE)

if(T2D_ENABLE_AUDIO_MODULE)
    add_subdirectory(audio)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-audio)
endif()

if(T2D_ENABLE_CORE_MODULE)
    add_subdirectory(core)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-core)
endif()

if(T2D_ENABLE_DEBUG_MODULE)
    add_subdirectory(debug)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-debug)
endif()

if(T2D_ENABLE_IMAGE_MODULE)
    add_subdirectory(image)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-image)
endif()

if(T2D_ENABLE_INPUT_MODULE)
    add_subdirectory(input)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-input)
endif()

if(T2D_ENABLE_MEMORY_MODULE)
    add_subdirectory(memory)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-memory)
endif()

if(T2D_ENABLE_STARTER_MODULE)
    add_subdirectory(starter)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-starter)
endif()

if(T2D_ENABLE_STORAGE_MODULE)
    add_subdirectory(storage)
    target_link_libraries(${PROJECT_NAME} INTERFACE trial2d-engine-storage)
endif()
