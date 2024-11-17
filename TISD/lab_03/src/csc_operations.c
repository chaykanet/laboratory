#include "csc_operations.h"
#include <stdio.h>
int *multvec_mat(size_t *res_len, int **matrix, size_t const n, size_t const m, int *vector, size_t const n_v)
{   
    if (n_v != m)
        return NULL;

    int *pvec = malloc(sizeof(int) * n);

    if (!pvec)
        return NULL;

    int sum = 0;
    
    for (size_t i = 0; i < n; i++)
    {
        sum = 0;
        for (size_t j = 0; j < m; j++)
            sum += matrix[i][j] * vector[j];

        pvec[i] = sum; 
    }

    *res_len = n;

    return pvec;
}

int *multvec_csc(size_t *res_len, sparseMatrix_t *matrix, vec_t *vector)
{   
    int *result = calloc(matrix->num_rows, sizeof(int));
    
    if (!result) return NULL;

    int row_len = matrix->row_len;

    if (row_len != vector->vec_len) return NULL;

    int *vector_map = calloc(row_len, sizeof(int));
    for (int l = 0; l < vector->numNonZero; l++) {
        vector_map[vector->JB[l]] = vector->B[l];
    }

    for (int i = 0; i < row_len; i++) 
    {
        int start = matrix->JA[i];
        int end = matrix->JA[i + 1];
    
        for (int j = start; j < end; j++) 
        {   
            int row_index = matrix->IA[j];
            int value = matrix->A[j];
            result[row_index] += value * vector_map[i];
        }
    }

    free(vector_map);
    *res_len = matrix->num_rows;

    return result;
}

sparseMatrix_t *matconvert_tocsc(int **matrix, size_t const n, size_t const m)
{
    sparseMatrix_t *csc = create_sparseMatrix(matrix, n, m);

    return csc;
}  

int **csc_convert_tomat(size_t *n, size_t *m, sparseMatrix_t *csc)
{   
    if (!csc)
        return NULL;

    size_t n_mat = 0;
    size_t m_mat = 0;

    n_mat = csc->num_rows;
    m_mat = csc->row_len;
    
    int **matrix = create_matrix(n_mat, m_mat);

    if (!matrix)
        return NULL;

    for (size_t i = 0; i < n_mat; i++)
        for (size_t j = 0; j < m_mat; j++)
            matrix[i][j] = 0;

    for (int j = 0; j < csc->row_len; j++)
    {
        for (int k = csc->JA[j]; k < csc->JA[j + 1]; k++) 
        {
            int row_index = csc->IA[k];  
            matrix[row_index][j] = csc->A[k];
        }
    }
    
    *n = n_mat;
    *m = m_mat;

    return matrix;
}

int *vecconvert_toarr(size_t *n, vec_t *vector)
{
    if (!vector)
        return NULL;

    int index = 0;

    int *p = malloc(sizeof(int) * vector->vec_len);

    if (!p)
        return NULL;

    for (int i = 0; i < vector->vec_len; i++)
    {
        if (index < vector->numNonZero && i == vector->JB[index])
        {
            p[i] = vector->B[index];
            index++;
        }
        else
            p[i] = 0;
    }

    *n = vector->vec_len;

    return p;
}

vec_t *convert_from_arr(int *vec, size_t const n)
{   
    if (!vec)
        return NULL;

    int non_zero_count = 0;

    for (size_t i = 0; i < n; i++)
        if (vec[i] != 0)
            non_zero_count++;

    int *pB = malloc(sizeof(int) * non_zero_count);

    int *pJB = malloc(sizeof(int) * non_zero_count);
    
    size_t index = 0;
    for (size_t i = 0; i < n && (int) index < non_zero_count; i++)
    {
        if (vec[i] != 0)
        {
            pB[index] = vec[i];
            
            pJB[index] = i;
            index++;
        }
    }

    vec_t *vector = create_vector(pB, pJB, non_zero_count, n);

    for (size_t i = 0; i < (size_t) non_zero_count; i++)
        vector->JB[i] = pJB[i];

    return vector;
}