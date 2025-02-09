#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c main.c

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c matrix_io.c

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c logic.c

clang -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion \
 -c errcodes.c

clang -o app.exe main.o matrix_io.o logic.o errcodes.o -fsanitize=memory -fPIE -pie -lm -fno-omit-frame-pointer -g3