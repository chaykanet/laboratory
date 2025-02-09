#ifndef H_STRING_IO
#define H_STRING_IO

#include <stdio.h>
#include "errcodes.h"

/*  Выполняет чтение вводимой строки.
    Функция принимает буффер и размер буффера.
*/
int get_line(char *buf, int buf_len);

#endif
