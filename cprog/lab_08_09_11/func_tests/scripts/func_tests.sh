#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m' 
NC='\033[0m'

path_to_script=$(dirname "$0")

cd "$path_to_script" || exit

# Создаем массивы тестов.

all_pos_in=()
all_pos_out=()

all_neg_in=()
all_neg_out=()

all_pos_args=()
all_neg_args=()

verb="False"
valg="False"

for arg in "$@"; do
    # Проверка на режим скрипта.
    if [[ $arg == "-v" || $arg == "--verbose" ]]; then
        verb="True"
    fi

    if [[ $arg == "--valgrind" ]]; then
        valg="True"
    fi
done


# Определяем тесты в data.
for file in ./../data/*; do
    if [ -f "$file" ]; then
        if [[ "$file" == "./../data/pos_"[0-9][0-9]"_in.txt" ]]; then
            all_pos_in+=("$file")
        fi

        if [[ "$file" == "./../data/pos_"[0-9][0-9]"_out.txt" ]]; then
            all_pos_out+=("$file")
        fi

        if [[ "$file" == "./../data/pos_"[0-9][0-9]"_args.txt" ]]; then
            all_pos_args+=("$file")
        fi

        if [[ "$file" == "./../data/neg_"[0-9][0-9]"_in.txt" ]]; then
            all_neg_in+=("$file")
        fi

        if [[ "$file" == "./../data/neg_"[0-9][0-9]"_out.txt" ]]; then
            all_neg_out+=("$file")
        fi

        if [[ "$file" == "./../data/neg_"[0-9][0-9]"_args.txt" ]]; then
            all_neg_args+=("$file")
        fi
    fi
done

# Кол-во позитивных и негативных тестов.
len_pos=${#all_pos_in[@]}
len_neg=${#all_neg_in[@]}

count_pos=0
count_neg=0

if [[ "$verb" == "True" ]]; then
    for (( i=0; i < len_pos; i++ ));
    do
        if ./pos_case.sh "${all_pos_in[$i]}" "${all_pos_out[$i]}" "${all_pos_args[$i]}" "$valg"; then
            if [[ $i -le 9 ]]; then
                echo "POS_0$((i + 1)): PASS."
            else
                echo "POS_$((i + 1)): PASS."
            fi
            count_pos=$((count_pos + 1))
        else
            if [[ $i -le 9 ]]; then
                echo "POS_0$((i + 1)): FAILED."
            else
                echo "POS_$((i + 1)): FAILED."
            fi
        fi
    done

    for (( i=0; i < len_neg; i++ ));
    do
        if ./neg_case.sh "${all_neg_in[$i]}" "${all_neg_args[$i]}" "$valg"; then
            if [[ $i -le 9 ]]; then
                echo "NEG_0$((i + 1)): PASS."
            else
                echo "NEG_$((i + 1)): PASS."
            
            fi
            count_neg=$((count_neg + 1))
        else
            if [[ $i -le 9 ]]; then
                echo "NEG_0$((i + 1)): FAILED."
            else
                echo "NEG_$((i + 1)): FAILED."
            fi
        fi
    done
else
    for (( i=0; i < len_pos; i++ ));
    do
        if ./pos_case.sh "${all_pos_in[$i]}" "${all_pos_out[$i]}" "${all_pos_args[$i]}" "$valg"; then
            count_pos=$((count_pos + 1))
        fi
    done

    for (( i=0; i < len_neg; i++ ));
    do
        if ./neg_case.sh "${all_neg_in[$i]}" "${all_neg_args[$i]}" "$valg"; then
            count_neg=$((count_neg + 1))
        fi
    done
fi

count=$((len_pos + len_neg - count_pos - count_neg))

echo "POS TESTS PASSED $count_pos of $len_pos"
echo "NEG TESTS PASSED $count_neg of $len_neg"
echo "TOTAL TESTS FAIILED: $count."
exit $count