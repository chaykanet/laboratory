#include "string_io.h"
#include "logic.h"

int main(void)
{
    int rc;
    char str[STR_LEN] = { 0 };
    char months[MONTHS_N][WORD_LEN] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
   
    rc = get_line(str, STR_LEN);

    if (rc != ERR_OK)
    {
        return rc;
    }

    rc = check_data(str, months);

    if (rc != ERR_OK)
    {
        print_answer(rc);
        return ERR_OK;
    }
    
    print_answer(rc);

    return ERR_OK;
}
