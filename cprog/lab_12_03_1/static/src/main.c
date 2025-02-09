#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_limits.h"
#include "errcodes.h"
#include "mysort.h"
#include "func_array.h"

#define ACTION_SORT 1
#define ACTION_FKEY 2

int main(int argc, char **argv)
{   
    int rc = ERR_OK;
    int action = 0;

    if (argc == MAX_ARGUMENTS - 1)
        action = ACTION_SORT;
    else if (argc == MAX_ARGUMENTS && strcmp(argv[argc - 1], FKEY) == 0)
        action = ACTION_FKEY;
    else
        return ERR_ARG;

    int *p_st = NULL, *p_en = NULL;
    
    char *filename = argv[1];

    const int *p_stf, *p_enf;

    rc = read_array(filename, &p_st, &p_en);
    
    p_stf = p_st;
    p_enf = p_en;

    if (rc == ERR_OK)
    {
        if (action == ACTION_FKEY)
        {
            rc = key(p_st, p_en, &p_stf, &p_enf);

            free(p_st);
        }

        if (rc == ERR_OK && (action == ACTION_FKEY || action == ACTION_SORT))
        {
            mysort((int *) p_stf, p_enf - p_stf, sizeof(int), compare_int);

            rc = outputarray_tofile(argv[2], p_stf, p_enf);
        }
    }

    free((int *) p_stf);

    return rc;
}
