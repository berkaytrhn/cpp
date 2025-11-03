#!/bin/bash

mkdir -p $1/build

cmake -G "MinGW Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S $1/ -B $1/build

mingw32-make -C $1/build

echo "Build complete."
