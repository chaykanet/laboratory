#!/bin/bash

file_1=$1
file_2=$2

grep -oE "Result: .*" "$file_1" > ./../../res_1.txt
grep -oE "Result: .*" "$file_2" > ./../../res_2.txt

if diff ./../../res_1.txt ./../../res_2.txt; then
    exit 0
else
    exit 1
fi
