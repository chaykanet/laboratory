#ifndef SET_OP_H
#define SET_OP_H

#include "set.h"

#define ERR_OK 0

int to_set(int **set, size_t *set_n, int *arr, const size_t n);

bool find_elem(int *arr, const size_t index, const size_t n, const int elem);

int intersec(int **set_in, size_t *in_n, int *set_a, size_t const a_n, int *set_b, size_t const b_n);

#endif