#ifndef ERRCODES_H
#define ERRCODES_H

#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_ALLOC 4
#define ERR_OVERFLOW 5
#define ERR_EMPTY 6


void print_err(int const rc);

#endif
