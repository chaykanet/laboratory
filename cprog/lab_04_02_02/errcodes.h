/* Заголовочный файл содержит мнемонические имена кодов ошибок*/

#ifndef ERRCODES_H
#define ERRCODES_H

#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_BUF_TO_SMALL 2
#define ERR_TOO_MUCH_WORDS 3

/*  Функция выводит сообщение об ошибке.
    Функция принимает код ошибки rc.
*/
void print_err(int const rc);

#endif
