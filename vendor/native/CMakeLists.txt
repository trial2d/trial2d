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

if(CMAKE_SYSTEM_NAME MATCHES "Emscripten")
    target_link_options(${PROJECT_NAME} INTERFACE
        -sABORTING_MALLOC=0
        -sALLOW_MEMORY_GROWTH=1
        -sDISABLE_EXCEPTION_CATCHING=0
        -sFILESYSTEM=0
        -sMALLOC=emmalloc
        -sMAX_WEBGL_VERSION=1
        -sMIN_WEBGL_VERSION=1
        -sWASM=1
        $<$<NOT:$<CONFIG:Debug>>:
            -flto
            -sASSERTIONS=0
            -sUSE_CLOSURE_COMPILER=1>)
endif()
