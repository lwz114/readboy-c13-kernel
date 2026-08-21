# Readboy C13 kernel

Kernel source and board files for the Readboy C13 (MSM8996, Android 7.1 base).

Build locally:

    sudo apt install bc bison flex libssl-dev libelf-dev device-tree-compiler gcc-aarch64-linux-gnu
    ./scripts/build-c13.sh

The live device DTB and kernel configuration were extracted from the C13 recovery environment and used as the board baseline.
