#ifndef CAR_KEY_T_H
#define CAR_KEY_T_H

#include "car_t_io.h"
#include "car_t_array.h"
#include <stdio.h> 

typedef struct ckey_t // Структура для таблицы ключей индекс - цена.
{
    size_t index;
    
    unsigned price;  
} ckey_t;

/*  Функция получает массив типа ckey_t (массив ключей) из массива типа car_el_t (таблицы).
    Функция принимает двойные указатели типа ckey_t на начало key_st и конец key_en массива ключей, указатели типа 
    car_el_t на начало base_st и конец base_en массива машин.
    Возвращает код ошибки. 
*/
int get_keys(ckey_t **key_st, ckey_t **key_en, car_el_t *base_st, size_t const nmemb);


/*  Функция осуществляет вывод таблицы машин по таблице ключей.
    Функция принимает указатели типа car_el_t на начало base_st и конец base_en массива машин, 
    указатели типа ckey_t на начало key_st и конец key_en массива ключей.
*/
void print_arr_withkey(car_el_t *base_st, car_el_t *base_en, ckey_t *key_st, ckey_t *key_en);

/*  Функция осуществляет вывод таблицы ключей машин.
    Функция принимает указатели типа ckey_t на начало key_st и конец key_en массива ключей.
*/
void print_keys(ckey_t *key_st, ckey_t *key_en);

#endif
