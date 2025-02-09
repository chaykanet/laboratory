#include "mysort.h"
#include "errcodes.h"
#include "object_t.h"
#include "my_limits.h"
#include "object_t_array.h"

#define ACTION_ALL 1
#define ACTION_PREFIX 2
#define ACTION_SORT 3

int main(int argc, char **argv)
{   
    int rc = ERR_OK;
    int action = 0;
    
    object_t *list = NULL;    
    size_t nmemb = 0;

    if (argc == MAX_ARGUMENTS && strcmp(ALL, argv[MAX_ARGUMENTS - 1]) == 0)
        action = ACTION_ALL;
    else if (argc == MAX_ARGUMENTS)
        action = ACTION_PREFIX;
    else if (argc == MAX_ARGUMENTS - 1)
        action = ACTION_SORT;
    else
        return ERR_ARG;

    rc = read_array(argv[1], &list, &nmemb);

    if (rc == ERR_OK && nmemb == 0)
        rc = ERR_EMPTY;

    if (rc == ERR_OK && action == ACTION_SORT)
        sort_array(list, nmemb);
    
    if (rc == ERR_OK && action == ACTION_PREFIX)
        rc = print_with_prefix(list, nmemb, argv[MAX_ARGUMENTS - 1]);
    
    if (rc == ERR_OK && (action == ACTION_SORT || action == ACTION_ALL))
        print_array(list, nmemb);
    
    if (list)
        free_array(list, nmemb);
    
    return rc;
}
