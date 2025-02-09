#include "logic.h"

bool find_column(int const *p, size_t const n)
{   
    if (n == ONE)
        return false;

    size_t i = 0;
    while (i < n - 1)
    {   
        if (*p * *(p + M) >= 0)
            return false;
        
        p += M;
        i++;
    }

    return true;
}

void new_array(int *arr, size_t *a_n, int (*mat)[M], size_t const n, size_t const m)
{
    *a_n = m;

    for (size_t i = 0; i < m; i++)
        if (find_column(mat[0] + i, n))
            arr[i] = ONE;
        else
            arr[i] = ZERO;
}
