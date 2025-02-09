#include "matrix_io.h"

#define CORR_IN 1

int input_matrix(int (*mat)[M], size_t const n, size_t const m)
{
    printf("Enter elements of matrix: ");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &mat[i][j]) != CORR_IN)
                return ERR_IO;

    return ERR_OK;
}

void print_matrix(int (*mat)[M], size_t const n, size_t const m)
{
    printf("Your matrix:\n");

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int input_sizes_mat(int *n, int *m)
{   
    printf("Enter your n, m: ");
    
    if (scanf("%d %d", n, m) != CORR_IN_TWO)
        return ERR_IO;
    
    return ERR_OK;
}    
