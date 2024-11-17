#include "car_t_array.h"

int fread_arr_car(FILE *file, car_el_t **base_st, car_el_t **base_en)
{   
    int rc = ERR_OK, err = ERR_OK;
    size_t n = 0;

    car_el_t *p = malloc(MAX_ELEM * sizeof(car_el_t));
    
    if (!p)
    {
        *base_st = NULL;

        return ERR_ALLOC;
    }
    
    fseek(file, 0, SEEK_SET);

    while ((rc = fscanf(file, "%lu", &p->index)) == 1 && err == ERR_OK && n < MAX_ELEM + 1)
    {   
        err = read_carfrmfile(file, &p->car);    
        p++;
        n++;
    }

    if (MAX_ELEM + 1 == n)
        return ERR_OVERFLOW;
    
    if (rc != EOF)
    {   
        *base_en = NULL;
        return ERR_IO;
    }
    else
    {   
        *base_st = p - n;
        *base_en = p; 
        return ERR_OK;
    }
}

void print_arr_car(car_el_t *base_st, size_t const nmemb)
{   
    print_header(0);

    for (car_el_t *p = base_st; p < base_st + nmemb; p++)
    {   
        char strtmp[20];
        snprintf(strtmp, sizeof(strtmp), "%lu", p->index);
        print_centered(stdout, strtmp, 5);
        // printf("%-5lu", p->index);
        write_car_tofile(stdout, p->car);
    }
}

int add_arr_elem(car_el_t **base_st, size_t *nmemb)
{   
    int rc = ERR_OK;
    if (*nmemb == MAX_ELEM)
        return ERR_OVERFLOW;

    car_el_t car_el;

    car_el.index = *nmemb + 1;
    rc = get_car(&car_el.car);

    if (rc != ERR_OK)
        return rc;
    
    *(*base_st + *nmemb) = car_el;
    *nmemb += 1;

    return rc;
}

int pop_arr_elembyprice(car_el_t **base_st, size_t *nmemb, size_t const price)
{   
    int rc = ERR_OK;
    bool del = false;

    car_el_t *pcar = *base_st;

    if (*nmemb == 1 && pcar->car.price == price)
        return ERR_EMPTY;

    for (car_el_t *p = *base_st, *pcur = p + 1; pcur < *base_st + *nmemb; p++, pcur++)
    {
        if (p->car.price == price || del)
        {
            *p = *pcur;
            p->index--;
            del = true;
        }
    }
    
    pcar = *base_st + (*(nmemb) - 1);

    if (!del && pcar->car.price == price)
        del = true;

    if (del)
        *nmemb -= 1;

    return rc;
}

int filter_car_param(car_el_t *base_st, size_t const nmemb, car_el_t *arr, size_t *len, char const *mark, unsigned const price_l, unsigned const price_r)
{   
    if (price_l > price_r)
        return ERR_IO;

    size_t count = 0;
    for (car_el_t *p = base_st; p < base_st + nmemb; p++)
    {
        if (!p->car.state_new)
        {
            if (strcmp(mark, p->car.mark) == 0 && p->car.state.oldstate.owners == 1)
            {   
                if (p->car.state.oldstate.repairs == 0 && price_l <= p->car.price && price_r >= p->car.price)
                {   
                    arr[count] = *p;
                    count++;
                }
            }
        }
   }
   
    *len = count;
    
    return ERR_OK;
}

void print_garanted_car(car_el_t *arr, size_t const len)
{   
    car_el_t arr_f[MAX_ELEM];
    size_t len_f = 0;
    size_t i = 0; 
    for (car_el_t *pcar = arr; pcar < arr + len; pcar++, i++)
    {
        if (pcar->car.garanty)
        {
            arr_f[i] = *pcar;
            len_f++;
        }
    }

    if (!len_f)
    {
        printf("Нет таких вхождений\n");
        return;
    }

    print_arr_car(arr_f, len_f);
}