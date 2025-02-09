#ifndef CHECK_COMPARATORS_H
#define CHECK_COMPARATORS_H

#include <math.h>
#include <stddef.h>

#include "errcodes.h"

#define EPS 1e-7

/*  Функция сравнивает вещественные элементы массивов.
    Функция принимает массивы arr_l и arr_r и их размеры nmemb.
    Возвращает код ошибки.
*/
int compare_arr(const double *arr_l, const double *arr_r, const size_t nmemb);

/*  Функция сравнивает размеры и элементы матриц.
    Функция принимает матрицы mat_l ее размеры n_l, m_l, mat_r ее размеры n_r, m_r.
    Возвращает код ошибки.
*/
int compare_mat(double **mat_l, const size_t n_l, const size_t m_l, double **mat_r, const size_t n_r, const size_t m_r);

#endif
