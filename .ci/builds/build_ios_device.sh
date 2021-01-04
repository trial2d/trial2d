#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/ios_device"

mkdir -p "${BUILD_DIR}"
(cd "${BUILD_DIR}" && cmake "${PWD_DIR}/${ROOT_DIR}"\
    -DCMAKE_BUILD_TYPE=Release\
    -DCMAKE_TOOLCHAIN_FILE="${PWD_DIR}/${ROOT_DIR}/vendor/ios-cmake/ios.toolchain.cmake"\
    -DPLATFORM=OS\
    -DDEPLOYMENT_TARGET=10.0)
(cd "${BUILD_DIR}" && cmake --build .)
