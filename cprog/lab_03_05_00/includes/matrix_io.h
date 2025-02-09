/* Заголовочный файл содержит функции, предназначенные для ввода/вывода матриц, массивов и сообщений об ошибках*/
#ifndef H_MATRIX_IO

#include <stdio.h>
#include <stddef.h>
#include "matrix_limits.h"
#include "errcodes.h"

#define CORR_IN 1

/*  Функция принимает пустую матрицу, кол-во строк, кол-во столбцов.
    Осуществляет заполнение матрицы.
    Возвращает матрицу и код ошибки выполнения функции.
*/
int input_matrix(int (*mat)[M], size_t const n, size_t const m);

/*  Функция принимает матрицу, кол-во строк, кол-во столбцов.
    Осуществляет вывод матрицы на экран.
*/
void print_matrix(int (*mat)[M], size_t const n, size_t const m);

/*  Функция принимает массив, размер массива.
    Осуществляет вывод массива на экран.
*/
void print_arr(int const *arr, size_t const n);

/*  Функция принимает код ошибки.
    Осуществляет вывод сообщение об ошибке.
*/
void print_err(int const rc);

int input_matrix(int (*mat)[M], size_t const n, size_t const m)
{
    printf("Enter elements of matrix: ");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &mat[i][j]) != CORR_IN)
                return ERR_IO;

    return ERR_OK;
}

void print_matrix(int (*mat)[M], size_t const n, size_t const m)
{
    printf("Your matrix:\n");

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void print_arr(int const *arr, size_t const n)
{
    printf("Your array: ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Error: Incorrect input");
    
    if (rc == ERR_EMPTY)
        printf("Error: Empty");
    
    if (rc == ERR_RANGE)
        printf("Error: Out of range");
}

#endif
