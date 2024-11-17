#include "car_key_t.h"
#include "car_t_arr_sort.h"

int cmp_car_price(void const *l, void const *r)
{
    car_el_t *car_l = (car_el_t *) l;
    car_el_t *car_r = (car_el_t *) r;

    return car_l->car.price - car_r->car.price; 
}

int cmp_key_price(void const *l, void const *r)
{
    ckey_t *key_l = (ckey_t *) l;
    ckey_t *key_r = (ckey_t *) r;

    return key_l->price - key_r->price; 
}

static void swop_elem(void *l, void *r, size_t size)
{
    char tmp[MAX_BITES];
    memcpy(tmp, l, size);
    memcpy(l, r, size);
    memcpy(r, tmp, size);
}

void qsort_arr(void *base_st, size_t const nmemb, size_t const size, int (*cmp)(void const *,void const *))
{   
    if (!nmemb)
        return;
        
    size_t index_i = nmemb - 1, prev_index = nmemb - 1;
    
    while (index_i > 0)
    {   
        char *p_i = (char *) base_st + index_i * size;
    
        for (char *pcur = (char *) base_st + size, *prev = (char *) base_st; pcur < p_i + size; pcur += size, prev +=size)
        {
            if (cmp(prev, pcur) > 0)
            {
                swop_elem(prev, pcur, size);
                index_i = ((char *) prev - (char *) base_st) / size;
            }
        }

        if (prev_index == index_i)
            index_i = 0;

        prev_index = index_i;
    } 
}

void sort_arr(void *base_st, void *base_en, size_t const nmemb, size_t const size, int (*cmp)(void const *,void const *))
{
    if (!nmemb)
        return;

    for (char *pi = (char *) base_st; pi < (char *) base_st + nmemb * size; pi += size)
        for (char *pj = (char *) base_st; pj < (char *) base_en - size; pj += size)
            if (cmp(pj, pj + size) > 0)
                swop_elem(pj, pj + size, size);
}
