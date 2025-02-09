#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include "matrix.h"
#include "my_limits.h"
#include "errcodes.h"

#define EPS 1e-7

/*  Функция вычетает из первого массива соответствующие элементы второго, домножая их на коэффицент ведущего элемента.  
    Функция принимает массивы from_row, row и их длину len, индекс (позиция ведущего элемента) с которого начинаются вычитания элементов.
*/
void sub_rows(double *from_row, double *row, const size_t len, const size_t index);

/*  Функция приводит матрицу к ступенчатому виду с помощью ведущего элемента по столбцу.
    Для j-го (j=i) столбца находится элемент наибольший по модулю, после строка, содержащая этот элемент, переходит в i индекс.
    Затем к строкам с i+1 по n прибовляют i-ю строку, домноженную на коэффицент, чтобы элементы j-го столбца обнулялись. 
    В результате выполнения алгоритма получается ступенчатая матрица.
    Функция принимает матрицу matrix и ее размер n, m.
*/
void bring_mat_to_step(double **matrix, const size_t n, const size_t m);

/*  Функция осуществляет решение СЛАУ для матрицы nxn+1 методом гаусса с ведущим элементом по столбцу.
    Функция принимает указатель на вектор результата vector, его длину vec_n, матрицу matrix и ее размеры n, m.
    Возвращает код ошибки. 
*/
int solve_sle_gauss(double **vector, const size_t vec_n, double **matrix, const size_t n, const size_t m);

/*  Функция осуществляет сложение двух матриц. 
    Складывает соответствующие элементы и сохраняет их в matrix_dst.
    Функция принимает матрицы matrix_a и matrix_b их размеры n_a, m_a и n_b, m_b, указатели на матрицу matrix_dst и размерности n_dst, m_dst.
*/
int sum_matrix(double **matrix_a, const size_t n_a, const size_t m_a, double **matrix_b, const size_t n_b, const size_t m_b, double ***matrix_dst, size_t *n_dst, size_t *m_dst);

/*  Функция осуществляет перемножения матриц.
    Результат перемножения матриц сохраняет в созданной матрице matrix.
    Функция принимает матрицы matrix_f, matrix_s и их размеры n_f, m_f и n_s, m_s, указатели на матрицу matrix и на ее размеры n, m.
    Возвращает код ошибки.
*/
int multy_matrix(double **matrix_f, const size_t n_f, const size_t m_f, double **matrix_s, const size_t n_s, const size_t m_s, double ***matrix, size_t *n, size_t *m);

/*  Функция находит для ступенчатой матрицы (nxm, m=n+1) значения координат вектора.
    Начиная с i-ой (i=n-1) строки по 0-ю находится соответствующая j-я (j=n-1, n=m-1) координата вектора.
    Функция принимает вектор (матрица nx1) vector, его длину vec_n, ступенчатую матрицу step_matrix, ее размеры n, m.
    Функция не проверяет правильность переданных аргументов.
*/
void find_vector(double **vector, const size_t vec_n, double **step_matrix, const size_t n, const size_t m);

#endif
