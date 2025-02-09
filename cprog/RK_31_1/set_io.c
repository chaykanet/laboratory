#include "set_io.h"

int input_arr(int *arr, const size_t n)
{   
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return ERR_IO;

    return ERR_OK;
}

// int input_set(int *set, size_t *set_n, size_t const n)
// {   
//     bool is_find = false;

//     size_t c = 0;

//     size_t index = 0;

//     for (size_t i = 0; i < n; i++)
//     {
//         is_find = false;
//         int tmp;

//         if (scanf("%d", &tmp) != 1)
//             return ERR_IO;

//         for (size_t j = 0; j < index; j++)
//             if (set[j] == tmp)
//             {
//                 is_find = true;
//             }

//         if (!is_find)
//         {   
//             set[c] = tmp;
//             index++;
//             c++;
//         }
//     }

//     *set_n = c; 

//     return ERR_OK;
// }

void print_set(int *set, const size_t n)
{   
    printf("Set:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", set[i]);

    printf("\n");
}
