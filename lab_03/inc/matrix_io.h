#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include <stdio.h>
#include "csc_matrix.h"
#include "errcodes.h"

void print_vector(vec_t *vector);

void print_csc(sparseMatrix_t *csc);

void print_result(vec_t *vec);
// void print_csc_matrix(sparseMatrix_t *matrix);

void print_matrix(int **matrix, size_t const n, size_t const m);

int input_vector(vec_t **vector);

int fget_vector(char *filename, vec_t **vector);

int input_csc_matrix(sparseMatrix_t *matrix);

int input_matrix_xy(int **matrix, size_t const n, size_t const m);

int input_matrix(int **matrix, size_t const n, size_t const m);

int read_matrix(FILE *file, int **matrix, size_t const n, size_t const m);

#endif
