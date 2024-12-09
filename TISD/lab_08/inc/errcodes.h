#ifndef __ERRCODES_H_
#define __ERRCODES_H_

typedef enum _error
{
    // Успешное выполнение.
    ERR_OK = 0,
    // Ошибка чтения/записи.
    ERR_IO,
    // Ошибка, пустой граф.
    ERR_EMPTY
} error_t;

#endif