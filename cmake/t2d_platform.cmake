if(CMAKE_SYSTEM_NAME MATCHES "Android")
    set(T2D_MOBILE ON)
    set(T2D_ANDROID ON)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(T2D_DESKTOP ON)
    set(T2D_DARWIN ON)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Emscripten")
    set(T2D_WEB ON)
    set(T2D_EMSCRIPTEN ON)

    if(NOT T2D_EMSCRIPTEN_ASMJS AND NOT T2D_EMSCRIPTEN_WASM)
        set(T2D_EMSCRIPTEN_WASM ON)
    endif()
endif()

if(CMAKE_SYSTEM_NAME MATCHES "iOS")
    set(T2D_MOBILE ON)
    set(T2D_IOS ON)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(T2D_DESKTOP ON)
    set(T2D_LINUX ON)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(T2D_DESKTOP ON)
    set(T2D_WINDOWS ON)
endif()
