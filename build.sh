#!/bin/bash

# build + run steps
ls -la && export V=12 && dpkg --add-architecture i386 && export DEBIAN_FRONTEND=noninteractive && apt update && apt install libc++abi-$V-dev:i386 libc++-$V-dev:i386 clang-$V:i386 llvm-$V:i386 -y && cd build; clang++-$V -m32 -g -fsanitize=address -stdlib=libc++ main.cpp -o main && ./main