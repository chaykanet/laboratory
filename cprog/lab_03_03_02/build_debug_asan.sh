#!/bin/bash

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c main.c

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c matrix_io.c

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c logic.c

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
 -fsanitize=address -fno-omit-frame-pointer -g3 -c errcodes.c

clang -o app.exe main.o matrix_io.o logic.o errcodes.o -fsanitize=address -lm