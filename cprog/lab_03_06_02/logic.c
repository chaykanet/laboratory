#include "logic.h"

/*  Функция осуществляет заполнение столбца снизу вверх, если значение аргумента reverse = true,
    иначе заполняет столбец сверху вниз.
    Функция принимает матрицу, кол-во строк, кол-во столбцов.
*/
void input_down_up(int (*mat)[N], size_t n, size_t index, size_t *num, bool reverse)
{   
    if (reverse)
    {    
        for (size_t i = n; i > 0; i--)
        {
            mat[i - 1][index] = *num;
            *num += 1;
        }
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            mat[i][index] = *num;
            *num += 1;
        }
    }
}

/*  Функция осуществляет заполнение матрицы методом "хода быка", начиная с последнего элемента.
    Функция принимает матрицу, кол-во строк, кол-во столбцов.
*/
void input_step_bull(int (*mat)[M], size_t n, size_t m)
{   
    size_t i = m;
    size_t num = 1;
    size_t ost = m % DIV_TWO;

    while (i > 0)
    {
        if (i % DIV_TWO == ost)
            input_down_up(mat, n, i - 1, &num, true);
        else
            input_down_up(mat, n, i - 1, &num, false);

        --i;
    }
}
