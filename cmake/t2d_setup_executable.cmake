function(T2D_SETUP_EXECUTABLE TARGET)
    cmake_parse_arguments(
        PARSE_ARGV
        1
        ARG
        ""
        "TEMPLATES_DIR;BUNDLE_IDENTIFIER"
        "")

    if(NOT ARG_TEMPLATES_DIR)
        message(FATAL_ERROR "Missing argument: TEMPLATES_DIR, TARGET: ${TARGET}")
    endif()

    if(NOT ARG_BUNDLE_IDENTIFIER)
        message(FATAL_ERROR "Missing argument: BUNDLE_IDENTIFIER, TARGET: ${TARGET}")
    endif()

    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        set_target_properties(${TARGET} PROPERTIES
            MACOSX_BUNDLE ON
            POSITION_INDEPENDENT_CODE ON
            MACOSX_BUNDLE_GUI_IDENTIFIER ${ARG_BUNDLE_IDENTIFIER}
            MACOSX_BUNDLE_INFO_PLIST ${ARG_TEMPLATES_DIR}/cocoa.plist
            XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER ${ARG_BUNDLE_IDENTIFIER})
    endif()

    if(CMAKE_SYSTEM_NAME MATCHES "iOS")
        set_target_properties(${TARGET} PROPERTIES
            MACOSX_BUNDLE ON
            POSITION_INDEPENDENT_CODE ON
            MACOSX_BUNDLE_GUI_IDENTIFIER ${ARG_BUNDLE_IDENTIFIER}
            MACOSX_BUNDLE_INFO_PLIST ${ARG_TEMPLATES_DIR}/ios.plist
            XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER ${ARG_BUNDLE_IDENTIFIER})
    endif()

    if(CMAKE_SYSTEM_NAME MATCHES "Emscripten")
        set_target_properties(${TARGET} PROPERTIES
            SUFFIX ".html")
        target_link_options(${TARGET}
            PRIVATE --shell-file ${ARG_TEMPLATES_DIR}/wasm.html)
    endif()

    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        set_target_properties(${TARGET} PROPERTIES
            WIN32_EXECUTABLE ON)
    endif()
endfunction()
