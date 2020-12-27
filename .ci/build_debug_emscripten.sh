#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

BUILD_DIR="${DIR}/../build"
EMSDK_DIR="${DIR}/emscripten_sdk/emsdk-2.0.11"

if [ ! -d "${EMSDK_DIR}" ]; then
    "${DIR}/prepare_emscripten.sh"
fi

source "${EMSDK_DIR}/emsdk_env.sh"

mkdir -p $BUILD_DIR/debug_emscripten
pushd $BUILD_DIR/debug_emscripten
emcmake cmake ../.. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
popd
