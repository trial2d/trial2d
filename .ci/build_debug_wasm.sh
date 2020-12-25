#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/debug_wasm
pushd $BUILD_DIR/debug_wasm
cmake ../.. -DCMAKE_BUILD_TYPE=Debug\
    -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN_ROOT/libexec/cmake/Modules/Platform/Emscripten.cmake
cmake --build .
popd
