#!/bin/bash
set -e

CMDLINE_TOOLS_ID=6858069
BUILD_TOOLS_VERSION=30.0.3
ANDROID_PLATFORM_VERSION=30
NDK_VERSION=21.1.6352462

#
#
#

error_exit()
{
    echo "${1:-"Unknown Error"}" 1>&2
    exit 1
}

#
#
#

DIR=`dirname "${BASH_SOURCE}"`

DOWNLOADS_DIR="${DIR}/.downloads"
ANDROID_SDK_DIR="${DIR}/android_sdk"

mkdir -p "${DOWNLOADS_DIR}"
mkdir -p "${ANDROID_SDK_DIR}"

#
#
#

SYSTEM_NAME=`uname | tr '[:upper:]' '[:lower:]'`
case "${SYSTEM_NAME}" in
    darwin*) CMDLINE_TOOLS_NAME="commandlinetools-mac-${CMDLINE_TOOLS_ID}_latest";;
    linux*) CMDLINE_TOOLS_NAME="commandlinetools-linux-${CMDLINE_TOOLS_ID}_latest";;
    *) error_exit "Error. Unknown host system: ${SYSTEM_NAME}";;
esac

CMDLINE_TOOLS_URL="https://dl.google.com/android/repository/${CMDLINE_TOOLS_NAME}.zip"
CMDLINE_TOOLS_URL_FILENAME="${DOWNLOADS_DIR}/cmdline-tools-${CMDLINE_TOOLS_ID}.zip"

#
#
#

if [ ! -e "${CMDLINE_TOOLS_URL_FILENAME}" ]; then
    echo "Downloading cmdline-tools: ${CMDLINE_TOOLS_URL_FILENAME}"
    wget -q "${CMDLINE_TOOLS_URL}" -O "${CMDLINE_TOOLS_URL_FILENAME}"
else
    echo "Found downloaded package:" ${CMDLINE_TOOLS_URL_FILENAME}
fi

CMDLINE_TOOLS_DIR="${ANDROID_SDK_DIR}/cmdline-tools"

if [ ! -d "${CMDLINE_TOOLS_DIR}" ]; then
    echo "Unpacking cmdline-tools: ${CMDLINE_TOOLS_DIR}"
    unzip -q "${CMDLINE_TOOLS_URL_FILENAME}" -d "${ANDROID_SDK_DIR}"
else
    echo "Found unpacked cmdline-tools: ${CMDLINE_TOOLS_DIR}"
fi

#
#
#

echo "Installing android sdk packages: ${ANDROID_SDK_DIR}"

(echo y | "${CMDLINE_TOOLS_DIR}/bin/sdkmanager" --sdk_root="${ANDROID_SDK_DIR}" "extras;android;m2repository")
(echo y | "${CMDLINE_TOOLS_DIR}/bin/sdkmanager" --sdk_root="${ANDROID_SDK_DIR}" "build-tools;${BUILD_TOOLS_VERSION}")
(echo y | "${CMDLINE_TOOLS_DIR}/bin/sdkmanager" --sdk_root="${ANDROID_SDK_DIR}" "platforms;android-${ANDROID_PLATFORM_VERSION}")
(echo y | "${CMDLINE_TOOLS_DIR}/bin/sdkmanager" --sdk_root="${ANDROID_SDK_DIR}" "ndk;${NDK_VERSION}")

rm -rf "${ANDROID_SDK_DIR}/emulator"
