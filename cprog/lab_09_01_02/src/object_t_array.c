#include "object_t_array.h"

int create_array(object_t **list, const size_t nmemb)
{
    if (nmemb == 0)
        return ERR_ALLOC;

    object_t *ptrs = malloc(nmemb * sizeof(object_t));

    if (!ptrs)
        return ERR_ALLOC;

    *list = ptrs;

    return ERR_OK;
}

int finit_array(object_t *list, size_t nmemb, FILE *file)
{   
    int rc = ERR_OK;
    
    for (size_t i = 0; i < nmemb && rc == ERR_OK; i++)
        rc = read_object(file, &list[i]);

    if (rc == EOF)
        rc = ERR_OK;

    return rc;
}

int calc_objects(FILE *file, size_t *calc)
{   
    int rc = ERR_OK;

    object_t tmp = { 0 };

    size_t count = 0;

    while ((rc = read_object(file, &tmp)) == ERR_OK)
    {
        count++;
        free_object(&tmp);
    }

    if (rc == EOF)
        free_object(&tmp);

    if (rc != ERR_OK && rc != EOF)
        return ERR_IO;

    *calc = count + 1;

    return ERR_OK; 
}

int read_array(const char *filename, object_t **list, size_t *nmemb)
{   
    FILE *file;
   
    int rc = ERR_OK;
    size_t n = 0;

    object_t *plist = NULL;

    file = fopen(filename, "r");

    if (!file)
        return ERR_FILE;

    rc = calc_objects(file, &n);

    if (rc == ERR_OK)
        rc = create_array(&plist, n);

    if (rc == ERR_OK)
    {   
        rewind(file);

        rc = finit_array(plist, n, file);
    }

    if (rc == ERR_OK)
    {
        *list = (object_t *) plist;
        *nmemb = n;

        rc = ERR_OK;
    }
    else
        free_array(plist, n);

    fclose(file);

    return rc;
}

int print_with_prefix(const object_t *list, const size_t size, const char *prefix)
{   
    int err = ERR_OK;
 
    bool is_finded = false;

    for (size_t i = 0; i < size; i++)
    {
        if (strstr(list[i].name_object, prefix) == list[i].name_object)
        {
            print_object(&list[i]);
            is_finded = true;
        }
    }

    if (!is_finded)
        err = ERR_LIST;

    return err;
}

void print_array(const object_t *list, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        print_object(&list[i]);
}

void free_array(object_t *list, const size_t n)
{
    if (list == NULL)
        return;

    for (size_t i = 0; i < n; i++)
        free_object(&list[i]);
    
    free(list);
}
