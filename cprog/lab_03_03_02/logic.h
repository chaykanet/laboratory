// Заголовочный файл содержит объявления функций и мнемонические имена логики необходимой для решения задачи

#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"

#define CORR_IN_TWO 2

/*  Меняет элементы строк местами.
    Возвращет полученные строки.
    Функция принимает строки матрицы row1, row2, их размер m.
*/
void swap(int *row1, int *row2, size_t const m);

/*  Находит произведение элементов массива и возвращет это произведение.
    Функция принимает одномерный массив, его размер m.
*/
int multy_arr(int const *arr, size_t const m);

/*  Сортирует строки по возрастанию произведения их элементов.
    Возвращает полученную матрицу.
    Функция принимает матрицу, ее кол-во строк, ее кол-во столбцов.
*/
void sort_matrix(int (*mat)[M], size_t n, size_t m);

#endif
