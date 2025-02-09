#ifndef MYSORT_H
#define MYSORT_H

#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "my_limits.h"
#include "errcodes.h"

#define EPS 1e-7
#define IS_BIGGER(A, B) A - B > EPS ? true : false

/*  Функция сравнивает целочисленные элементы.
    Принимает указатели на элементы r, l.
    Возвращает число больше 0, если r > l, иначе если r < l, то - число меньше 0, иначе - 0.
*/
int compare_int(const void *r, const void *l);

/*  Функция сортирует массив элементов по возрастанию.
    Принимает указатель на массив base, кол-во элементов nmemb, размер элементов size, функцию компаратор cmp.
*/
void mysort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *));

#endif
