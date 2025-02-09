#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c ./*.c
 
clang -o app.exe ./*.o -fsanitize=memory -fPIE -pie -lm -fno-omit-frame-pointer -g3