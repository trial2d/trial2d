#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/unix_debug"

mkdir -p "$BUILD_DIR" && pushd "$BUILD_DIR"
cmake "${PWD_DIR}/${ROOT_DIR}" -DCMAKE_BUILD_TYPE=Debug
cmake --build .
ctest --verbose
popd
