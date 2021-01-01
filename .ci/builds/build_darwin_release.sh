#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/darwin_release"

mkdir -p "${BUILD_DIR}"
cmake -S "${ROOT_DIR}" -B "${BUILD_DIR}" -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build "${BUILD_DIR}"
(cd "${BUILD_DIR}" && ctest --verbose)
