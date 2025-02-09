#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include <stdio.h>

#include "matrix.h"
#include "errcodes.h"

/*  Функция осуществляет считывание элементов матрицы из файла.
    Функция принимает файловую переменную file, матрицу matrix и ее размеры n, m.
*/
int read_matrix(FILE *file, double **matrix, const size_t n, const size_t m);

/*  Функция получает из файла матрицу.
    Функция принимает файловую переменную file, указатели на матрицу matrix и ее размеры n, m.
    Возвращает код ошибки.
*/
int get_matrix(FILE *file, double ***matrix, size_t *n, size_t *m); 

/*  Функция записывает матрицу в файл.
    Функция принимает матрицу matrix и ее размеры n, m.
    Возвращает код ошибки.
*/
int fprint_matrix(FILE *file, double **matrix, const size_t n, const size_t m);

#endif
