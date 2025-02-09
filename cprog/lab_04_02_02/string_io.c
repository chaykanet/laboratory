#include "string_io.h"
#include <stdbool.h>
#include "logic.h"

int get_line(char *buf, int buf_len)
{   
    char *p;
    printf("Enter your string: ");
    if (!fgets(buf, buf_len, stdin))
        return ERR_IO;
    
    p = strchr(buf, '\n');

    if (p)
        *p = '\0';

    if (!*buf || strlen(buf) >= STR_LEN - 1)
        return ERR_IO;

    return ERR_OK;
}

void print_find_word(char (*words_1)[WORD_LEN], size_t const n_1, char (*words_2)[WORD_LEN], size_t const n_2)
{   
    printf("Result: \n"); 
    for (size_t i = 0; i < n_1; i++)
    {  
        if (is_finded(words_2, n_2, words_1[i]))
            printf("%s yes\n", words_1[i]);
        else
            printf("%s no\n", words_1[i]);
    }
}
