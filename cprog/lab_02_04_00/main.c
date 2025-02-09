#include <stdio.h>
#include <stddef.h>

#define ERR_OK 0
#define ERR_IO 1
#define CORR_IN 1
#define ERR_RANGE 100
#define N 10
#define EMPTY 2

/*  Функция принимает массив и его длину.
    Выводит массив на экран.*/
void print_array(size_t const n, int const *arr)
{
    printf("Your new array: ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/*  Функция принимает два элемента и меняет их местами.*/
void swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

/*  Функция возвращает отсортированный по возрастанию массив.
    Функция принимает массив и его длину, сортирует его пузырьком. */
void sort_by_bubble(int *arr, size_t const a_n)
{
    for (size_t i = a_n - 1; i != 0; i--)
        for (size_t j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
}

/*  Функция принимает массив по концевому признаку.
    Возвращает массив, его длину и код ошибки.*/
int input_array(int *arr, size_t *a_n)
{       
    *a_n = 0;
    int tmp;

    printf("Input your element: ");

    while (scanf("%d", &tmp) == CORR_IN)
    {   
        if (*a_n < N)
        {   
            arr[*a_n] = tmp;
            *a_n += 1;
        }
        else
            return ERR_RANGE;

        printf("Input your element: ");
    }

    if (*a_n == 0)
        return EMPTY;

    return ERR_OK;
}

int main(void)
{
    int rc;
    size_t a_n;

    int arr[N];

    rc = input_array(arr, &a_n);

    if (rc != ERR_OK && rc != ERR_RANGE)
    {
        printf("Array is empty\n");
        return EMPTY;
    }
        
    sort_by_bubble(arr, a_n);

    print_array(a_n, arr);
    
    return rc;
}
