#include "mysort.h"

/*  Функция меняет местами элементы.
    Принимает указатели на элементы r, l и их размер size.
*/
static void swap_elem(void *r, void *l, size_t const size)
{
    char tmp[size];
    memcpy(tmp, r, size);
    memcpy(r, l, size);
    memcpy(l, tmp, size);
}

int compare_int(const void *r, const void *l)
{
    const int *pr = r;
    const int *pl = l;

    return *pr - *pl;
}

// Защита. Сортировка выбором.
void mysort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *))
{   
    char *min_elem;

    for (char *pcur = (char *) base; pcur < (char *) base + size * nmemb; pcur += size)
    {
        min_elem = pcur;

        for (char *p = pcur; p < (char *) base + size * nmemb; p += size)
            if (cmp(min_elem, p) > 0)
                min_elem = p;
        
        swap_elem(pcur, min_elem, size);        
    } 
}

// Cортировка пузырьком.
// void mysort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *))
// {
//     char *pi = (char *) base + nmemb * size - size;
//     char *pv = pi;
    
//     while (pi > (char *) base)
//     {   
//         char *p_i = pi;
    
//         for (char *pcur = (char *) base + size, *prev = base; pcur < p_i + size; pcur += size, prev += size)
//         {
//             if (cmp(prev, pcur) > 0)
//             {
//                 swap_elem(prev, pcur, size);
//                 pi = (char *) base + (pcur - (char*) base - size);
//             }
//         }

//         if (pv == pi)
//             pi = (char *) base;

//         pv = pi;
//     } 
// }
