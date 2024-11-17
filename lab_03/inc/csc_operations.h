#ifndef CSC_OPERATIONS_H
#define CSC_OPERATIONS_H

#include <stdbool.h>
#include "csc_matrix.h" 

int *vecconvert_toarr(size_t *n, vec_t *vector);

vec_t *convert_from_arr(int *vec, size_t const n);

sparseMatrix_t *matconvert_tocsc(int **matrix, size_t const n, size_t const m);

int **csc_convert_tomat(size_t *n, size_t *m, sparseMatrix_t *csc);

int *multvec_csc(size_t *res_len, sparseMatrix_t *matrix, vec_t *vector);

int *multvec_mat(size_t *res_len, int **matrix, size_t const n, size_t const m, int *vector, size_t const n_v);

#endif
