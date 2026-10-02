#!/bin/sh

gcc -o game -std=c99 -Wall -Wextra -Wpedantic -Wno-unused-function -Wno-unused-variable source/bitmap.c source/file_linux.c source/input.c source/input_linux.c source/main.c source/math.c source/opengl.c source/renderer_opengl.c source/string.c source/time.c source/time_linux.c source/window_linux.c -lGL -lm -lX11 -lXinerama
