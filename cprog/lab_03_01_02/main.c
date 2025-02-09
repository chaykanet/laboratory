#include <stdio.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"
#include "logic.h"

int main(void)
{
    int rc;
    size_t n, m;
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
 
    int arr[M];
    size_t a_n;

    new_array(arr, &a_n, mat, n, m);

    print_arr(arr, a_n);
        
    return ERR_OK;
}
