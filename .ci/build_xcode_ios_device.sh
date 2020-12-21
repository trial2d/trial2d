#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/xcode_ios_device
pushd $BUILD_DIR/xcode_ios_device
cmake ../.. -G Xcode\
    -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/../cmake/ios.toolchain.cmake\
    -DPLATFORM=OS\
    -DDEPLOYMENT_TARGET=10.0
open trial2d.xcodeproj
popd
