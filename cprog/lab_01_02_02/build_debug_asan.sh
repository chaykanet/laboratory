#!/bin/bash

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -Wvla -fsanitize=address -fno-omit-frame-pointer -g3 -c main.c

clang -o app.exe main.o -fsanitize=address -lm