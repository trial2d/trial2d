#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/release_wasm
pushd $BUILD_DIR/release_wasm
cmake ../.. -DCMAKE_BUILD_TYPE=Release\
    -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN_ROOT/libexec/cmake/Modules/Platform/Emscripten.cmake
cmake --build .
popd
