project(trial2d-vendor-native)

add_library(${PROJECT_NAME} INTERFACE)

if(CMAKE_SYSTEM_NAME MATCHES "Android")
    target_link_libraries(${PROJECT_NAME} INTERFACE
        android
        EGL
        GLESv3
        log
        m)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} INTERFACE
        "-framework AudioToolbox"
        "-framework Cocoa"
        "-framework CoreAudio"
        "-framework Metal"
        "-framework MetalKit"
        "-framework QuartzCore")
endif()

if(CMAKE_SYSTEM_NAME MATCHES "iOS")
    target_link_libraries(${PROJECT_NAME} INTERFACE
        "-framework AudioToolbox"
        "-framework AVFoundation"
        "-framework Foundation"
        "-framework Metal"
        "-framework MetalKit"
        "-framework UIKit")
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(${PROJECT_NAME} INTERFACE
        dl
        GL
        m
        X11
        Xcursor
        Xi)
endif()
