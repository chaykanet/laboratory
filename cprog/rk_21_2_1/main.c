#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define N 15


void sort_arr(int *arr, size_t const a_n)
{   
    if (a_n <= 2)
        return;

    int ost = 0;
    if (a_n % 2 == 0)
        ost = 1;
    
    for (size_t i = 0; i < a_n; i += 2)
        for (size_t j = 0; j < a_n - i - 1 - ost; j += 2)
            if (arr[j] > arr[j + 2])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = tmp;
            }
}

int input_arr(int *arr, size_t *a_n)
{   
    printf("Your array: ");
    for (size_t i = 0; i < *a_n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
            return ERR_IO;
    } 

    return ERR_OK;
}

void print_arr(int const *arr, size_t const a_n)
{
    for (size_t i = 0; i < a_n; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int arr[N];
    int n, rc;

    printf("Your num of el: ");

    rc = scanf("%d", &n);

    if (rc != 1)
        return ERR_IO;

    if (n <= 0 || n > N)
        return ERR_RANGE;
    
    size_t a_n = (size_t) n;

    rc = input_arr(arr, &a_n);

    if (rc != ERR_OK)
        return ERR_IO;

    sort_arr(arr, a_n);

    print_arr(arr, a_n);
    
    return ERR_OK;
}