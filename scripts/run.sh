#!/bin/bash

# OpenCV MinGW binaries path
export PATH="../libs/OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin:$PATH"

# Running the given executable
$1/build/${@:2}