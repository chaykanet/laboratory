#include <stdio.h>
#include "errcodes.h"
#include <vector.h>

void print_err(int const rc)
{
    switch (rc)
    {
        case ERR_IO:
            printf("ERR_IO: Ошибка ввода.\n");
            break;
        case ERR_DATA:
            printf("ERR_DATA: Ошибка данных.\n");
            break;
        case ERR_NULL:
            printf("ERR_NULL: Переполнение данных.\n");
        case ERR_OK:
            break;
    }
}
