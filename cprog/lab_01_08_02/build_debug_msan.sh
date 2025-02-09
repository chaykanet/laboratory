#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -Wvla -c main.c

clang -o app.exe main.o -fsanitize=memory -fPIE -pie -lm -fno-omit-frame-pointer -g3