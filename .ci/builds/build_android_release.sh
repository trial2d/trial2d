#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

SAMPLE_DIR="${DIR}/../../sample"
PLATFORM_DIR="${DIR}/../platform"
ANDROID_NDK_DIR="${PLATFORM_DIR}/android_sdk/ndk/21.1.6352462"

if [ ! -d "${ANDROID_NDK_DIR}" ]; then
    "${PLATFORM_DIR}/prepare_android.sh"
fi

pushd "${SAMPLE_DIR}/gradle"
gradle assembleRelease
popd
