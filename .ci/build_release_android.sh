#!/bin/bash
set -e
DIR=`dirname "${BASH_SOURCE}"`

BUILD_DIR="${DIR}/../build"
ANDROID_NDK_DIR="${DIR}/android_sdk/ndk/21.1.6352462"

if [ ! -d "${ANDROID_NDK_DIR}" ]; then
    "${DIR}/prepare_android.sh"
fi

mkdir -p $BUILD_DIR/release_android
pushd $BUILD_DIR/release_android
cmake ../.. -DCMAKE_BUILD_TYPE=Release\
    -DCMAKE_TOOLCHAIN_FILE="${ANDROID_NDK_DIR}/build/cmake/android.toolchain.cmake"\
    -DANDROID_ABI=armeabi-v7a\
    -DANDROID_PLATFORM=android-19
cmake --build .
popd
