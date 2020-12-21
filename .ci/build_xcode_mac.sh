#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/xcode_mac
pushd $BUILD_DIR/xcode_mac
cmake ../.. -G Xcode
open trial2d.xcodeproj
popd
