#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/debug_wasm
pushd $BUILD_DIR/debug_wasm
emcmake cmake -DCMAKE_BUILD_TYPE=Debug ../..
cmake --build .
popd
