#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

PWD_DIR=`pwd`
ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/xcode_darwin"

mkdir -p "$BUILD_DIR" && pushd "$BUILD_DIR"
cmake "${PWD_DIR}/${ROOT_DIR}" -G Xcode
open trial2d.xcodeproj
popd
