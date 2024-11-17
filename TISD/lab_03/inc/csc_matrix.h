#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include "errcodes.h"

typedef struct sparse_matrix // Разряженная матрица.
{
    int *A;

    int *IA;

    int *JA;

    int numNonZero;

    int row_len;

    int num_rows;

} sparseMatrix_t;

typedef struct vector // Структура для вектора строки.
{
    int *B;

    int *JB;

    int numNonZero;

    int vec_len;

} vec_t;

void free_matrix(int **matrix);

void free_vector(vec_t *vector);

void freeSparseMatrix(sparseMatrix_t *matrix);

int **create_matrix(size_t const n, size_t const m);

int init_sparseMatrix(sparseMatrix_t *csc, int **matrix, int none_zero_count, int num_rows, int row_len);

int init_vector(vec_t *vector, int *values, int *indexes, int none_zero_count, int vec_len);

sparseMatrix_t *create_sparseMatrix(int **matrix, int num_rows, int row_len);

vec_t *create_vector(int *values, int *indexes, int none_zero_count, int vec_len);

#endif
