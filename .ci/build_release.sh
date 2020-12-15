#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/release
pushd $BUILD_DIR/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
cmake --build .
ctest --verbose
popd
