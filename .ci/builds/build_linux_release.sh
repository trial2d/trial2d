#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/linux_release"

mkdir -p "$BUILD_DIR" && pushd "$BUILD_DIR"
cmake "${PWD_DIR}/${ROOT_DIR}" -DCMAKE_BUILD_TYPE=Release
cmake --build .
ctest --verbose
popd
