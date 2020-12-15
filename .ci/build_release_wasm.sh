#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/release_wasm
pushd $BUILD_DIR/release_wasm
emcmake cmake -DCMAKE_BUILD_TYPE=Release ../..
cmake --build .
popd
