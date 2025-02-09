#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c main.c

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c string_func.c

clang -o app.exe main.o string_func.o -fsanitize=memory -fPIE -pie -lm -fno-omit-frame-pointer -g3