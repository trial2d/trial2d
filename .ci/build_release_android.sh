#!/bin/bash
set -e
BUILD_DIR=`dirname "$BASH_SOURCE"`/../build
mkdir -p $BUILD_DIR/release_android
pushd $BUILD_DIR/release_android
cmake ../.. -DCMAKE_BUILD_TYPE=Release\
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake\
    -DANDROID_PLATFORM=android-19\
    -DANDROID_ABI=armeabi-v7a
cmake --build .
popd
