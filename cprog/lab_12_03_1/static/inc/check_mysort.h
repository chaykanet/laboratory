#ifndef CHECK_MYSORT_H
#define CHECK_MYSORT_H

#include <check.h>
#include <stdlib.h>
#include "mysort.h"

/* Набор тестов для функции mysort.
*/
Suite *mysort_suite(void);

/* Функция возвращает результат тестирования функции mysort.
*/
int mysort_result(void);

#endif
