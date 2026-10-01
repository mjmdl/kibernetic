#!/bin/sh

gcc -o game -std=c99 -Wall -Wextra -Wpedantic -Wno-unused-function -Wno-unused-variable source/main.c source/string.c source/window_linux.c -lGL -lX11 -lXinerama
