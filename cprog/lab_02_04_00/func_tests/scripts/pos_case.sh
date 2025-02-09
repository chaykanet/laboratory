#!/bin/bash

input=$1;
out_expect=$2;

./../../app.exe < "$input" > ./../../out.txt

# Код завершения main.exe.
exec_res=$?

if [[ $exec_res -eq 100 ]]; then
    if ./comparator.sh ./../../out.txt "$out_expect"; then
        exit 0
    else
        exit 1
    fi
fi

if [[ $exec_res -ne 0 ]]; then
    exit 1
else
    if ./comparator.sh ./../../out.txt "$out_expect"; then
        exit 0
    else
        exit 1
    fi
fi
