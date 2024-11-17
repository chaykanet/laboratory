#!/bin/bash

gcc -std=c99  -Wall -Werror -pedantic -c ./*.c

gcc -o app.exe ./*.o -lm