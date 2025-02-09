#ifndef H_STRING_IO
#define H_STRING_IO

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "strings_limits.h"
#include "errcodes.h"

/*  Выполняет чтение вводимой строки.
    Функция принимает буффер и размер буффера.
    Возвращает код ошибки
*/
int get_line(char *buf, int buf_len);

/*  Функция выводит сообщение "Yes", если код успешно завершается, 
    иначе "No".
    Функция принимает код выполнения rc. 
*/
void print_answer(int const rc);

#endif
