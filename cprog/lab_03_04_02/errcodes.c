
#include "errcodes.h"
#include <stdio.h>

void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Error: Incorrect input\n");
    else if (rc == ERR_EMPTY)
        printf("Error: Empty\n");
    else if (rc == ERR_RANGE)
        printf("Error: Out of range\n");
    else if (rc == ERR_PARAM)
        printf("Error: Matrix is not square\n");
    else if (rc == ERR_FINDED)   
        printf("Error: Max wasn't finded\n");
    else if (rc == ERR_OK)
        printf("Ok\n");
    else
        printf("Error: Unknown error\n");
}
