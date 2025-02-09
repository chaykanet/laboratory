#include <stdio.h>
#include "logic.h"

int main(void)
{
    int n, m;
    int rc;
    int mat[N][M];

    printf("Enter your n, m: ");

    rc = input_sizes_mat(&n, &m);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    if (n <= 0 || n > N || m < 1 || m > M)
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

    int arr[Z];
    size_t a_n;

    take_from_mat(mat, n, m, arr, &a_n);
    
    if (a_n == 0)
    {
        print_err(ERR_EMPTY);
        return ERR_EMPTY;        
    }

    reverse_arr(arr, a_n);
    
    rc = back_to_mat(mat, n, m, arr, a_n);

    if (rc != ERR_OK)
    {
        print_err(ERR_BACK);
        return ERR_BACK; 
    }
    
    print_matrix(mat, n, m);

    return ERR_OK;
}
