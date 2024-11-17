#!/bin/bash

gcc -std=c99 -g3 -c ./*.c

gcc -o app.exe ./*.o -lm