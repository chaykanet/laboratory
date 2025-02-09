#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"
#include "logic.h"

int main(void)
{
    int n, m;
    int rc;
    int mat[N][M];
    int max;

    rc = input_sizes_mat(&n, &m);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    if (n < 1 || n > N || m < 1 || m > M)
    {
        print_err(ERR_RANGE);
        return ERR_RANGE;
    }

    if (n != m)
    {
        print_err(ERR_PARAM);
        return ERR_PARAM;
    }

    rc = input_matrix(mat, n, m);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    size_t mat_n = n;

    rc = find_max_un_sec_diagonal(mat, mat_n, &max);
    
    if (rc != FINDED)
    {
        print_err(ERR_FINDED);
        return ERR_FINDED;
    }

    printf("Your max: %d\n", max);

    return ERR_OK;
}
