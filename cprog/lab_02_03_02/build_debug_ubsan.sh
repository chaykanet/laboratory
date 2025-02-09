#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=undefined -fno-omit-frame-pointer -g3 -c main.c

clang -o app.exe main.o -fsanitize=undefined -lm