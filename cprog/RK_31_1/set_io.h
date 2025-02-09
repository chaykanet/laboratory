#ifndef SET_IO_H 
#define SET_IO_H

#include <stdlib.h>
#include <stdlib.h>

#include "set.h"
#include "set_op.h"

#define ERR_OK 0
#define ERR_IO 1

int input_arr(int *arr, const size_t n);

// int input_set(int *set, size_t *set_n, size_t const n);

void print_set(int *set, const size_t n);

#endif
