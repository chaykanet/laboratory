#include "errcodes.h"
#include <stdio.h>

void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Error: Incorrect input");
    else if (rc == ERR_BUF_TO_SMALL)
        printf("Error: Overflow");
    else if (rc == ERR_TOO_MUCH_WORDS)
        printf("Error: Out of range");
    else
        printf("Error: None error\n");
}
