#include "car_key_t.h"

int get_keys(ckey_t **key_st, ckey_t **key_en, car_el_t *base_st, size_t const nmemb)
{   
    if (!nmemb)
        return ERR_EMPTY;
        
    *key_st = malloc((nmemb) * sizeof(ckey_t));

    ckey_t *pkey = *key_st;

    if (!key_st)
        return ERR_ALLOC;

    for (car_el_t *p = base_st; p < base_st + nmemb; p++, pkey++)
    {
        pkey->index = p->index;
        pkey->price = p->car.price;
    }

    *key_en = pkey;

    return ERR_OK;
}

void print_arr_withkey(car_el_t *base_st, car_el_t *base_en, ckey_t *key_st, ckey_t *key_en)
{   
    if (base_en - base_st != key_en - key_st)
        return;
        
    printf("Вывод таблицы по отсортированным ключам:\n");
    
    print_header(0);

    for (ckey_t *pkey = key_st; pkey < key_en; pkey++)
    {   
        char strtmp[20];
        snprintf(strtmp, sizeof(strtmp), "%lu", pkey->index);
        print_centered(stdout, strtmp, 5);

        car_el_t *p = base_st + pkey->index - 1;

        write_car_tofile(stdout, p->car);
    }
}

void print_keys(ckey_t *key_st, ckey_t *key_en)
{
    print_header(1);
    char strtmp[30];
    for (ckey_t *key = key_st; key < key_en; key++)
    {   
        snprintf(strtmp, sizeof(strtmp), "%lu", key->index);
        print_centered(stdout, strtmp, 5);

        snprintf(strtmp, sizeof(strtmp), "%u", key->price);
        print_centered(stdout, strtmp, 20);
        fprintf(stdout, "\n");
    }
}
