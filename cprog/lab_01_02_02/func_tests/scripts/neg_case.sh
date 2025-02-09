#!/bin/bash

input=$1;


main="../../app.exe"

$main < "$input" > "./../../out.txt"

exec_res=$?

# Код завершение main.exe.
if [[ $exec_res -eq 1 ]]; then
    exit 0
else
    exit 1
fi