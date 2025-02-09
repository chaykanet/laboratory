// Заголовочный файл содержит объявления функций и мнемонические имена логики необходимых для решения задачи

#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"

#define CORR_IN_TWO 2
#define DIV_BY_TWO 2
#define ONE 1
#define TWO 2
#define Z (M * N)

/*  Функция возвращает элементы из массива обратно в матрицу.
    Возвращает матррицу.    
    Функция принимает матрицу mat, кол-во строк n, кол-во столбцов m, массив arr, его размер a_n.
    Возвращает код ошибки.
*/
int back_to_mat(int (*mat)[M], size_t const n, size_t const m, int const *arr, size_t const a_n);

/*  Функция принимает две целые переменные num1, num2.
    Меняет их значения местами.
*/
void swap(int *num1, int *num2);

/*  Разворачивает массив и возвращает его.
    Функция принимает массив arr, его размер a_n.
*/
void reverse_arr(int *arr, size_t const a_n);

/*  Возвращает true, если число простое,
    иначе false.
    Функция принимает число n.
*/
bool is_simple(int const n);

/*  Функция берет из матрицы простые элементы и заполнят ими массив.
    Возвращает полученный массив.
    Функция принимает матрицу mat, кол-во строк n, кол-во столбцов m, массив arr, его размер a_n.
*/
void take_from_mat(int (*mat)[M], size_t const n, size_t const m, int *arr, size_t *a_n);

#endif
