#include "errcodes.h"
#include <stdio.h>

void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Error: Incorrect input");
    else if (rc == ERR_EMPTY)
        printf("Error: Empty");
    else if (rc == ERR_RANGE)
        printf("Error: Out of range");
    else if (rc == ERR_BACK)
        printf("Error: Back to mat");
    else
        printf("Error: Unknown error\n");
}
