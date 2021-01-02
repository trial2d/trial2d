#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/linux_debug"

mkdir -p "${BUILD_DIR}"
(cd "${BUILD_DIR}" && cmake "${PWD_DIR}/${ROOT_DIR}" -DCMAKE_BUILD_TYPE=Debug)
(cd "${BUILD_DIR}" && cmake --build .)
(cd "${BUILD_DIR}" && ctest --verbose)
