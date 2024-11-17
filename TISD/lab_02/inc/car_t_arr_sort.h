#ifndef CAR_T_ARR_SORT_H
#define CAR_T_ARR_SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "car_key_t.h"
#include "car_t_array.h"

#define MAX_BITES 256

/*  Сортирует массив типа car_el_t по возрастанию цены машины.
    Функция принимает указатели на начало и конец массива base_st, base_en, кол-во элементов nmemb, размер элемента size, функцию компаратора типа 
    (void const *,void const *).
    Функция сортирует массив пузырьком с запоминанием последенго обмена по возрастанию.
*/
void qsort_arr(void *base_st, size_t const nmemb, size_t const size, int (*cmp)(void const *,void const *));

/*  Сортирует массив элементов различных типов.
    Функция принимает указатели на начало и конец массива base_st, base_en, кол-во элементов nmemb, размер элемента size, функцию компаратора типа 
    (void const *,void const *).
    Функция сортирует массив пузырьком по возрастанию.
*/  
void sort_arr(void *base_st, void *base_en, size_t const nmemb, size_t const size, int (*cmp)(void const *,void const *));

/*  Функция компаратор сравнивает цены машин типа car_el_t.
    Функция принимает указатели типа void на первый l и второй элемент r.
    Возвращает разницу цен.
*/
int cmp_car_price(void const *l, void const *r);

/*  Функция компаратор сравнивает цены машин типа ckey_t.
    Функция принимает указатели типа void на первый l и второй элемент r.
    Возвращает разницу цен.
*/
int cmp_key_price(void const *l, void const *r);

#endif
