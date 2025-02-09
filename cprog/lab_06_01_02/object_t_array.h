
#ifndef ST_OBJECT_ARRAY_H
#define ST_OBJECT_ARRAY_H

#include <stdio.h>
#include <stddef.h>
#include "object_t.h"
#include "string.h"
#include "stdbool.h"

/*  Функция формирует массив структур object_t из текстового файла.
    Функция принимает имя файла filename, массив структур list, размер массива size, максимальный размер массива.
    Вовзращает массив, размер, код ошибки.
*/
int read_array(char const *filename, struct object_t *list, size_t *size, size_t const max_size);

/*  Функция сортирует массив структур object_t по возрастанию плотности объектов.
    Функция принимает массив list, его размер size.
    Возвращает отсортированный массив.
*/
void sort_array(struct object_t *list, size_t const size);

/*  Функция выводит информацию об объектах, в начале названий которых есть вхождение подсторки prefix.
    Функция принимает массив list, его размер size, подстроку prefix.
    Возвращает код ошибки.
*/
int print_with_prefix(struct object_t const *list, size_t const size, char const *prefix);

/*  Функция выводит массив объектов.
    Функция принимает массив list, его размер size.
    Возвращает код ошибки.
*/
void print_array(struct object_t const *list, size_t const size);

#endif
