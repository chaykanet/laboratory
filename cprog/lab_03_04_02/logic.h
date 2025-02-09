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
#define FINDED 4
#define NOT_FINDED 6
#define DIV_BY_TEN 10
#define FIVE 5

/*  Возвращает true, если число оканчивается на 5,
    иначе false
    Функция принимает число num.
*/
bool is_end_five(int const num);

/*  Функция находит максимальный элемент, оканчивающийся на 5 под побочной диагональю
    Возвращет максимальны элемент и код шибки нахождения.
    Функция принимает квадратную матрицу mat, ее размер n, адрес переменной max.
*/
int find_max_un_sec_diagonal(int (*mat)[M], size_t const n, int *max);

#endif
