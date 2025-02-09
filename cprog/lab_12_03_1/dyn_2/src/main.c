#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_limits.h"
#include "errcodes.h"
#include "mysort.h"

#include <dlfcn.h>

#define ACTION_SORT 1
#define ACTION_FKEY 2

#define ERR_LOAD 10

struct lib_funcs_t
{
    int (*read_array)(char *filename, int **p_st, int **p_en);

    int (*outputarray_tofile)(char *filename, int const *p_st, int const *p_en);

    int (*key)(int *pb_src, int *pe_src, int *pb_dst, int **pe_dst);
};

int load_lib(void *hlib, struct lib_funcs_t *funcs)
{
    funcs->read_array = dlsym(hlib, "read_array");
    funcs->outputarray_tofile = dlsym(hlib, "outputarray_tofile");
    funcs->key = dlsym(hlib, "key");

    if (!funcs->read_array)
    {
        fprintf(stderr, "Error loading read_array: %s\n", dlerror());
        return ERR_LOAD;
    }

    if (!funcs->outputarray_tofile)
    {
        fprintf(stderr, "Error loading outputarray_tofile: %s\n", dlerror());
        return ERR_LOAD;
    }

    if (!funcs->key)
    {
        fprintf(stderr, "Error loading key: %s\n", dlerror());
        return ERR_LOAD;
    }

    return ERR_OK;
}

int main(int argc, char **argv)
{   
    int rc = ERR_OK;
    int action = 0;

    if (argc == MAX_ARGUMENTS - 1)
        action = ACTION_SORT;
    else if (argc == MAX_ARGUMENTS && strcmp(argv[argc - 2], FKEY) == 0)
        action = ACTION_FKEY;
    else
        return ERR_ARG;

    int *p_st = NULL, *p_en = NULL;
    
    char *filename = argv[1];

    int *p_stf, *p_enf;

    void *hlib = NULL;

    struct lib_funcs_t funcs = { NULL };

    hlib = dlopen(argv[argc - 1], RTLD_NOW);

    rc = load_lib(hlib, &funcs);

    if (rc == ERR_OK)
        rc = funcs.read_array(filename, &p_st, &p_en);
    
    p_stf = p_st;
    p_enf = p_en;

    if (rc == ERR_OK)
    {
        if (action == ACTION_FKEY)
        {   
            if (p_en - p_st)
            {
                p_stf = malloc(sizeof(int) * (p_en - p_st));

                p_enf = p_stf + (p_en - p_st);
            }

            rc = funcs.key(p_st, p_en, p_stf, &p_enf);

            free(p_st);
        }

        if (rc == ERR_OK && (action == ACTION_FKEY || action == ACTION_SORT))
        {
            mysort((int *) p_stf, p_enf - p_stf, sizeof(int), compare_int);

            rc = funcs.outputarray_tofile(argv[2], p_stf, p_enf);
        }
    }

    free(p_stf);
    
    dlclose(hlib);

    return rc;
}
