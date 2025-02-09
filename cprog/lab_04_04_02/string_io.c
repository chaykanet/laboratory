#include "string_io.h"

int get_line(char *buf, int buf_len)
{   
    char *p;
    
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

void print_answer(int const rc)
{
    if (rc == ERR_OK)
        printf("YES");
    else
        printf("NO");
}
