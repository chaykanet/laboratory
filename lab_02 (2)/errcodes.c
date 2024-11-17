#include "errcodes.h"

void print_err(int const rc)
{
    switch (rc)
    {
    case ERR_IO:
        printf("ERR_IO: Ошибка ввода.\n");
        break;
    case ERR_OVERFLOW:
        printf("ERR_OVERFLOW: Ошибка переполнения.\n");
        break;
    case ERR_ALLOC:
        printf("ERR_ALLOC: Ошибка выделения памяти.\n");
        break;
    case ERR_EMPTY:
        printf("ERR_EMPTY: Ошибка пустого массива.\n");
        break;
    default:
        break;
    }
}
