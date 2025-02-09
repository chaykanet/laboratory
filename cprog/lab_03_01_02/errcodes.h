/* Заголовочный файл содержит мнемонические имена кодов ошибок и функцию вывода ошибок*/

#ifndef ERRCODES_H
#define ERRCODES_H

#define ERR_OK 0
#define ERR_IO 1
#define ERR_EMPTY 2
#define ERR_RANGE 3

/*  Осуществляет вывод сообщения об ошибке.
    Функция принимает код ошибки rc.
*/
void print_err(int const rc);

#endif
