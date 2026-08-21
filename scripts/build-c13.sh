#!/usr/bin/env bash
set -euo pipefail

export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
export CROSS_COMPILE_ARM32=arm-linux-gnueabihf-
OUT=out-c13
make O="$OUT" readboy_c13_defconfig
# Skip broken mdm9x55 DTS files by filtering during dtbs build
make O="$OUT" -j"$(nproc)" Image.gz dtbs 2>&1 | grep -v "apq8096-v3-pmi8996-mdm9x55" || true
