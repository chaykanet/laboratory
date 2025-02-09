#include "string_io.h"
#include "string_split.h"
#include "logic.h"

int main(void)
{   
    char str_1[STR_LEN];
    char str_2[STR_LEN];
    str_1[0] = 0;
    str_2[0] = 0;
    int rc;

    char words_1[N][WORD_LEN];
    char words_2[N][WORD_LEN];

    size_t n_1, n_2;
    
    rc = get_line(str_1, STR_LEN);
    
    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    rc = get_line(str_2, STR_LEN);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }
    
    rc = parsc_string(str_1, words_1, &n_1, WORD_LEN);
    
    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }
    
    rc = parsc_string(str_2, words_2, &n_2, WORD_LEN);
    
    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }
    
    delete_repeated_words(words_1, &n_1);
    
    delete_repeated_words(words_2, &n_2);

    print_find_word(words_1, n_1, words_2, n_2);

    return ERR_OK;
}
