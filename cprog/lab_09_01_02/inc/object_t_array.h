#ifndef ST_OBJECT_ARRAY_H
#define ST_OBJECT_ARRAY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errcodes.h"
#include "object_t.h"
#include "stdbool.h"

/*  Функция формирует массив структур object_t из текстового файла.
    Функция принимает имя файла filename, массив структур list, размер массива size, максимальный размер массива.
    Вовзращает массив, размер, код ошибки.
*/
int read_array(char const *filename, object_t **list, size_t *nmemb);

/*  Функция выводит информацию об объектах, в начале названий которых есть вхождение подсторки prefix.
    Функция принимает массив list, его размер size, подстроку prefix.
    Возвращает код ошибки.
*/
int print_with_prefix(object_t const *list, size_t const size, char const *prefix);

/*  Функция инициализирует массив элементами из файла.
    Функция принимает указатель на инициализируемый массив list, кол-во элементов n, файловую переменную file.
    Возвращает код ошибки.
*/
int finit_array(object_t *list, size_t nmemb, FILE *file);

/*  Функция считает кол-во элементов типа object_t в файле, если элемент не типа object_t возвращает ошибку.
    Функция принимает файловую переменную, указатель на счетчик calc.
    Возвращает код  ошибки.
*/
int calc_objects(FILE *file, size_t *calc);

/*  Функция выводит массив объектов.
    Функция принимает массив list, его размер size.
    Возвращает код ошибки.
*/
void print_array(object_t const *list, size_t const size);

/*  Функция высвобождает память из под массива типа object_t.
    Функция принимает массив list, кол-во элементов n.
*/
void free_array(object_t *list, size_t const n);

#endif
