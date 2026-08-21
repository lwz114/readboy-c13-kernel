#!/usr/bin/env bash
set -euo pipefail

export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
OUT=out-c13
make O="$OUT" readboy_c13_defconfig
make O="$OUT" -j"$(nproc)" Image.gz dtbs
