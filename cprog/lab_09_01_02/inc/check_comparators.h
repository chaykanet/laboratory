#ifndef _CHECK_COMPARATORS_H_
#define _CHECK_COMPARATORS_H_

#include "object_t.h"

/*  Компаратор сравнивающий элементы типа object_t.
    Принимает указатели на l, r.
    Возвращает 0, если равны, иначе - код ошибки сравнивания.
*/
int compare_object_t(const void *l, const void *r);

/*  Функция сравнивает элементы массивов.
    Функция принимает массивы l и r, их размер n, размер элемента size, компаратор cmp(const *void, const *void).
    Возвращает не 0, если элементы не равны, иначе 0.
*/
int compare_arr(const void *l, const void *r, const size_t n, const size_t size, int (*cmp)(const void*, const void*));

#endif