#include "string_split.h"
#include "errcodes.h"
#include <string.h>

void get_next_word(char const *str, char **pbeg, char **pend)
{   
    *pbeg = NULL;
    *pend = NULL;

    char const *pcur = str;

    char *p = strchr(SEPARATORS, *pcur);

    while (p && *pcur)
    {
        pcur++;
        p = strchr(SEPARATORS, *pcur);
    }

    if (!*pcur)
    {
        *pbeg = (char *) pcur;
        *pend = (char *) pcur;   
        return;
    }

    *pbeg = (char *) pcur;
    
    while (*pcur && !p)
    {
        pcur++;
        p = strchr(SEPARATORS, *pcur);
    }

    *pend = (char *) pcur;
}

int copy_word(char const *pbeg, char const *pend, char *word, int const word_len)
{   
    if (pend - pbeg >= word_len)
        return ERR_BUF_TO_SMALL;
    
    char const *pcur = pbeg;

    size_t i = 0;

    while (pcur != pend)
    {
        word[i] = *pcur;
        i++;
        pcur++;    
    }

    word[i] = '\0';

    return ERR_OK;
}

int parsc_string(char const *str, char (*words)[WORD_LEN], size_t *words_n, int word_len)
{   
    char *pbeg, *pend;
    char const *pcur = str;

    *words_n = 0;
    int rc = ERR_OK;

    get_next_word(pcur, &pbeg, &pend);

    while (rc == ERR_OK && pcur && *pcur && pbeg != pend)
    {
        if (pbeg)
        {
            if (*words_n < N)
            {   
                rc = copy_word(pbeg, pend, words[*words_n], word_len);

                if (rc == ERR_OK)
                    *words_n += 1;
                else
                    return rc;
            }
            else
                rc = ERR_TOO_MUCH_WORDS;
        }

        pcur = pend;

        get_next_word(pcur, &pbeg, &pend);
    }

    return rc;
}
