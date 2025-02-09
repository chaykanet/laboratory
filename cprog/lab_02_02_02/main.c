#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#define ERR_OK 0
#define ERR_IO 1
#define CORR_IN 1
#define ERR_RANGE 3
#define ERR_EMPTY 2
#define N 10
#define DIV_BY_TEN 10

/* Функция принимает код ошибки.
   Затем определяет ошибку и выводит сообщение о ней*/
void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Incorrect input\n");
    else if (rc == ERR_EMPTY)
        printf("New array is empty\n");
    else
        printf("Unknown error\n");
}

/*  Функция выводит массив на экран.
    Функция принимает массив и его длину.*/
void print_array(size_t const n, const int *arr)
{
    printf("Your new array: ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/*  Функция возвращает истину, если число имеет одинаковые начальные и конечные цифры,
    иначе ложь.
    Функция принимает число.*/
bool is_num(int const num)
{
    int tmp = num;
    
    if (tmp < 0)
        tmp = abs(tmp);

    int start = tmp % DIV_BY_TEN, end = start;

    if (tmp >= DIV_BY_TEN)
    {
        tmp /= DIV_BY_TEN;

        while (tmp > 0)
        {   
            end = tmp % DIV_BY_TEN;
            tmp /= DIV_BY_TEN;
        }
    }
    
    if (end == start)
        return true;
    else
        return false;
}

/*  Функция вызывает функцию is_num, фильтрует массив, 
    числа, у которых одинаковые начальные и конечные цифры, добавляет в новый массив.
    Возвращает новый массив, код ошибки и его длину.
    Функция принимает массив его длину, новый массив и его длину.*/
void new_array(int const *arr, size_t const n, int *new_arr, size_t *size)
{   
    *size = 0;

    for (size_t i = 0; i < n; i++)
        if (is_num(arr[i]))
        {
            new_arr[*size] = arr[i];
            *size += 1;
        }  
}

/*  Функция заполняет массив элементами до нужного размера.
    Возвращает массив и код ошибки.
    Функция принимает массив и его длину.*/
int input_arr(int *arr, size_t const n)
{   
    printf("Enter your numbers: \n");
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != CORR_IN)
            return ERR_IO;
    }

    return ERR_OK;
}

int main(void)
{
    int n, rc;

    printf("Enter your n: ");
    rc = scanf("%d", &n);

    if (rc != CORR_IN)
    {
        printf("Incorrect input\n");
        return ERR_IO;
    }

    if (n <= 0 || n > N)
    {
        printf("Out of range\n");
        return ERR_RANGE;
    }

    int arr[N];
    int new_arr[N];

    size_t a_n = (size_t) n;
    size_t size;

    rc = input_arr(arr, a_n);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    new_array(arr, a_n, new_arr, &size);

    if (size == 0)
    {
        print_err(ERR_EMPTY);
        return ERR_EMPTY;
    }

    print_array(size, new_arr);
    return ERR_OK;
}
