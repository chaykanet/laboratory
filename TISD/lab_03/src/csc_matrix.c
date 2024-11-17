#include "csc_matrix.h"
#include <stdio.h>
void freeSparseMatrix(sparseMatrix_t *matrix)
{   
    if (!matrix)
        return;

    free(matrix->A);
    free(matrix->IA);
    free(matrix->JA);
    free(matrix);
}

void free_vector(vec_t *vector)
{   
    if (!vector)
        return;

    free(vector->B);
    free(vector->JB);
    free(vector);
}

int init_sparseMatrix(sparseMatrix_t *csc, int **matrix, int none_zero_count, int num_rows, int row_len)
{   
    if (none_zero_count < 0)
        return ERR_IO;
        
    csc->numNonZero = none_zero_count; 
    size_t index = 0;
    size_t i_JB = 1;
    size_t calc = 0;
    csc->JA[0] = 0;
    for (int i = 0; i < row_len; i++)
    {   
        for (int j = 0; j < num_rows; j++)
        {
            if (matrix[j][i] != 0)
            {
                csc->A[index] = matrix[j][i];
                csc->IA[index] = j;
                index++;
                calc++;
            }
        }

        csc->JA[i_JB] = calc;
        i_JB++;
    }

    csc->row_len = row_len;
    csc->num_rows = num_rows;

    return ERR_OK;
}

sparseMatrix_t *create_sparseMatrix(int **matrix, int num_rows, int row_len)
{
    sparseMatrix_t *csc = malloc(sizeof(sparseMatrix_t));
    int *pA = NULL, *pIA = NULL, *pJA = NULL; 
    
    int none_zero_count = 0;
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < row_len; j++)
            if (matrix[i][j] != 0)
                none_zero_count++;
    
    if (!csc || none_zero_count == 0)
        return NULL;

    pA = malloc(none_zero_count * sizeof(int));

    if (!pA)
    {   
        freeSparseMatrix(csc);
        return NULL;
    }
    csc->A = pA;

    pIA = malloc(none_zero_count * sizeof(int));

    csc->IA = pIA;

    if (!pIA)
    {   
        freeSparseMatrix(csc);
        return NULL;
    }
    pJA = malloc((row_len + 1) * sizeof(int));

    if (!pJA)
    {   
        freeSparseMatrix(csc);
        return NULL;
    }

    csc->JA = pJA;
    
    int rc = init_sparseMatrix(csc, matrix, none_zero_count, num_rows, row_len);

    if (rc != ERR_OK)
    {   
        freeSparseMatrix(csc);
        return NULL;
    }

    return csc;
}

int init_vector(vec_t *vector, int *values, int *indexes, int none_zero_count, int vec_len)
{
    if (none_zero_count < 0)
        return ERR_IO;
    
    vector->numNonZero = none_zero_count;
    vector->vec_len = vec_len;

    for (int i = 0; i < none_zero_count; i++)
    {   
        if (indexes[i] < 0)
            return ERR_IO;

        if (indexes[i] >= vec_len)
            return ERR_RANGE;

        vector->B[i] = values[i];
        vector->JB[i] = indexes[i];
    }

    return ERR_OK;
}

vec_t *create_vector(int *values, int *indexes, int none_zero_count, int vec_len)
{
    vec_t *vector = malloc(sizeof(vec_t));

    if (!vector)
        return NULL;

    int *pB = malloc(sizeof(int) * none_zero_count);

    if (!pB)
    {   
        free(vector);
        return NULL;
    }
    int *pJB = malloc(sizeof(int) * none_zero_count);

    if (!pJB)
    {   
        free(vector);
        free(pB);
        return NULL;
    }

    vector->B = pB;
    vector->JB = pJB;
    
    int rc = init_vector(vector, values, indexes, none_zero_count, vec_len);

    if (rc != ERR_OK)
        return NULL;

    return vector;
}

int **create_matrix(size_t const n, size_t const m)
{
    int **ptrs = calloc(n, sizeof(int *));

    if (!ptrs)
        return NULL;

    int *pvalues = malloc(n * m * sizeof(int));
    
    if (!pvalues)
    {   
        free(ptrs);
        return NULL;
    }
    
    for (size_t i = 0; i < n; i++)
        ptrs[i] = (pvalues + m * i);

    return ptrs;
}

void free_matrix(int **matrix)
{   
    if (matrix)
    {
        free(matrix[0]);
        
        free(matrix);
    }
}
