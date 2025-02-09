#include "logic.h"

/*  Возвращает true, если число оканчивается на 5,
    иначе false
    Функция принимает число num.
*/
bool is_end_five(int const num)
{
    int tmp = abs(num);

    if (tmp % DIV_BY_TEN == FIVE)
        return true;
    else
        return false;
}

/*  Функция находит максимальный элемент, оканчивающийся на 5 под побочной диагональю
    Возвращет максимальны элемент и код шибки нахождения.
    Функция принимает квадратную матрицу mat, ее размер n, адрес переменной max.
*/
int find_max_un_sec_diagonal(int (*mat)[M], size_t const n, int *max)
{
    bool not_finded = true;

    for (size_t i = 0; i < n; i++)
        for (size_t j = n - 1; j > n - 1 - i; j--)
        {
            if (is_end_five(mat[i][j]) && not_finded)
            {
                *max = mat[i][j];
                not_finded = false;
            }

            if (is_end_five(mat[i][j]) && !(not_finded))
                if (mat[i][j] > *max)
                    *max = mat[i][j];
        }
    
    if (not_finded)
        return NOT_FINDED;
    else    
        return FINDED;
}
