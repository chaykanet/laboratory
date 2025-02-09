// Заголовочный файл содержит объявления функций и мнемонические имена логики необходимой для решения задачи

#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"

#define CORR_IN_ONE 1
#define DIV_BY_TEN 10
#define NOT_FIND -1
#define DIV_BY_TWO 2
#define TWO_ELEMENTS 2

/*  Находит сумму цифр этого числа.
    Возвращает эту сумму.
    Функция принимает число num.
*/
int find_digit_sum(int const num);

/*  Функция подсчитывает кол-во чисел, сумма цифр которых нечетна.
    Возвращает кол-во чисел.
    Функция принимает одномерный массив row, его размер m.
*/
size_t calc_needed_num(int const *row, size_t const m);

/*  Добавлет в матрицу строку из -1.
    Функция принимает матрицу mat, индекс строки m_n, размер строки m, индекс строки index.
*/
void insert_row(int (*mat)[M], size_t *m_n, size_t const m, int *row, size_t const index);

/*  Формирует новую матрицу. Добавлет строку из -1, если
    в последующей строке есть 2 элемента, сумма цифр которых нечетна.
    Возвращает новую матрицу, ее кол-во строк, ее кол-во столбцов.
    Функция принимает новую матрицу, ее кол-во строк, ее кол-во столбцов,
    матрицу mat, ее кол-во строк n, ее кол-во столбцов m.
*/
void add_neg_row_matrix(int (*mat)[M], size_t *n, size_t const m);

/*  Функция присваивает элементы одного массива другому.
    Функция принимает два массива arr1, arr2 и их размер m.
*/
void assign_arr(int *arr1, int const *arr2, size_t m);

#endif
