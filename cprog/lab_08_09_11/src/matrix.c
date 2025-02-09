#include "matrix.h"

// double **create_matrix(const size_t n, const size_t m)
// {
//     double **ptrs = malloc(sizeof(double *) * n + sizeof(double) * n * m);

//     if (!ptrs)
//         return NULL;

//     for (size_t i = 0; i < n; i++)
//         ptrs[i] = (double *) ((char *) ptrs + n * sizeof(double *) + m * i * sizeof(double));

//     return ptrs;
// }

// Защита.
double **create_matrix(const size_t n, const size_t m)
{
    double **ptrs = calloc(n, sizeof(double *));

    if (!ptrs)
        return NULL;

    for (size_t i = 0; i < n; i++)
    {
        ptrs[i] = malloc(m * sizeof(double));

        if (!ptrs[i])
        {
            free_matrix(ptrs, n);

            return NULL;
        }
    }

    return ptrs;
}

// Защита
void free_matrix(double **matrix, const size_t n)
{   
    for (size_t i = 0; i < n; i++)
    {   
        if (matrix[i])
            free(matrix[i]);
    }
    free(matrix);
}

// void free_matrix(double **matrix, const size_t n)
// {   
//     (void) n;

//     if (!matrix)
//         return;

//     free(matrix);
// }
