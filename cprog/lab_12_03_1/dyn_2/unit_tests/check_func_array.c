#include <check.h>
#include <stdlib.h>
#include "mysort.h"
#include "check_func_array.h"

/*  Функция сравнивает элементы двух массивов одинаковой длины.
    Функция прринимает массивы arr_l и arr_r и кол-во элементов nmemb.
*/
static int compare_arr(int const *arr_l, int const *arr_r, size_t const nmemb)
{   
    int rc = ERR_OK;

    for (size_t i = 0; i < nmemb && rc == ERR_OK; i++)
    {   
        if (compare_int(arr_l + i, arr_r + i) != 0)
            return arr_l[i] - arr_r[i];
    }

    return ERR_OK;
}

/* Негативный тест для фильтра.
   В массиве 0 элементов.
*/
START_TEST(test_neg_key_0_elems)
{
    int rc;
    int arr[] = { 0 };
    int *p_en = arr + 0;

    int *pb_dst = NULL, *pe_dst = NULL;

    rc = key(arr, p_en, pb_dst, &pe_dst);

    free((int *) pb_dst);

    ck_assert_int_eq(rc, ERR_EMPTY);
}
END_TEST

/* Позитивный тест для фильтра.
   В массиве 0 негативных элементов.
*/
START_TEST(test_pos_key_0_neg_elems)
{
    int rc;
    int arr[] = { 6, 5, 4, 3, 2 };
    int exp[] = { 6, 5, 4, 3, 2 };
    int tmp[] = { 0, 0, 0, 0, 0 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);

    int *p_en = arr + n;

    int *pb_dst = NULL, *pe_dst = NULL;

    pb_dst = malloc(sizeof(int) * n_ex);

    rc = key(arr, p_en, pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_OK);

    size_t n_k = pe_dst - pb_dst;

    memcpy(tmp, pb_dst, n_k * sizeof(int));

    free((int *) pb_dst);

    ck_assert_uint_eq(n_ex, n_k);

    ck_assert_int_eq(compare_arr(tmp, exp, n_ex), ERR_OK);
}
END_TEST

/* Негативный тест для фильтра.
   В массиве первый негативных элемент.
*/
START_TEST(test_neg_key_1_neg_start_elem)
{
    int rc;
    int arr[] = { -6, 5, 4, 3, 2, 1 };
    
    size_t n = sizeof(arr) / sizeof(arr[0]);

    int *p_en = arr + n;

    int *pb_dst = NULL, *pe_dst = NULL;

    rc = key(arr, p_en, pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_EMPTY);
}
END_TEST

/* Позитивный тест для фильтра.
   В массиве второй негативных элемент.
*/
START_TEST(test_pos_key_1_neg_second_elem)
{
    int rc;
    int arr[] = { 6, -5, 4, 3, 2, 1, 0 };
    int exp[] = { 6 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);

    int tmp[] = { 0 };

    int *p_en = arr + n;

    int *pb_dst = NULL, *pe_dst = NULL;

    pb_dst = malloc(sizeof(int) * n_ex);

    rc = key(arr, p_en, pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_OK);

    size_t n_k = pe_dst - pb_dst;

    memcpy(tmp, pb_dst, n_k * sizeof(int));

    free((int *) pb_dst);

    ck_assert_uint_eq(n_ex, n_k);

    ck_assert_int_eq(compare_arr(tmp, exp, n_ex), ERR_OK);
}
END_TEST

/* Позитивный тест для фильтра.
   В массиве 2 негативных элемента.
*/
START_TEST(test_pos_key_2_neg_elems)
{
    int rc;
    int arr[] = { 6, -5, 4, 3, -2, 1, 0 };
    int exp[] = { 6, -5, 4, 3 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);

    int tmp[] = { 0, 0, 0, 0 };

    int *p_en = arr + n;

    int *pb_dst = NULL, *pe_dst = NULL;

    pb_dst = malloc(sizeof(int) * n_ex);

    rc = key(arr, p_en, pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_OK);

    size_t n_k = pe_dst - pb_dst;

    memcpy(tmp, pb_dst, n_k * sizeof(int));

    free((int *) pb_dst);

    ck_assert_uint_eq(n_ex, n_k);

    ck_assert_int_eq(compare_arr(tmp, exp, n_ex), ERR_OK);
}
END_TEST

/* Позитивный тест для фильтра.
   В массиве 2 негативных элемента рядом.
*/
START_TEST(test_pos_key_2_neg_next_elems)
{
    int rc;
    int arr[] = { 6, -5, -4, 3, 2, 1 };
    int exp[] = { 6, -5 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);

    int tmp[] = { 0, 0 };

    int *p_en = arr + n;

    int *pb_dst = NULL, *pe_dst = NULL;

    pb_dst = malloc(sizeof(int) * n_ex);

    rc = key(arr, p_en, pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_OK);

    size_t n_k = pe_dst - pb_dst;

    memcpy(tmp, pb_dst, n_k * sizeof(int));

    free((int *) pb_dst);

    ck_assert_uint_eq(n_ex, n_k);

    ck_assert_int_eq(compare_arr(tmp, exp, n_ex), ERR_OK);
}
END_TEST

/* Позитивный тест для фильтра.
   В массиве все негативные элементы.
*/
START_TEST(test_pos_key_all_neg_elems)
{
    int rc;
    int arr[] = { -6, -5, -4, -3, -2, -1 };
    int exp[] = { -6, -5, -4, -3, -2 };
    
    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);
    
    int tmp[] = { 0, 0, 0, 0, 0 };
    
    int *p_en = arr + n;

    int *pb_dst = NULL, *pe_dst = NULL;

    pb_dst = malloc(sizeof(int) * n_ex);

    rc = key(arr, p_en, pb_dst, &pe_dst);

    ck_assert_int_eq(rc, ERR_OK);

    size_t n_k = pe_dst - pb_dst;

    memcpy(tmp, pb_dst, n_k * sizeof(int));

    free((int *) pb_dst);

    ck_assert_uint_eq(n_ex, n_k);

    ck_assert_int_eq(compare_arr(tmp, exp, n_ex), ERR_OK);
}
END_TEST

/* Позитивный тест для функции arrscanf_toarray.
   Массивы одинаковой длины.
*/
START_TEST(test_pos_arrscanf_tofile_eq_arrs)
{
    int arr1[] = { 1, 2, 3, 4, 5, 6 };
    int arr2[] = { 6, 5, 4, 3, 2, 1 };

    size_t n_1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t n_2 = sizeof(arr2) / sizeof(arr2[0]);

    ck_assert_int_eq(ERR_OK, arrcopy_toarray(arr1, arr1 + n_1, arr2, arr2 + n_2));

    ck_assert_int_eq(ERR_OK, compare_arr(arr1, arr2, n_1));
}

/* Позитивный тест для функции arrscanf_toarray.
   Принимающий массив меньше.
*/
START_TEST(test_pos_arrscanf_tofile_arr1_lt_arr2)
{
    int arr1[] = { 1, 2, 3, 4 };
    int arr2[] = { 6, 5, 4, 3, 2, 1 };

    int exp[] = { 6, 5, 4, 3 };

    size_t n_1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t n_2 = sizeof(arr2) / sizeof(arr2[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);

    ck_assert_int_eq(ERR_OK, arrcopy_toarray(arr1, arr1 + n_1, arr2, arr2 + n_2));

    ck_assert_int_eq(ERR_OK, compare_arr(arr1, exp, n_ex));
}

/* Позитивный тест для функции arrscanf_toarray.
   Принимающий массив из 1 элемента.
*/
START_TEST(test_pos_arrscanf_tofile_arr1_1elem_arr2)
{
    int arr1[] = { 1 };
    int arr2[] = { 6, 5, 4, 3, 2, 1 };

    int exp[] = { 6 };

    size_t n_1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t n_2 = sizeof(arr2) / sizeof(arr2[0]);
    size_t n_ex = sizeof(exp) / sizeof(exp[0]);

    ck_assert_int_eq(ERR_OK, arrcopy_toarray(arr1, arr1 + n_1, arr2, arr2 + n_2));

    ck_assert_int_eq(ERR_OK, compare_arr(arr1, exp, n_ex));
}

/* Негативный тест для функции arrscanf_toarray.
   Принимающий массив из 0 элементов.
*/
START_TEST(test_neg_arrscanf_tofile_arr1_0elem_arr2)
{
    int arr1[] = { 0 };
    int arr2[] = { 6, 5, 4, 3, 2, 1 };

    size_t n_2 = sizeof(arr2) / sizeof(arr2[0]);

    ck_assert_int_eq(ERR_COPY, arrcopy_toarray(arr1, arr1 + 0, arr2, arr2 + n_2));
}

/* Негативный тест для функции arrscanf_toarray.
   Принимающий массив больше.
*/
START_TEST(test_neg_arrscanf_tofile_arr1_gt_arr2)
{
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
    int arr2[] = { 6, 5, 4, 3, 2, 1 };

    size_t n_1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t n_2 = sizeof(arr2) / sizeof(arr2[0]);

    ck_assert_int_eq(ERR_COPY, arrcopy_toarray(arr1, arr2, arr1 + n_1, arr2 + n_2));
}

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    
    s = suite_create("key");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_neg_key_0_elems);
    tcase_add_test(tc_neg, test_neg_key_1_neg_start_elem);

    suite_add_tcase(s, tc_neg);

    tcase_add_test(tc_pos, test_pos_key_0_neg_elems);
    tcase_add_test(tc_pos, test_pos_key_1_neg_second_elem);
    tcase_add_test(tc_pos, test_pos_key_2_neg_elems);
    tcase_add_test(tc_pos, test_pos_key_2_neg_next_elems);
    tcase_add_test(tc_pos, test_pos_key_all_neg_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}

Suite *arrscan_toarray_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    
    s = suite_create("arrscan_toarray");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_neg_arrscanf_tofile_arr1_0elem_arr2);
    tcase_add_test(tc_neg, test_neg_arrscanf_tofile_arr1_gt_arr2);

    suite_add_tcase(s, tc_neg);

    tcase_add_test(tc_pos, test_pos_arrscanf_tofile_eq_arrs);
    tcase_add_test(tc_pos, test_pos_arrscanf_tofile_arr1_lt_arr2);
    tcase_add_test(tc_pos, test_pos_arrscanf_tofile_arr1_1elem_arr2);

    suite_add_tcase(s, tc_pos);

    return s;
}

int key_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = key_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int arrscan_toarray_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = arrscan_toarray_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
