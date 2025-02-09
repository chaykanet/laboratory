#!/bin/bash

file_1=$1
file_2=$2

n1=$(wc -l < "$file_1")
n2=$(wc -l < "$file_2")

grep -A"$n1" "Result: .*" "$file_1" > ./../../res_1.txt
str=$(grep -oE "Result: .*" "$file_1")
sed -i s/".* Result: .*"/"$str"/ ./../../res_1.txt

grep -A"$n2" "Result: .*" "$file_2" > ./../../res_2.txt
str=$(grep -oE "Result: .*" "$file_2")
sed -i s/".* Result: .*"/"$str"/ ./../../res_2.txt


if diff ./../../res_1.txt ./../../res_2.txt > ./../../dif.txt; then
    exit 0
else
    exit 1
fi
