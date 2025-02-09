#include "set_op.h"

#include "set.h"

bool find_elem(int *arr, const size_t index, const size_t n, const int elem)
{
    for (size_t i = index; i < n; i++)
        if (arr[i] == elem)
            return true;

    return false;
}

int intersec(int **set_in, size_t *in_n, int *set_a, size_t const a_n, int *set_b, size_t const b_n)
{
    size_t n = a_n < b_n ? a_n : b_n;

    if (n == 0)
    {   
        *in_n = 0;
        *set_in = NULL;
        return ERR_OK;
    }

    int *ptrs = create(n);

    if (!ptrs)
        return ERR_ALLOC;

    size_t index = 0;
    
    for (size_t i = 0; i < a_n; i++)
    {   
        bool is_find = false;
        
        is_find = find_elem(set_b, 0, b_n, set_a[i]);
    
        if (is_find)
        {
            ptrs[index] = set_a[i];
            index++;
        }
    }

    *in_n = index;

    *set_in = ptrs;

    return ERR_OK;
}

int to_set(int **set, size_t *set_n, int *arr, const size_t n)
{
    size_t s_n = 0;

    for (size_t i = 0; i < n; i++)
        if (!find_elem(arr, 0, i, arr[i]))
            s_n++;

    if (s_n == 0)
    {
        *set = NULL;
        *set_n = 0;

        return ERR_OK; 
    }

    size_t index = 0;

    int *p = create(s_n);

    if (!set)
        return ERR_ALLOC;

    for (size_t i = 0; i < n && index < s_n; i++)
    {
        bool is_find = false;

        is_find = find_elem(p, 0, index, arr[i]);

        if (!is_find)
        {
            p[index] = arr[i];
            index++;
        }
    }

    *set = p;
    *set_n = s_n;

    return ERR_OK;
}
