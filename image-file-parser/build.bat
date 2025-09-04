@echo off
cmake -G "MinGW Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

mingw32-make
