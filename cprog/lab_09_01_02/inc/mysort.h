#ifndef MYSORT_H
#define MYSORT_H

#include <string.h>
#include <stddef.h>

#include "object_t.h"

/*  Функция сортирует массив типа object_t.
    Функция принимает указатель на массив list, кол-во элементов nmemb.
*/
void sort_array(object_t *list, size_t const nmemb);

#endif
