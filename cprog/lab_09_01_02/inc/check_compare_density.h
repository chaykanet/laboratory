#ifndef CHECK_COMPARE_DENSITY_H
#define CHECK_COMPARE_DENSITY_H

#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "errcodes.h"
#include "object_t.h"
#include "my_limits.h"

/*  Набор тестов для compare_density.
*/
Suite *compare_density_suite(void);

/*  Функция выводит результат тестирования compare_density.
*/
int compare_density_result(void);

#endif
