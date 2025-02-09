#!/bin/bash

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c main.c

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c string_func.c

clang -o app.exe main.o string_func.o -fsanitize=address -lm