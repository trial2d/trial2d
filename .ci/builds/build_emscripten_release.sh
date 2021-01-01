#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/emscripten_release"

PLATFORM_DIR="${DIR}/../platform"
EMSDK_DIR="${PLATFORM_DIR}/emscripten_sdk/emsdk-2.0.11"

if [ ! -d "${EMSDK_DIR}" ]; then
    "${PLATFORM_DIR}/prepare_emscripten.sh"
fi

source "${EMSDK_DIR}/emsdk_env.sh"

mkdir -p "${BUILD_DIR}"
emcmake cmake -S "${ROOT_DIR}" -B "${BUILD_DIR}" -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build "${BUILD_DIR}"
