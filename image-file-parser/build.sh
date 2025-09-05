#!/bin/bash

mkdir build

cmake -G "MinGW Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S ./ -B ./build

mingw32-make -C build

echo "Build complete."
