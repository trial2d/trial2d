#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/xcode_darwin"

mkdir -p "$BUILD_DIR"
(cd "${BUILD_DIR}" && cmake "${PWD_DIR}/${ROOT_DIR}" -G Xcode)
(cd "${BUILD_DIR}" && open "trial2d.xcodeproj")
