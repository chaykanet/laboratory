#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ERR_ALLOC 2

int *create(size_t const n);

void free_set(int *set);

#endif
