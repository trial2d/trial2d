#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/asmjs_release"

PLATFORM_DIR="${DIR}/../platform"
EMSDK_DIR="${PLATFORM_DIR}/emscripten_sdk/emsdk-2.0.11"

if [ ! -d "${EMSDK_DIR}" ]; then
    "${PLATFORM_DIR}/prepare_emscripten.sh"
fi

source "${EMSDK_DIR}/emsdk_env.sh"

mkdir -p "${BUILD_DIR}"
(cd "${BUILD_DIR}" && emcmake cmake "${PWD_DIR}/${ROOT_DIR}"\
    -DCMAKE_BUILD_TYPE=Release\
    -DT2D_EMSCRIPTEN_ASMJS=ON)
(cd "${BUILD_DIR}" && cmake --build .)
