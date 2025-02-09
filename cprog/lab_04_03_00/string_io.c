#include "string_io.h"
#include <string.h>

int get_line(char *buf, int buf_len)
{   
    char *p;
    
    printf("Enter your string: ");
    if (fgets(buf, buf_len, stdin))
    {
        p = strchr(buf, '\n');

        if (p)
        {
            *p = '\0';
            return ERR_OK;
        }
    }
    
    return ERR_IO;
}
