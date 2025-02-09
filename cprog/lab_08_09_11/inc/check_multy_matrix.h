#ifndef CHECK_MULTY_MATRIX_H
#define CHECK_MULTY_MATRIX_H

#include <check.h>
#include "errcodes.h"
#include "matrix_operations.h"

/* Набор тестов для функции multy_matrix.
*/
Suite *multy_matrix_suite(void);

/* Функция возвращает результат тестирования функции multy_matrix.
*/
int multy_matrix_result(void);

#endif
