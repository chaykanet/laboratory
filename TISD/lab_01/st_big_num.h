
#ifndef ST_BIG_NUM_H
#define ST_BIG_NUM_H

#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "errcodes.h"

#define N 41
#define LEN_MANTISA 41
#define LEN_POWER 5
#define MAX_POWER 99999

struct big_num  // Структура хранения чисел.
{
    int massive[N];  // Массив хранения цифр числа.

    size_t len; // Длина числа.

    int point_pos; // Позиция точки в числе.

    int power;  // Степень числа.

    char sign;  // Знак числа.

};

/*  Функция считывает из буффера число структурного типа big_num.
    Возвращает код ошибки, если строка не подходит маске [+-]n.mEk
    (n + m) = 40 до 40 цифр, k до 5 цифр.
*/
int take_num(char const *buffer, struct big_num *num);

/*  Функция выводит число структурного типа big_num на экран в виде
    [+-]0.mEk, m до 40 цифр.
*/
void print_num(struct big_num num);

#endif
