#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "errcodes.h"
#include "csc_matrix.h"
#include "csc_operations.h"
#include "matrix_io.h"

int main(int argc, char **argv)
{
    int rc = ERR_OK;
    FILE *f = fopen(argv[1], "r");

    sparseMatrix_t *csc;
    vec_t *vector = malloc(sizeof(vec_t));

    int size = atoi(argv[3]);
    int tmp1, tmp2;
    int **matrix = create_matrix(size, size);

    if (fscanf(f, "%d %d", &tmp1, &tmp2) != 2)
        return ERR_IO;

    rc = read_matrix(f, matrix, size, size);

    if (!matrix)
        return ERR_IO;

    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        arr[i] = 1;

    int *indexes = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        indexes[i] = i;
    
    vector->B = arr;
    vector->JB = indexes;
    vector->vec_len = size;
    vector->numNonZero = size;

    double time = 0, st, end;

    FILE *out = fopen(argv[2], "a");

    if (strcmp(argv[4], "mat") == 0)
    {   
        size_t vec_n;
        int *vec = vecconvert_toarr(&vec_n, vector);

        size_t res_len;

        st = clock();
        int *res = multvec_mat(&res_len, matrix, size, size, vec, vec_n);
        end = clock();

        time = (double) (end - st) / CLOCKS_PER_SEC * 1000;

        fprintf(out, "%lf ", time);

        free(res);
    }
    else if (strcmp(argv[4], "csc") == 0)
    {   
        size_t res_len;
        csc = matconvert_tocsc(matrix, size, size);
        
        st = clock();
        int *res = multvec_csc(&res_len, csc, vector);
        end = clock();

        time = (double) (end - st) / CLOCKS_PER_SEC * 1000;

        fprintf(out, "%lf ", time);

        free(res);
    }
    else if (strcmp(argv[4], "v") == 0)
    {   
        size_t res_len;
        csc = matconvert_tocsc(matrix, size, size);
        size_t valume = sizeof(sparseMatrix_t) + sizeof(int) * csc->numNonZero * 2 + sizeof(int) * (csc->row_len + 1);

        fprintf(out, "%lu ", valume);
    }
    else
        rc = ERR_IO;

    fclose(f);
    fclose(out);

    freeSparseMatrix(csc);

    free_matrix(matrix);

    free_vector(vector);

    return rc;
}
