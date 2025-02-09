#include "matrix_io.h"

int input_matrix(int (*mat)[M], size_t const n, size_t const m)
{
    printf("Enter elements of matrix: ");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &mat[i][j]) != CORR_IN)
                return ERR_IO;

    return ERR_OK;
}

void print_arr(int const *arr, size_t const n)
{
    printf("Your array: ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int input_sizes_mat(size_t *n, size_t *m)
{    
    if (scanf("%zu %zu", n, m) != CORR_IN_TWO)
        return ERR_IO;
    
    return ERR_OK;
}    
