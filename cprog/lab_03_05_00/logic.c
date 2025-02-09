#include "logic.h"
#include "matrix_io.h"

int back_to_mat(int (*mat)[M], size_t const n, size_t const m, int const *arr, size_t const a_n)
{   
    if (a_n == 0)
        return ERR_IO;

    size_t index = 0;
    size_t calc_back = 0;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_simple(mat[i][j]) && index < a_n)
            {
                mat[i][j] = arr[index];
                ++index;
                ++calc_back;
            }

    if (calc_back != a_n)
        return ERR_IO;
        
    return ERR_OK;
}

void swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void reverse_arr(int *arr, size_t const a_n)
{
    for (size_t i = 0; i < a_n / 2; i++)
        swap(&arr[i], &arr[a_n - 1 - i]);
}

bool is_simple(int const n)
{
    int tmp = n;

    if (tmp == ONE || tmp <= 0)
        return false;

    int k = tmp / DIV_BY_TWO;
    int i = TWO;

    bool simple = true;
    while (simple && i <= k)
    {
        if (tmp % i == 0)
            simple = false;
        
        ++i;
    }

    return simple;
}

void take_from_mat(int (*mat)[M], size_t const n, size_t const m, int *arr, size_t *a_n)
{   
    *a_n = 0;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_simple(mat[i][j]))
            {
                arr[*a_n] = mat[i][j];
                *a_n += 1;
            }
}
