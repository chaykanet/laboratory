#!/bin/bash

verbose=1

if [[ $1 == "-v" || $1 == "-verbose" ]]; then
    verbose=0
fi

sanitize=(./build_release.sh ./build_debug.sh ./build_debug_asan.sh ./build_debug_msan.sh 
 ./build_debug_ubsan.sh ./collect_coverage.sh)

./clean.sh

 for (( i=0; i<${#sanitize[@]}; i++ ));
 do
    echo "${sanitize[$i]}"

    bash "${sanitize[$i]}"
    
    cd ./func_tests/scripts/ || exit

    if [[ "$verbose" -eq 0 ]]; then
        ./func_tests.sh -v
    else
        ./func_tests.sh
    fi

    echo -e "\n"

    cd ./../../

    ./clean.sh
done