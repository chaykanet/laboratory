// Заголовочный файл содержит объявления функций и мнемонические имена логики необходимой для решения задачи

#ifndef LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_limits.h"
#include "matrix_io.h"
#include "errcodes.h"

#define CORR_IN_ONE 1
#define CORR_IN_TWO 2
#define DIV_TWO 2

/*  Функция осуществляет заполнение столбца снизу вверх, если значение reverse false.
    Иначе функция осуществляет запонение столбуа сверху вниз.
    Функция принимает матрицу mat, кол-во строк n, индекс столбца index, 
    число с которого начинается заполнение num, переменная reverse.
*/
void input_down_up(int (*mat)[N], size_t n, size_t index, size_t *num, bool reverse);

/*  Функция осуществляет заполнение матрицы методом "хода быка", начиная с последнего элемента.
    Функция принимает матрицу, кол-во строк, кол-во столбцов.
*/
void input_step_bull(int (*mat)[M], size_t n, size_t m);

#endif
