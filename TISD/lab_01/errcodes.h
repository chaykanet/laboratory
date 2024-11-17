
#ifndef ERRCODES_H
#define ERRCODES_H

#define ERR_IO 1
#define ERR_DATA 2
#define ERR_NULL 3
#define ERR_OK 0

/*  Функция выводит сообщение об ошибке.
    Функция принимает код ошибки.
*/
void print_err(int const rc);

#endif