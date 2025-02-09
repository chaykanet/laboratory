#include "check_comparators.h"

int compare_arr(double const *arr_l, const double *arr_r, const size_t nmemb)
{   
    int rc = ERR_OK;

    for (size_t i = 0; i < nmemb && rc == ERR_OK; i++)
        if (fabs(arr_l[i] - arr_r[i]) >= EPS)
            return ERR_EQUAL;

    return ERR_OK;
}

int compare_mat(double **mat_l, const size_t n_l, const size_t m_l, double **mat_r, const size_t n_r, const size_t m_r)
{   
    if (n_l != n_r || m_l != m_r)
        return ERR_EQUAL;

    for (size_t i = 0; i < n_l; i++)
        if (compare_arr(mat_l[i], mat_r[i], m_l) != ERR_OK)
            return ERR_EQUAL;

    return ERR_OK;
}
