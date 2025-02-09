#include "set.h"

int *create(size_t const n)
{
    if (n == 0)
        return NULL;

    int *ptrs = malloc(n * sizeof(int));

    if (!ptrs)
        return NULL;
    
    return ptrs;
}

void free_set(int *set)
{
    if (set != NULL)
        free(set);
}
