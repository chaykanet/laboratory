#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define ERR_OK 0
#define ERR_IO 1
#define CORR_IN 1
#define ERR_RANGE 3
#define N 10
#define EMPTY 2
#define ERR_FIND 4

/*  Функция принимает код ошибки.
    Затем определяет ошибку и выводит сообщение о ней*/
void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Incorrect input\n");
    else if (rc == EMPTY)
        printf("Array is empty\n");
    else if (rc == ERR_FIND)
        printf("Not finded\n");
    else
        printf("Unknown error\n");
}

/*  Функция находит минимальное произведение двух соседних элементов.
    Возвращает минимальное произведение, код ошибки.
    Функция принимает адреса начала и конца массива*/
int find_min(int *const pa, int *const pe, int *min)
{   
    if (pa == pe - 1)
        return ERR_FIND;
    
    int *px = pa;
    int *it = px + 1;

    *min = *it * *px;

    while (it != pe)
    {   
        if (*it * *px < *min)
            *min = *it * *px;

        ++px;
        ++it;
    }

    return ERR_OK;
}

/*  Функция заполняет массив до конца массива.
    Возвращает заполненный массив, код ошибкию.
    Функция принимает адреса начала и конеца массива*/
int input_arr(int *pa, int *pe)
{   
    for (int *it = pa; it != pe; it++)
    {
        printf("Enter your number: ");
        if (scanf("%d", it) != CORR_IN)
            return ERR_IO;
    }

    return ERR_OK;
}

int main(void)
{
    int rc, min, n;

    int arr[N];

    int *pa = arr;

    printf("Enter your n: ");
    
    rc = scanf("%d", &n);

    if (rc != CORR_IN)
    {
        printf("Incorrect input\n");
        return ERR_IO;
    }

    if (n < 0 || n > N)
    {
        printf("Out of range");
        return ERR_RANGE;
    }

    int *pe = arr + n;

    if (pa == pe)
    {
        printf("Array is empty\n");
        return EMPTY;
    }

    rc = input_arr(pa, pe);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    rc = find_min(pa, pe, &min);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    printf("Your min: %d\n", min);

    return ERR_OK;
}
