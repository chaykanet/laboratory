#include "logic.h"
#include <stdbool.h>
#include "string_io.h"

void my_strcpy(char *str_1, char *str_2)
{   
    char *it = str_1;
    for (char *px = str_2; *px != '\0'; px++)
    {
        *it = *px;
        it++;
    }

    *it = '\0';
}

void delete_repeated_words(char (*words)[WORD_LEN], size_t *words_n)
{   
    size_t i = 0;
    size_t j = 0;
    size_t len = *words_n;

    while (i < len)
    {
        if (i != 0 && is_finded(words, i - 1, words[i]))
        {
            i++;
            *words_n -= 1;
        }
        else
        {
            my_strcpy(words[j], words[i]);
            i++;
            j++;
        }
    }
}

bool is_finded(char (*words)[WORD_LEN], size_t const words_n, char const *str)
{
    for (size_t j = 0; j < words_n; j++)
        if (strcmp(str, words[j]) == 0)
            return true;
    return false;
}
