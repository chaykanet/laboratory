#include "logic.h"

void delete_first_char(char *str)
{   
    char first_char = str[0];
    size_t i = 1;
    size_t j = 1;

    while (str[i] != '\0')
    {
        if (str[i] == first_char)
            i++;
        else
        {
            str[j] = str[i];
            i++;
            j++;
        }
    }

    str[j] = '\0';
}

void form_rvrs_str_without_last(char *const str, char (*words)[WORD_LEN], size_t words_n)
{   
    if (words_n <= 1)
        return;

    size_t i = words_n - 1;
    char last[WORD_LEN];
    strcpy(last, words[words_n - 1]);
    
    for (; i - 1 != 0; i--)
    {   
        if (strlen(words[i - 1]) && strcmp(words[i - 1], last) != 0)
        {   
            delete_first_char(words[i - 1]);
            
            strcat(str, words[i - 1]);

            str[strlen(str)] = ' ';
        }
    }

    if (strlen(words[i - 1]) && strcmp(words[i - 1], last) != 0)
    {
        delete_first_char(words[i - 1]);
        strcat(str, words[i - 1]);
    }
    else
        str[strlen(str) - 1] = '\0';
}

int get_words(char *const str, char (*words)[WORD_LEN], size_t *words_n)
{
    char *p = strtok(str, SEPARATORS);

    size_t i = 0;

    while (p && strlen(p) < WORD_LEN && i < N)
    {
        strncpy(words[i], p, WORD_LEN);
        i++;
        p = strtok(NULL, SEPARATORS);
    }

    if (p && strlen(p) >= WORD_LEN)
        return ERR_BUF_TO_SMALL;
    
    if (i == N)
        return ERR_TOO_MUCH_WORDS;

    *words_n = i;

    return ERR_OK;
}
