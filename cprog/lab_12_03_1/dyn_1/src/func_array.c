#include "func_array.h"

int fread_toarray(FILE *file, int *const base_st, int *const base_en)
{   
    int rc = ERR_OK;

    int *p = base_st;

    while ((rc = fscanf(file, "%d", p)) == 1 && p < base_en)
        ++p;
    
    return rc;
}

int arrcopy_toarray(int *const pb_dst, int *const pe_dst, int *const pb_src, int *const pe_src)
{   
    if (pb_dst == pe_dst)
        return ERR_COPY;

    if ((pe_src - pb_src) < (pb_dst - pe_dst))
        return ERR_COPY;
    
    memcpy(pb_dst, pb_src, (pe_dst - pb_dst) * sizeof(int));
    // for (int const *pcur = pb_src; pcur < pe_src && p < pe_dst; pcur++, p++)
    //     *p = *pcur;
    
    return ERR_OK;
}

int read_array(char *filename, int **p_st, int **p_en)
{   
    int rc = ERR_OK;
    
    size_t n = 0;

    FILE *file = NULL; 
    
    file = fopen(filename, "r");

    if (!file)
    {   
        *p_st = NULL;
        return ERR_FILE;
    }

    rc = calc_size_array(file, &n);

    if (rc == ERR_OK && n > 0)
    {    
        int *p = malloc(n * sizeof(int));
        
        if (p)
        {   
            *p_st = p;

            *p_en = p + n;
            rewind(file);
            rc = fread_toarray(file, *p_st, *p_en);

            if (rc == EOF)
                rc = ERR_OK;
            else
                rc = ERR_IO;
        }
        else
            rc = ERR_ALLOC;
    }
    else if (n == 0)
    {   
        *p_st = NULL;
        rc = ERR_EMPTY;
    }
    else
        *p_st = NULL;

    fclose(file);

    return rc;   
}

int calc_size_array(FILE *file, size_t *n)
{   
    int rc = ERR_OK;
    int tmp, tmp_n = 0;

    if (file)
    {
        fseek(file, 0, SEEK_SET);

        while ((rc = fscanf(file, "%d", &tmp)) == 1)
            ++tmp_n;

        if (rc == EOF)
        {
            *n = tmp_n;
            rc = ERR_OK;
        }
        else
            rc = ERR_IO;
    }
    else
        rc = ERR_FILE;

    return rc; 
}

int outputarray_tofile(char *filename, int const *p_st, int const *p_en)
{   
    int rc = ERR_OK;
    FILE *file = fopen(filename, "w");

    if (file)
    {   
        int res = 1;
        for (int const *pcur = p_st; pcur < p_en && res >= 1; pcur++)
            res = fprintf(file, "%d ", *pcur);

        fclose(file);
        
        if (res < 1)
            rc = ERR_IO;
    }
    else
        rc = ERR_FILE;

    return rc;
}
/*
    Защита. Функция находит указатель на последний отрицательный элемент.
    Принимает указатели на начало и конец массива.
    Возвращает указатель на негативый элемент. Если его нет, то - NULL. 
*/
static int *find_last_neg(int const *pb_src, int const *pe_src)
{
    int *p_neg = NULL;

    for (int const *pcur = pb_src; pcur < pe_src; pcur++)
    {
        if (*pcur < 0)
            p_neg = (int *) pcur;
    }

    return p_neg;
}

int key(const int *pb_src, const int *pe_src, const int **pb_dst, const int **pe_dst)
{   
    int rc = ERR_OK;

    if (pb_src == pe_src)
    {   
        *pb_dst = NULL;
        return ERR_EMPTY;
    }
    
    int *p_neg = NULL;

    p_neg = find_last_neg(pb_src, pe_src);

    // int const *p_neg = NULL;
    // size_t new_len = 0;

    // for (int const *pcur = pb_src; pcur < pe_src; pcur++)
    // {
    //     if (*pcur < 0)
    //         p_neg = pcur;
    // }

    if (!p_neg)
        p_neg = (int *) pe_src;
    else if (p_neg == pb_src)
    {   
        *pb_dst = NULL;
        return ERR_EMPTY;
    }
    size_t new_len = 0;
    new_len = p_neg - pb_src;
    
    int *p = malloc(sizeof(int) * new_len);

    if (!p)
        return ERR_ALLOC;

    int *pe = p + new_len;
    
    rc = arrcopy_toarray(p, pe, (int *) pb_src, (int *) p_neg);
    
    *pb_dst = p;
    *pe_dst = pe;

    return rc;
}
