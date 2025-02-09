#include <string.h>
#include <math.h>

#include "check_comparators.h"

/*  Компаратор сравнивающий элементы типа object_t.
    Принимает указатели на l, r.
    Возвращает 0, если равны, иначе - код ошибки сравнивания.
*/
int compare_object_t(const void *l, const void *r)
{   
    object_t *l_ob = (object_t *) l;
    object_t *r_ob = (object_t *) r;

    if (fabs(l_ob->mass - r_ob->mass) < EPS)
    {
        if (fabs(l_ob->volume - r_ob->volume) < EPS)
        {
            if (strcmp(l_ob->name_object, r_ob->name_object) == 0)
                return ERR_OK;
        }
    }

    return ERR_EQUAL;
}

/*  Функция сравнивает элементы массивов.
    Функция принимает массивы l и r, их размер n, размер элемента size, компаратор cmp(const *void, const *void).
    Возвращает не 0, если элементы не равны, иначе 0.
*/
int compare_arr(const void *l, const void *r, const size_t n, const size_t size, int (*cmp)(const void*, const void*))
{
    for (size_t i = 0; i < n; i++)
        if (cmp((char *) l + i * size, (char *) r + i * size))
            return cmp((char *) l + i * size, (char *) r + i * size);

    return ERR_OK;
}
