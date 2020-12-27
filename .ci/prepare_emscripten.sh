#!/bin/bash
set -e

EMSDK_VERSION="2.0.11"

#
#
#

DIR=`dirname "${BASH_SOURCE}"`

DOWNLOADS_DIR="${DIR}/downloads"
EMSCRIPTEN_SDK_DIR="${DIR}/emscripten_sdk"

mkdir -p "${DOWNLOADS_DIR}"
mkdir -p "${EMSCRIPTEN_SDK_DIR}"

#
#
#

EMSDK_URL="https://github.com/emscripten-core/emsdk/archive/${EMSDK_VERSION}.zip"
EMSDK_URL_FILENAME="${DOWNLOADS_DIR}/emsdk-${EMSDK_VERSION}.zip"

#
#
#

if [ ! -e "${EMSDK_URL_FILENAME}" ]; then
    echo "Downloading emsdk: ${EMSDK_URL_FILENAME}"
    wget -q "${EMSDK_URL}" -O "${EMSDK_URL_FILENAME}"
else
    echo "Found downloaded package:" ${EMSDK_URL_FILENAME}
fi

EMSDK_DIR="${EMSCRIPTEN_SDK_DIR}/emsdk-${EMSDK_VERSION}"

if [ ! -d "${EMSDK_DIR}" ]; then
    echo "Unpacking emsdk: ${EMSDK_DIR}"
    unzip -q "${EMSDK_URL_FILENAME}" -d "${EMSCRIPTEN_SDK_DIR}"
else
    echo "Found unpacked emsdk: ${EMSDK_DIR}"
fi

#
#
#

echo "Installing emscripten sdk: ${EMSCRIPTEN_SDK_DIR}"

"${EMSDK_DIR}/emsdk" install ${EMSDK_VERSION}
"${EMSDK_DIR}/emsdk" activate ${EMSDK_VERSION}
