#ifndef CHECK_SOLVE_SLE_H
#define CHECK_SOLVE_SLE_H

#include <check.h>
#include "errcodes.h"
#include "matrix_operations.h"

/* Набор тестов для функции solve_sle_gauss.
*/
Suite *solve_sle_gauss_suite(void);

/* Функция возвращает результат тестирования функции solve_sle_gauss.
*/
int sle_result(void);

/* Набор тестов для функции sub_rows.
*/
Suite *sub_rows_suite(void);

/* Функция возвращает результат тестирования функции sub_rows.
*/
int sub_rows_result(void);

/* Набор тестов для функции find_vector.
*/
Suite *find_vector_suite(void);

/* Функция возвращает результат тестирования функции find_vector.
*/
int find_vector_result(void);

#endif
