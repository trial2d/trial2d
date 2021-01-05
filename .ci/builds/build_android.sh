#!/bin/bash
set -e
DIR="$( cd "$( dirname "${BASH_SOURCE}" )" && pwd )"

ROOT_DIR="${DIR}/../.."
GRADLE_DIR="${ROOT_DIR}/sample/gradle"

PLATFORM_DIR="${DIR}/../platform"
ANDROID_NDK_DIR="${PLATFORM_DIR}/android_sdk/ndk/21.1.6352462"

if [ ! -d "${ANDROID_NDK_DIR}" ]; then
    "${PLATFORM_DIR}/prepare_android.sh"
fi

(cd "${GRADLE_DIR}" && ./gradlew assembleRelease)
