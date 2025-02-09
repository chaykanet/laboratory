/* Заголовочный файл содержит функции для разбиения строки на лексемы*/
#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

#include <stdio.h>
#include "strings_limits.h"


/*  Функция разбивает строку на лексемы, присваивая их к массиву строк. 
    Функция принимает строку str, массив строк words, размер массива words_n, размер лексмем word_len.
*/
int parsc_string(char const *str, char (*words)[WORD_LEN], size_t *words_n, int word_len);

/*  Функция с помощью указателей pbeg и pend копирует лексему из строки в строку word.
    Функция принимает указатели на начало и конец лексемы pbeg, pend, строку word, максимальный размер лексемы word_len.
*/
int copy_word(char const *pbeg, char const *pend, char *word, int word_len);

/*  Функция находит указатели на начало и конец следующей лексемы в строке.
    Функция принимает строку str, параметры pbeg и pend, в которых будут занесены указатели на начало и конец следующей лексемы.
*/
void get_next_word(char const *str, char **pbeg, char **pend);

#endif
