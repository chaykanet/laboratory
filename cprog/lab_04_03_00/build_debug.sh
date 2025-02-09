#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -g3 -c ./*.c

gcc -o app.exe ./*.o -lm
