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

/*  Функция сверяет число на числа в массиве.
    Функция возвращает true, если число уникальное, иначе false.
    Функция принимает адреса на начало и конец массива qbeg, qend, само число num.
*/
bool is_uniq(int *const qbeg, int *const qend, int const num)
{   
    if (qbeg == qend)
        return true;

    bool uniq = true;

    int *px = qbeg;

    while (px != qend && uniq)
    {
        if (*px == num)
            uniq = false;
        px++;
    }

    return uniq;
}

/*  Функция считает кол-во уникальных чисел в массиве.
    Функция принимает адреса на начало и конец массива pbeg, pend.
*/
int calc_uniq(int *const pbeg, int *const pend)
{   
    size_t n = 0;
    
    for (int *pcur = pbeg; pcur != pend; pcur++)
    {   
        if (is_uniq(pbeg, pcur, *pcur))
            n++;
    }

    return n;
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
    int rc, n;

    size_t uniq_num = 0;

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

    uniq_num = calc_uniq(pa, pe);

    printf("Your uniq_num: %zu\n", uniq_num);

    return ERR_OK;
}
