#include "arr.h"
#include <stdio.h>

/**
 * Возвращает true, если num четное, иначе - false.
 *
 * \param[in] num - проверяемое число
 *
 * \return Возвращает true или false.
 */
static bool is_prime(int num)
{
    if (num <= 1) 
        return false;
    
    if (num <= 3) 
        return true; 

    if (num % 2 == 0 || num % 3 == 0) 
        return false;

    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) 
            return false;

    return true;
}

/**
 * Находит следующее простое число.
 *
 * \param[in] prev - предыдущее простое число
 *
 * \return Возвращает следующее простое число.
 */
static int next_prime(int const prev)
{
    int num = prev + 1;

    while (!is_prime(num))
        num++;

    return num;
}

int fill_prime(int *arr, const size_t n)
{   
    if (arr == NULL)
        return ERR_OPERATION;
    
    if (n == 0)
        return ERR_OPERATION;
    
    int prime = 2;

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = prime;
        
        prime = next_prime(prime);
    }

    return ERR_OK;
}

size_t calc_even(int const *arr, const size_t n)
{   
    size_t calc = 0;

    for (size_t i = 0; i < n; i++)
        if (IS_EVEN(arr[i]))
            calc++;

    return calc;
}

int add_num_after_even(int *new_arr, size_t *new_len, int const *arr, const size_t n, const int num)
{
    size_t index = 0;

    size_t calc = 0;

    for (size_t i = 0; i < n; i++) 
    {
        new_arr[index++] = arr[i]; 

        if (IS_EVEN(arr[i]))
        {
            new_arr[index++] = num;

            calc++;
        }
    }

    *new_len = n + calc;

    return ERR_OK;
}
