#!/bin/bash

./clean.sh

bash build_gcov.sh

cd ./func_tests/scripts || exit

bash ./func_tests.sh

cd ../../

gcov app-main.exe app-object_t_array.exe app-object_t.exe