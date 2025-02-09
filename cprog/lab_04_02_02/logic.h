//  Заголовочный файл содержит функции и мнемонические имена логики, необходимых для решения задачи.

#ifndef LOGIC_H
#define LOGIC_H

#include <string.h>
#include "strings_limits.h"
#include "errcodes.h"
#include <stdbool.h>

/*  Функция копирует одну строку str_2 в строку str_1.
    Функция принимает строки str_1 и str_2.
*/
void my_strcpy(char *str_1, char *str_2);

/*  Функция удалет из массива повторяющиеся строки, оставляя первое вхождение.
    Функция принимает массив строк words, размер массива words_n.
*/
void delete_repeated_words(char (*words)[WORD_LEN], size_t *words_n);

/*  Функция возвращает true, если есть вхождение строки str в массиве строк words,
    иначе false.
    Функция принимает массив строк words, размер массива words_n, строку str.
*/
bool is_finded(char (*words)[WORD_LEN], size_t const words_n, char const *str);

#endif
