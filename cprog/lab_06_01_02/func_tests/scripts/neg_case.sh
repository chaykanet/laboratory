#!/bin/bash

input=$1;

import=False

file=...
file_txt=...

file_args=$(cat "$2")
for arg in $file_args; do
    if [[ "$arg" == "sb" ]]; then
        import=True
    fi
    i=$((i + 1))
done

if [[ $import == "False" ]]; then
    file=$(echo "$file_args" | grep -o '[^ ]*txt\b')
    name_input=$(basename "$input")
    file_name=$(basename "$file")
    file=${file/$file_name/$name_input}
fi

if [[ $import == "True" ]]; then
    file=$(echo "$file_args" | grep -o '[^ ]*bin\b')
fi

type="txt"

if [[ "$import" == "True" ]]; then
    file=$(echo "$file_args" | grep -o '[^ ]*bin\b')
    type=$(basename "$file")
    type=${type##*.}

    if [[ $type == "bin" ]]; then
        file_txt=${file/bin/txt}
        file_args=${file_args/$file/$file_txt}
    fi
fi

if [[ $import == "True" ]]; then
    cd ./../../ || exit
    bin=./in.bin
    if ! ./app.exe "import" "$file_txt" "$bin" > tmp.txt 2>&1; then
        exit 0
    fi
    file_args=${file_args/$file_txt/$bin}
    # file_args=${file_args/$file/$bin}
    if ! echo "$file_args" | xargs --no-run-if-empty ./app.exe > tmp.txt 2>&1; then
        exit 0
    fi
    # if ! ./app.exe "export" "$bin" "out.txt" > tmp.txt 2>&1; then
    #     exit 0
    # fi
    cd ./func_tests/scripts || exit
else
    cd ./../../ || exit
    # file_args="${file_args/$file/$input}"
    
    if ! echo "$file_args" | xargs --no-run-if-empty ./app.exe > tmp.txt 2>&1; then
        exit 0
    fi
    cd ./func_tests/scripts || exit
fi

exec_res=$?

# Код завершение main.exe.
if [[ $exec_res -ne 0 ]]; then
    exit 0
else
    exit 1
fi
