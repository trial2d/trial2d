#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/debug
pushd $BUILD_DIR/debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
cmake --build .
ctest --verbose
popd
