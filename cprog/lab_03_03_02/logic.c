#include "logic.h"

void swap(int *row1, int *row2, size_t const m)
{
    int tmp;
    for (size_t i = 0; i < m; i++)
    {
        tmp = row1[i];
        row1[i] = row2[i];
        row2[i] = tmp;
    }
}

int multy_arr(int const *arr, size_t const m)
{
    int multy = 1;

    for (size_t i = 0; i < m; i++)
        multy *= arr[i];

    return multy;
}

void sort_matrix(int (*mat)[M], size_t n, size_t m)
{
    for (size_t i = n - 1; i > 0; i--)
        for (size_t j = 0; j < i; j++)
            if (multy_arr(mat[j], m) > multy_arr(mat[j + 1], m))
                swap(mat[j], mat[j + 1], m);
}
