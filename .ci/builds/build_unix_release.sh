#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build"

mkdir -p "$BUILD_DIR/unix_release"
pushd "$BUILD_DIR/unix_release"
cmake "${PWD_DIR}/${ROOT_DIR}" -DCMAKE_BUILD_TYPE=Release
cmake --build .
ctest --verbose
popd
