#ifndef CHECK_READ_ARRAY_H
#define CHECK_READ_ARRAY_H

#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "errcodes.h"
#include "object_t.h"
#include "my_limits.h"
#include "object_t_array.h"

/*  Набор тестов для read_array.
*/
Suite *read_array_suite(void);

/*  Функция выводит результат тестирования read_array.
*/
int read_array_result(void);

#endif
