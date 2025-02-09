#include "errcodes.h"
#include <stdio.h>

void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Error: Incorrect input\n");
    else if (rc == ERR_RANGE)
        printf("Error: Out of range\n");
    else if (rc == ERR_OK)
        printf("Ok\n");
    else
        printf("Error: Unknown error\n");
}
