#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/darwin_debug"

mkdir -p "${BUILD_DIR}"
cmake "${ROOT_DIR}" -B "${BUILD_DIR}" -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build "${BUILD_DIR}"
(cd "${BUILD_DIR}" && ctest --verbose)
