#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build"
PLATFORM_DIR="${DIR}/../platform"
EMSDK_DIR="${PLATFORM_DIR}/emscripten_sdk/emsdk-2.0.11"

if [ ! -d "${EMSDK_DIR}" ]; then
    "${PLATFORM_DIR}/prepare_emscripten.sh"
fi

source "${EMSDK_DIR}/emsdk_env.sh"

mkdir -p "${BUILD_DIR}/emscripten_release"
pushd "${BUILD_DIR}/emscripten_release"
emcmake cmake "${PWD_DIR}/${ROOT_DIR}" -DCMAKE_BUILD_TYPE=Release
cmake --build .
popd
