//  Заголовочный файл содержит функции и мнемонические имена логики, необходимых для решения задачи.
#ifndef LOGIC_H
#define LOGIC_H

#include <string.h>
#include "strings_limits.h"
#include "errcodes.h"

/*  Функция удалет все вхождения первого символа в строке.
    Функция принимает строку.
*/
void delete_first_char(char *str);

/*  Функция формирует строку из массива строк в обратном порядке.
    Функция принимает массив строк words, размер массива words_n.
*/
void form_rvrs_str_without_last(char *const str, char (*words)[WORD_LEN], size_t words_n);

/*  Функция разбивает строку на лексемы.
    Функция принимает строку str, массив words, размер массива.
*/
int get_words(char *const str, char (*words)[WORD_LEN], size_t *words_n);

#endif
