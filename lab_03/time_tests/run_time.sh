#!/bin/bash

if ! gcc -std=gnu99 -o0 -I./../inc -g analysis.c ./../src/csc_matrix.c ./../src/csc_operations.c ./../src/matrix_io.c -o "./app.exe" -lm; then
    echo "failed building app for size=$SIZE"
    exit 1
fi

echo "app for size=$SIZE is builded"

echo "making matrixes..."
for ((ZERO_LVL=10; ZERO_LVL <= 100; ZERO_LVL += 10)) do
    for ((SIZE=1000; SIZE <= 1000; SIZE += 100)) do
        python3 ./create_mat.py ./data/mat"$SIZE"x"$ZERO_LVL".txt $SIZE $SIZE $ZERO_LVL 
    done
done


for ((ZERO_LVL=10; ZERO_LVL <= 100; ZERO_LVL += 10)) do
    for ((i=0; i < 10; i += 1)) do
        ./app.exe ./data/mat1000x"$ZERO_LVL".txt ./temp/mat1000x"$ZERO_LVL".txt "1000" "mat" 2>&1
        ./app.exe ./data/mat1000x"$ZERO_LVL".txt ./temp/csc1000x"$ZERO_LVL".txt "1000" "csc" 2>&1
    done
done
