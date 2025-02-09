#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "errcodes.h"

/*  Функция освобождает матрицу, предстаавленную в виде целого блока.
    Функция принимает матрицу matrix.
*/
void free_matrix(double **matrix, const size_t n);

/*  Функция осуществляет выделения памяти под матрицу.
    Функция принимает ее размеры n и m.
    Возвращает указатель на матрицу.
*/
double **create_matrix(const size_t n, const size_t m);

#endif
