#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/xcode_ios_simulator"

mkdir -p "$BUILD_DIR" && pushd "$BUILD_DIR"
cmake "${PWD_DIR}/${ROOT_DIR}" -G Xcode\
    -DCMAKE_TOOLCHAIN_FILE="${ROOT_DIR}/cmake/ios.toolchain.cmake"\
    -DPLATFORM=OS64COMBINED\
    -DDEPLOYMENT_TARGET=10.0
open trial2d.xcodeproj
popd
