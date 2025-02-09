#ifndef H_STRING_IO
#define H_STRING_IO

#include <string.h>
#include <stdio.h>
#include "strings_limits.h"
#include "errcodes.h"

/*  Выполняет чтение вводимой строки.
    Функция принимает буффер и размер буффера.
*/
int get_line(char *buf, int buf_len);

/*  Функция выполняет вывод сообщения об вхождений массива строк в другом массиве строк.
    Функция принимает массив words_1, размер массива n_1, массив words_2, размер массива n_2
*/
void print_find_word(char (*words_1)[WORD_LEN], size_t n_1, char (*words_2)[WORD_LEN], size_t n_2);

#endif
