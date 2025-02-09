#ifndef CHECK_FUNC_ARRAY_H
#define CHECK_FUNC_ARRAY_H

#include <check.h>
#include <stdbool.h>
#include "func_array.h"

/*  Набор тестов для функции key.
*/
Suite *key_suite(void);

/*  Набор тестов для функции arrscanf_toarray.
*/
Suite *arrscan_toarray_suite(void);

/*  Функция возвращает результат тестирования функции key.
*/
int key_result(void);

/*  Функция возвращает результат тестирования функции arrscanf_toarray.
*/
int arrscan_toarray_result(void);

#endif
