#!/bin/bash

input=$1;
out_expect=$2;
valgrind=$4;

import=False

file=...
file_txt=...

#аргументы exe
file_args=$(cat "$3")
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
    ./app.exe "import" "$file_txt" "$bin"
    file_args=${file_args/$file_txt/$bin}
    # file_args=${file_args/$file/$bin}
    echo "$file_args" | xargs ./app.exe
    # ./app.exe "export" "$bin" "out.txt"
    cd ./func_tests/scripts || exit
fi

if [[ $valgrind == "True" ]]; then
    cd ./../../ || exit
    # file_args="${file_args/$file/$input}"
    echo "$file_args" | xargs valgrind --leak-check=yes --quiet ./app.exe >> valgrind.txt
    cd ./func_tests/scripts || exit
fi

if [[ $valgrind != "True" ]]; then
    cd ./../../ || exit
    # file_args="${file_args/$file/$input}"
    echo "$file_args" | xargs ./app.exe
    cd ./func_tests/scripts || exit
fi

exec_res=$?

if [[ $exec_res -ne 0 ]]; then
    exit 1
else
    if ./comparator.sh ./../../out.txt "$out_expect"; then
        exit 0
    else
        exit 1
    fi
fi
