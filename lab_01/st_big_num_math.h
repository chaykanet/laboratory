
#ifndef ST_BIG_NUM_MATH_H
#define ST_BIG_NUM_MATH_H

#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "errcodes.h"

#include "st_big_num.h"

#define TEN 10
#define NINE 9
#define FIVE 5

/*  Функция осуществляет деление действительный чисел типа big_num.
    Функция принимает указатели на делимое num_1, делитель num_2, частное result.
    Возвращает код ошибки выполнения операции.
*/
int complex_devide(struct big_num *num_1, struct big_num *num_2, struct big_num *result);

/*  Функция осуществляет умножение действительного числа типа big_num на однозначное типа int.
    Функция принимает указатель на число num, однозначное число multy.
    Возвращает код ошибки выполнения операции.
*/
int simple_multy(struct big_num *num, int multy);

/*  Функция осуществляет вычитание целых числел типа big_num.
    Функция принимает указатели на num_1, num_2.
    Возвращает код ошибки выполнения операции.
*/
int to_sub(struct big_num *num_1, struct big_num *num_2);

#endif
