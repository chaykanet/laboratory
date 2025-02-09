#ifndef CHECK_ARR_H
#define CHECK_ARR_H

#include <check.h>
#include <stdlib.h>
#include "arr.h"

/* Набор тестов для функции add_num_after_even.
*/
Suite *add_num_after_even_suite(void);

/* Функция возвращает результат тестирования функции add_num_after_even.
*/
int add_num_after_even_result(void);

/* Набор тестов для функции fill_prime.
*/
Suite *fill_prime_suite(void);

/* Функция возвращает результат тестирования функции fill_prime.
*/
int fill_prime_result(void);

/* Набор тестов для функции fill_prime.
*/
Suite *calc_even_suite(void);

/* Функция возвращает результат тестирования функции fill_prime.
*/
int calc_even_result(void);

#endif
