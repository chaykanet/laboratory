/* Заголовочный файл содержит объявления функции, предназначенные для ввода/вывода матриц, массивов и сообщений об ошибках*/
#ifndef H_MATRIX_IO
#define H_MATRIX_IO

#include <stdio.h>
#include <stddef.h>
#include "matrix_limits.h"
#include "errcodes.h"

#define CORR_IN 1
#define CORR_IN_TWO 2

/*  Осуществляет заполнение матрицы.
    Возвращает матрицу и код ошибки выполнения функции.
    Функция принимает пустую матрицу mat, кол-во строк n, кол-во столбцов m.
*/
int input_matrix(int (*mat)[M], size_t const n, size_t const m);

/*  Функция осуществялет ввод размеров матрицы.
    Функция возвращает кол-во строк n, кол-во столбцов m.
*/
int input_sizes_mat(size_t *n, size_t *m);

/*  Осуществляет вывод массива на экран.
    Функция принимает массив arr, кол-во строк n, кол-во столбцов m.
*/
void print_arr(int const *arr, size_t const n);


#endif
