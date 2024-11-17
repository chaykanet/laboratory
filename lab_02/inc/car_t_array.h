#ifndef CAR_T_ARRAY_H
#define CAR_T_ARRAY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "car_t.h"
#include "car_t_io.h"
#include "errcodes.h"


#define MAX_ELEM 1000

typedef struct car_t_arr_el // Структура (индекс - машина)
{   
    unsigned long index;
    
    car_t car;

} car_el_t;

/*  Функция осуществляет запись элементов типа car_el_t из файловой переменной в соответствующий массив.
    Функция принимает файловую переменную file, двойные указатели на начало base_st и конец base_en массива типа car_el_t.
    Возвращает код ошибки. 
*/
int fread_arr_car(FILE *file, car_el_t **base_st, car_el_t **base_en);

/*  Функция добавляет элемент типа car_el_t в массив.
    Принимает указатели типа car_el_t на начало base_st и указатель на размер массива nmemb.
    Возвращает код ошибки.
*/
int add_arr_elem(car_el_t **base_st, size_t *nmemb);

/*  Функция удаляет первое вхождение элемента типа car_el_t по цене из массива.
    Принимает указатели типа car_el_t на начало base_st и указатель на размер массива nmemb, значение цены price.
    Возвращает код ошибки.
*/
int pop_arr_elembyprice(car_el_t **base_st, size_t *nmemb, size_t const price);

/*  Функция осуществляет вывод таблицы машин из массива типа car_el_t.
    Принимает указатели типа car_el_t на начало base_st и конец base_en массива.
*/
void print_arr_car(car_el_t *base_st, size_t const nmemb);

/*  Функция осуществляет вывод в файл таблицы машин из массива типа car_el_t.
    Принимает файловую переменную file, указатели типа car_el_t на начало base_st и конец base_en массива.
*/
void fprint_arr_car(FILE *file, car_el_t *base_st, size_t const nmemb);

/*  Функция находит старые машины определенной марки с 1 владельцем в заданном диапозоне цен.
    Принимает указатели типа car_el_t на начало фильтруемого массива base_st, размер массива nmemb, 
    массив нужных элементов arr, его длину len, марку машины mark, диапозон цен, price_l и price_r.
    Возвращает код ошибки.
*/
int filter_car_param(car_el_t *base_st, size_t const nmemb, car_el_t *arr, size_t *len, char const *mark, unsigned const price_l, unsigned const price_r);

/*  Функция выводит иномарки с тех. поддержкой.
    Функция принимает массив arr, размер массива len.
*/
void print_garanted_car(car_el_t *arr, size_t const len);

#endif
