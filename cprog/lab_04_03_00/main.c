#include <stdio.h>
#include "logic.h"
#include "string_io.h"

int main(void)
{
    int rc;
    char str[STR_LEN];

    char words[N][WORD_LEN];
    size_t words_n;

    rc = get_line(str, STR_LEN);

    if (rc != ERR_OK)
    {
        return rc;
    }

    rc = get_words(str, words, &words_n);

    if (rc != ERR_OK)
    {
        return rc;
    }

    if (words_n <= 1)
    {
        return ERR_IO;
    }

    char new_str[STR_LEN] = { 0 };

    form_rvrs_str_without_last(new_str, words, words_n);

    if (!strlen(new_str))
        return ERR_EMPTY_STR;

    printf("Result: %s\n", new_str);
    
    return ERR_OK;
}
