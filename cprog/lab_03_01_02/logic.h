// Заголовочный файл содержит объявления функций и мнемонические имена логики необходимой для решения задачи

#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"

#define ONE 1
#define ZERO 0

/*  Возвращает true, если знаки элементов столбца чередуются,
    иначе false.
    Функция принимает указатель на начало столбца, длину столбца n.
*/
bool find_column(int const *p, size_t const n);

/*  Заполняет i-ый элемент массива 1, если в i-строке знаки элементов чередуются,
    иначе заполняет нулем.
    Функция принимает одномерный массив arr, его размер a_n, матрицу, кол-во строк n, кол-во столбцов m.
*/
void new_array(int *arr, size_t *a_n, int (*mat)[M], size_t const n, size_t const m);

#endif
