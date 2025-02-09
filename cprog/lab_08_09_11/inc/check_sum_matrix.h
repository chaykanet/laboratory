#ifndef CHECK_SUM_MATRIX
#define CHECK_SUM_MATRIX

#include <check.h>
#include "errcodes.h"
#include "matrix_operations.h"

/* Набор тестов для функции sum_matrix.
*/
Suite *sum_matrix_suite(void);

/* Функция возвращает результат тестирования функции sum_matrix.
*/
int sum_matrix_result(void);

#endif
