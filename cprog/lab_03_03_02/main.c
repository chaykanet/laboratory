#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"
#include "logic.h"

int main(void)
{
    int rc;
    int n, m;
    int mat[N][M];

    printf("Enter your n, m: ");

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

    rc = input_matrix(mat, n, m);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }
 
    size_t mat_n = n;
    size_t mat_m = m;

    sort_matrix(mat, mat_n, mat_m);

    print_matrix(mat, mat_n, mat_m);

    return ERR_OK;
}
