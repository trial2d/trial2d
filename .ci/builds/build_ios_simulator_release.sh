#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/ios_simulator_release"

mkdir -p "${BUILD_DIR}"
(cd "${BUILD_DIR}" && cmake "${PWD_DIR}/${ROOT_DIR}"\
    -DCMAKE_BUILD_TYPE=Release\
    -DCMAKE_TOOLCHAIN_FILE="${PWD_DIR}/${ROOT_DIR}/cmake/ios.toolchain.cmake"\
    -DPLATFORM=SIMULATOR64\
    -DDEPLOYMENT_TARGET=10.0)
(cd "${BUILD_DIR}" && cmake --build .)
