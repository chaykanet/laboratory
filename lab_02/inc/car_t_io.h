#ifndef CAR_T_IO_H
#define CAR_T_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "car_t.h"

#define BUFFER_LEN 200
#define ELEM_NEW 7
#define ELEM_OLD 10
#define N 10

/*  Функция осуществляет запись структуры типа car_t по файловой переменной.
    Функция принимает файловую переменную file, структуру car.
*/
void write_car_tofile(FILE *file, car_t const car);

/*  Функция осуществляет корректную запись с клавиатуры в стуктуру car_t.
    Функция принимает указатель типа car_t на структуру car.
    Возвращает код ошибки.
*/
int get_car (car_t *car);

/*  Функция осуществляет корректную запись из файловой переменной в стуктуру car_t.
    Функция принимает файловую переменную file, указатель типа car_t на структуру car.
    Возвращает код ошибки.
*/
int read_carfrmfile(FILE *file, car_t *car);

/*  Функция выводит заголовки таблицы машин или ключей.
    Функция принимает параметр key, который переключает режим вывода.
    Если key равен 1, то функция выведет заголовки таблицы ключей, иначе заголовки таблицы машин.
*/
void print_header(int const key);

/*  Функция выводит в файловую переменную строку по ширине.
    Принимает файловую переменную file, строку str, величину ширины width.
*/
void print_centered(FILE *file, const char *str, int const width);

#endif
