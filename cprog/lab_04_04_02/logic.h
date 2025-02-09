//  Заголовочный файл содержит функции и мнемонические имена логики, необходимых для решения задачи.

#ifndef LOGIC_H
#define LOGIC_H

#include <string.h>
#include "strings_limits.h"
#include <stdbool.h>
#include "errcodes.h"

#define DATA_N 3
#define MONTHS_N 12
#define DIV_BY_FOUR 4
#define DIV_BY_HUNDRED 100
#define DIV_BY_FOUR_HUNDRED 400
#define MIN_DAYS_IN_MONTH 28
#define MAX_VES_FEBRUARY 29
#define SECOND_MONTH 2
#define MIN_YEAR 1000
#define MAX_YEAR 9999
#define SIZE_YEAR 4
#define INTEGERS "0123456789"

/*  Функция определяет верность введнной даты.
    Функция принимает строки str, массив названий месяцев года months.
    Функция возвращает код ошибки.
*/
int check_data(char *str, char (*months)[WORD_LEN]);

/*  Функция проверяет формат даты [D]D MONTH YYYY
    Принимает строку str, указатели на день p_day, месяц p_month, год p_year.
    Функция возвращает код ошибки.
*/
int check_format(char *str, char *p_day, char *p_month, char *p_year);

/*  Функция находит в строке день и год, проверяет их корректность
    Функция принимает строку str, указатель на день point_day, на год point_year.
    Функция возвращает код ошибки.
*/
int find_day_and_year(char *str, char **point_day, char **point_year);

/*  Функция находит в строке месяц, проверяет ее корректность.
    Функция принимает строку str, указатель на месяц month_point.
    Функция возвращает номер месяца, если месяц неверный, то - число 13.
*/
size_t find_and_determine_month(char *str, char (*months)[WORD_LEN], char **month_point);

#endif
