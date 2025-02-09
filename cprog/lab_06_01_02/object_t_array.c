#include "limits.h"
#include "object_t_array.h"
#include "errcodes.h"

/*  Функция меняет местами значения объектов.
*/
static void swap(struct object_t *first, struct object_t *second);

int read_array(char const *filename, struct object_t *list, size_t *size, size_t const max_size)
{   
    FILE *txt;
    int err = ERR_OK;
    struct object_t tmp;

    txt = fopen(filename, "r");

    if (txt)
    {        
        size_t tmpsize = 0;
        
        while ((err = read_object(txt, &tmp)) == ERR_OK)
        {   
            if (tmpsize < max_size)
                list[tmpsize] = tmp;
                    
            ++tmpsize;
        }
        
        if (err == EOF && tmpsize < max_size)
        {   
            list[tmpsize] = tmp;
            ++tmpsize;
            *size = tmpsize;
        }
        else
            err = ERR_DATA;

        fclose(txt);
    }
    else
        err = ERR_IO; 
    
    if (err == EOF)
        err = ERR_OK;

    return err;
}

void sort_array(struct object_t *list, size_t const size)
{   
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {  
            if (compare_density(&list[j], &list[j + 1]) > 0)
                swap(&list[j], &list[j + 1]);
        }
    }
}

int print_with_prefix(struct object_t const *list, size_t const size, char const *prefix)
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

void swap(struct object_t *first, struct object_t *second)
{   
    struct object_t tmp = *first;
    *first = *second;
    *second = tmp;
}


void print_array(struct object_t const *list, size_t const size)
{
    for (size_t i = 0; i < size; i++)
        print_object(&list[i]);
}
