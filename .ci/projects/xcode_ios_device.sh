#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/xcode_ios_device"

mkdir -p "$BUILD_DIR"
cmake -S "${ROOT_DIR}" -B "$BUILD_DIR" -G Xcode\
    -DCMAKE_TOOLCHAIN_FILE="${ROOT_DIR}/cmake/ios.toolchain.cmake"\
    -DPLATFORM=OS\
    -DDEPLOYMENT_TARGET=10.0
open "$BUILD_DIR/trial2d.xcodeproj"
