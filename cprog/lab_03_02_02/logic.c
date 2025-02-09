#include "logic.h"

/*  Находит сумму цифр этого числа.
    Возвращает эту сумму.
    Функция принимает число num.
*/
int calc_digit_sum(int const num)
{
    int tmp = abs(num);
    int sum = 0;
    while (tmp != 0)
    {
        sum += tmp % DIV_BY_TEN;
        tmp /= DIV_BY_TEN;
    }

    return sum;
}

/*  Функция подсчитывает кол-во чисел, сумма цифр которых нечетна.
    Возвращает кол-во чисел.
    Функция принимает одномерный массив row, его размер m.
*/
size_t calc_needed_num(int const *row, size_t const m)
{   
    size_t i = 0;
    size_t count = 0;

    while (i < m && count != TWO_ELEMENTS)
    {
        if (calc_digit_sum(row[i]) % DIV_BY_TWO != 0)
            ++count;
        ++i;
    }

    return count;
}

/*  Функция присваивает элементы одного массива другому.
    Функция принимает два массива arr1, arr2 и их размер m.
*/
void assign_arr(int *arr1, int const *arr2, size_t m)
{
    for (size_t i = 0; i < m; i++)
        arr1[i] = arr2[i];
}

/*  Добавлет в матрицу строку row на нужный индекс строки.
    Функция принимает матрицу, размеры матрицы n, m, строку row, индекс строки.
*/
void insert_row(int (*mat)[M], size_t *m_n, size_t const m, int *row, size_t const index)
{   
    *m_n += 1;
    for (size_t i = *m_n - 1; i > index; i--)
        assign_arr(mat[i], mat[i - 1], m);

    assign_arr(mat[index], row, m);
}

/*  Формирует новую матрицу. Добавлет строку из -1, если
    в последующей строке есть 2 элемента, сумма цифр которых нечетна.
    Возвращает новую матрицу, ее кол-во строк, ее кол-во столбцов.
    Функция принимает новую матрицу, ее кол-во строк, ее кол-во столбцов,
    матрицу, ее кол-во строк, ее кол-во столбцов.
*/
void add_neg_row_matrix(int (*mat)[M], size_t *n, size_t const m)
{   
    int neg_row[N] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    for (size_t i = 0; i < *n; i++)
    {   
        if (calc_needed_num(mat[i], m) == TWO_ELEMENTS)
        {   
            insert_row(mat, n, m, neg_row, i);
            i++;
        }
    }
}
