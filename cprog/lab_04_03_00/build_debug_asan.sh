#!/bin/bash

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c ./*.c

clang -o app.exe ./*.o -fsanitize=address -lm
