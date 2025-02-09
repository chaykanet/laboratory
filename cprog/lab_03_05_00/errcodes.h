/* Заголовочный файл содержит мнемонические имена кодов ошибок, объявление функции вывода ошибок*/

#ifndef ERRCODES_H
#define ERRCODES_H

#define ERR_OK 0
#define ERR_IO 1
#define ERR_EMPTY 2
#define ERR_RANGE 3
#define ERR_FINDED 4
#define ERR_BACK 5

/*  Осуществляет вывод сообщение об ошибке.
    Функция принимает код ошибки.
*/
void print_err(int const rc);

#endif
