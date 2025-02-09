#ifndef _ARR_H_
#define _ARR_H_

#include <stdlib.h>
#include <stdbool.h>

#define ERR_OK 0
#define ERR_OPERATION 1
#define ERR_ALLOC 2

#define IS_EVEN(x) ((x) % 2 == 0)

/**
 * Заполняет массив простыми числами.
 *
 * \param[in,out] arr - массив целых чисел
 * \param[in] n - размер массива
 *
 * \note Массив должен существовать.
 *
 * \return Возвращает ERR_OK или ERR_OPERATION
 */
int fill_prime(int *arr, const size_t n);

/**
 * Подсчитывает кол-во четных чисел.
 *
 * \param[in,out] arr - массив целых чисел
 * \param[in] n - размер массива
 *
 * \note Массив должен существовать.
 *
 * \return Возвращает кол-во четных чисел.
 */
size_t calc_even(int const *arr, const size_t n);

/**
 * Заполняеет массив new_arr числами из arr, добавляя число num после каждого четного числа.
 * 
 * \param[in,out] new_arr - новый массив чисел
 * \param[in,out] new_len - указатель на длину получаемого массива.
 * \param[in] arr - массив целых чисел
 * \param[in] n - размер массива
 *
 * \note Массивы должны существовать.
 *
 * \return Возвращает ERR_OK.
 */
int add_num_after_even(int *new_arr, size_t *new_len, int const *arr, const size_t n, const int num);

#endif
