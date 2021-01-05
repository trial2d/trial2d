#!/bin/bash
set -e
DIR="$( cd "$( dirname "${BASH_SOURCE}" )" && pwd )"

ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/xcode_ios_device"

mkdir -p "$BUILD_DIR"
(cd "${BUILD_DIR}" && cmake "${ROOT_DIR}" -G Xcode\
    -DCMAKE_TOOLCHAIN_FILE="${ROOT_DIR}/vendor/ios-cmake/ios.toolchain.cmake"\
    -DPLATFORM=OS\
    -DDEPLOYMENT_TARGET=10.0)
(cd "${BUILD_DIR}" && open "trial2d.xcodeproj")
