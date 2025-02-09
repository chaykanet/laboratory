#ifndef CHECK_SORT_H
#define CHECK_SORT_H

#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "mysort.h"
#include "errcodes.h"
#include "object_t.h"
#include "my_limits.h"

/*  Набор тестов для sort_array.
*/
Suite *sort_array_suite(void);

/*  Функция выводит результат тестирования sort_array.
*/
int sort_array_result(void);

#endif
