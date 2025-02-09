#include "matrix_io.h"

int read_matrix(FILE *file, double **matrix, const size_t n, const size_t m)
{   
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (fscanf(file, "%lf", &matrix[i][j]) != 1)
                return ERR_IO;
    
    double tmp;

    if (fscanf(file, "%lf", &tmp) == 1)
        return ERR_IO;

    return ERR_OK;
}

int fprint_matrix(FILE *file, double **matrix, const size_t n, const size_t m)
{
    if (!fprintf(file, "%zu %zu\n", n, m))
        return ERR_IO;

    for (size_t i = 0; i < n; i++)
    {    
        for (size_t j = 0; j < m; j++)
            if (!fprintf(file, "%lf ", matrix[i][j]))
                return ERR_IO;

        if (!fprintf(file, "\n"))
            return ERR_IO;
    }

    return ERR_OK;
}

int get_matrix(FILE *file, double ***matrix, size_t *n, size_t *m)
{   
    int rc = ERR_OK;

    int n_t = 0, m_t = 0;

    double **ptrs = NULL;

    if (fscanf(file, "%d %d", &n_t, &m_t) != 2 || n_t <= 0 || m_t <= 0)
        rc = ERR_IO;

    if (rc == ERR_OK)
    {   
        ptrs = create_matrix(n_t, m_t);

        if (ptrs)
            rc = read_matrix(file, ptrs, n_t, m_t);

        if (!ptrs)
            rc = ERR_ALLOC;
    }

    if (rc == ERR_OK)
    {
        *matrix = ptrs;
        *n = n_t;
        *m = m_t;
    }
    else if (ptrs)
        free_matrix(ptrs, n_t);
    
    return rc;
}