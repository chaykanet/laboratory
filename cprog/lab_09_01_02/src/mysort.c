#include "mysort.h"

static void swap(object_t *first, object_t *second)
{   
    char tmp[sizeof(object_t)];

    memmove(tmp, first, sizeof(object_t));
    memmove(first, second, sizeof(object_t));
    memmove(second, tmp, sizeof(object_t));
}

void sort_array(object_t *list, size_t const nmemb)
{   
    for (size_t i = 0; i < nmemb; i++)
    {
        for (size_t j = 0; j < nmemb - 1 - i; j++)
        {  
            if (compare_density(&list[j], &list[j + 1]) > 0)
                swap(&list[j], &list[j + 1]);
        }
    }
}
