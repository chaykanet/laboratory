#include "set.h"
#include "set_io.h"
#include "set_op.h"

int main(void)
{
    int rc = ERR_OK;
    size_t a_n, b_n;

    size_t a, b, in; // фактические размеры (без повторных чисел)

    int tmp1, tmp2;
    
    int *arr_a = NULL, *arr_b = NULL;
    int *set_a = NULL, *set_b = NULL, *set_in = NULL;

    if (scanf("%d", &tmp1) != 1 || tmp1 < 0)
        return ERR_IO;

    a_n = tmp1;
    
    arr_a = create(a_n);

    if (!arr_a && a_n != 0)
        return ERR_ALLOC;
    
    // rc = input_arr(set_a, &a, a_n);

    if (rc == ERR_OK)
        rc = input_arr(arr_a, a_n);

    if (rc == ERR_OK)
        rc = to_set(&set_a, &a, arr_a, a_n);
    
    if (rc == ERR_OK)
    {
        if (scanf("%d", &tmp2) != 1 || tmp2 < 0)
            rc = ERR_IO;

        if (rc == ERR_OK)
        {
            b_n = tmp2;

            arr_b = create(b_n);

            if (!arr_b && b_n != 0)
                rc = ERR_ALLOC;

            if (rc == ERR_OK)
                rc = input_arr(arr_b, b_n);

            if (rc == ERR_OK)
                rc = to_set(&set_b, &b, arr_b, b_n);
        }
    }

    if (rc == ERR_OK)
        rc = intersec(&set_in, &in, set_a, a, set_b, b);

    if (rc == ERR_OK)
    {
        print_set(set_a, a);
        print_set(set_b, b);
        print_set(set_in, in);     
    }

    if (arr_a)
        free(arr_a);

    if (arr_b)
        free(arr_b);

    if (set_a)
        free_set(set_a);
    if (set_b)
        free_set(set_b);

    if (set_in)
        free_set(set_in);

    return rc;
}