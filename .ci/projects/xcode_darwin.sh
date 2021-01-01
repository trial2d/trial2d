#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

ROOT_DIR="${DIR}/../.."
BUILD_DIR="${ROOT_DIR}/build/xcode_darwin"

mkdir -p "$BUILD_DIR"
cmake -S "${ROOT_DIR}" -B "$BUILD_DIR" -G Xcode
open "$BUILD_DIR/trial2d.xcodeproj"
