#ifndef FUNC_ARRAY_IO_H
#define FUNC_ARRAY_IO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errcodes.h"

/*  Функция считывает массив целых чисел их файла.
    Функция принимает имя файле filename, указатели на начало p_st и конец массива p_en.
    Функция возвращает код ошибки.
*/
int read_array(char *filename, int **p_st, int **p_en);

/*  Функция Подсчитывает кол-во целых элементов в файле.
    Функция принимает указатель на файл file, указатель на кол-во элементов n.
    Возвращает код ошибки.
*/
int calc_size_array(FILE *file, size_t *n);

/*  Функция записывает в файл целочисленный массив.
    Функция принимает имя файла filename, указатели на начало и конец массива p_st, p_en.
    Возвращает код ошибки.
*/
int outputarray_tofile(char *filename, int const *p_st, int const *p_en);

/*  Функция фильтрует массив следующим образом: фильтр записывает в новый массив целочисленные 
    элементы до последнего негативного, если негативных элементов нет, то функция записывает весь массив.
    Возвращает код ошибки.
*/
int key(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst);

/*  Функция копирует элементы из одного массива в другой.
    Функция принимает указатели на начало и конец pb_dst, pe_dst и pb_src, pe_src соответствующих массивов.
    Возвращает успешный код выполнения при полном копировании в принимающий массив, иначе - код ошибки.
*/
int arrcopy_toarray(int *const pb_dst, int *const pe_dst, int *const pb_src, int *const pe_src);

/*  Функция считывает nmemb целых чисел из файла в переданный массив.
    Функция принимает файловую переменную file, указатели на начало и конец массива base_st и base_en.
    Возвращает код последнего выполнения функции fcanf.
*/
int fread_toarray(FILE *file, int *const base_st, int *const base_en);

#endif
