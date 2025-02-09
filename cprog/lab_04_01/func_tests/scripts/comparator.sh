#!/bin/bash

file_1=$1
file_2=$2

grep -oE "[+-]?[0-9]+([.][0-9]+)?" "$file_1" > ./../../res_1.txt
grep -oE "[+-]?[0-9]+([.][0-9]+)?" "$file_2" > ./../../res_2.txt

if diff ./../../res_1.txt ./../../res_2.txt > ./../../dif.txt; then
    exit 0
else
    exit 1
fi
