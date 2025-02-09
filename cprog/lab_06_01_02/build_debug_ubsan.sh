#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -Wvla -fsanitize=undefined -fno-omit-frame-pointer -g3 -c ./*.c

clang -o app.exe ./*.o -fsanitize=undefined -lm