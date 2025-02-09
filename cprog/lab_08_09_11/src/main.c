#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "matrix_io.h"
#include "errcodes.h"
#include "matrix_operations.h"


#define ACTION_A 1
#define ACTION_M 2
#define ACTION_O 3
#define ACTION_NONE 4

int main(int argc, char **argv)
{   
    int action;
    
    if (argc == MAX_NUM_ARGUMENTS && strcmp(argv[1], "a") == 0)
        action = ACTION_A;
    else if (argc == MAX_NUM_ARGUMENTS && strcmp(argv[1], "m") == 0)
        action = ACTION_M;
    else if (argc == MAX_NUM_ARGUMENTS - 1 && strcmp(argv[1], "o") == 0)
        action = ACTION_O;
    else
        return ERR_ARG;

    int rc = ERR_OK;

    FILE *file_f = NULL, *file_s = NULL;
    FILE *fileout = NULL;

    double **matrix = NULL;
    double **matrix_f = NULL;
    double **matrix_s = NULL;
    size_t n = 0, m = 0, n_f = 0, m_f = 0, n_s = 0, m_s = 0;

    double **vector = NULL;
    size_t vec_n = 0;

    file_f = fopen(argv[2], "r");
    
    if (action == ACTION_A || action == ACTION_M)
        file_s = fopen(argv[3], "r");

    if (action == ACTION_O && !file_f)
        rc = ERR_FILE;

    if (action != ACTION_O && (!file_f || !file_s))
        rc = ERR_FILE;
    
    if (rc == ERR_OK)
        rc = get_matrix(file_f, &matrix_f, &n_f, &m_f);

    if (rc == ERR_OK && (action == ACTION_A || action == ACTION_M))
        rc = get_matrix(file_s, &matrix_s, &n_s, &m_s);
        
    if (rc == ERR_OK && action == ACTION_A)
    {   
        if (rc == ERR_OK)
            rc = sum_matrix(matrix_f, n_f, m_f, matrix_s, n_s, m_s, &matrix, &n, &m);

        if (rc == ERR_OK)
        {
            fileout = fopen(argv[4], "w");
            if (!fileout)
                rc = ERR_FILE;
        }

        if (rc == ERR_OK)
            rc = fprint_matrix(fileout, matrix, n, m);
    }

    if (rc == ERR_OK && action == ACTION_M)
    {   
        if (m_f != n_s)
            rc = ERR_RANGE;

        if (rc == ERR_OK)
            rc = multy_matrix(matrix_f, n_f, m_f, matrix_s, n_s, m_s, &matrix, &n, &m);

        if (rc == ERR_OK)
        {
            fileout = fopen(argv[4], "w");
            if (!fileout)
                rc = ERR_FILE;
        }
        
        if (rc == ERR_OK)
            rc = fprint_matrix(fileout, matrix, n, m);
    }

    if (rc == ERR_OK && action == ACTION_O)
    {
        if (rc == ERR_OK)
        {    
            vec_n = m_f - 1;

            if (vec_n == 0)
                rc = ERR_RANGE;

            if (rc == ERR_OK)
                vector = create_matrix(vec_n, 1);
            
            if (!vector)
                rc = ERR_ALLOC;
    
            if (rc == ERR_OK)
                rc = solve_sle_gauss(vector, vec_n, matrix_f, n_f, m_f);
        }
    
        if (rc == ERR_OK)
        {
            fileout = fopen(argv[3], "w");

            if (!fileout)
                rc = ERR_FILE;

            if (rc == ERR_OK)
                rc = fprint_matrix(fileout, vector, vec_n, 1);
        }
    }
    
    if (matrix)
        free_matrix(matrix, n);
    if (matrix_f)
        free_matrix(matrix_f, n_f);
    if (matrix_s)
        free_matrix(matrix_s, n_s);
    if (vector)
        free_matrix(vector, vec_n);

    if (file_f)
        fclose(file_f);
    if (file_s)
        fclose(file_s);
    if (fileout)
        fclose(fileout);

    return rc;
}
