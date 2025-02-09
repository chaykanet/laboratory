/* Заголовочный файл содержит мнемонические имена кодов ошибок, объявление функции вывода ошибок*/

#ifndef ERRCODES_H
#define ERRCODES_H

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2

/*  Осуществляет вывод сообщения об ошибке.
    Функция принимает код ошибки rc.
*/
void print_err(int const rc);

#endif
