#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

int main(void)
{
    int n, m, rc;
    int mat[N][M];

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

    input_step_bull(mat, n, m);

    print_matrix(mat, n, m);

    return ERR_OK;
}
