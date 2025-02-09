#include "check_mysort.h"
#include <stdio.h>
/*  Функция сравнивает элементы двух массивов одинаковой длины.
    Функция прринимает массивы типа int arr_l и arr_r и кол-во элементов nmemb.
*/
static int compare_arr(void const *arr_l, void const *arr_r, size_t const nmemb, size_t const size, int (*cmp)(const void *, const void *))
{   
    int rc = ERR_OK;

    for (size_t i = 0; i < nmemb && rc == ERR_OK; i++)
    {   
        if (cmp((char *) arr_l + i * size, (char *) arr_r + i * size) != 0)
            return cmp((char *) arr_l + i * size, (char *) arr_r + i * size);
    }

    return ERR_OK;
}

typedef struct el
{
    int a;

    char c;
} el_t;

/*  Компаратор для элементов типа el_t.
    Принимает указатели на элементы r, l.
    Возвращает число больше 0, если r > l, иначе если r < l, то - число меньше 0, иначе - 0.
*/
static int compare_el_t(const void *l, const void *r)
{
    el_t *el_l = (el_t *) l;
    el_t *el_r = (el_t *) r;

    if (el_l->a - el_r->a == 0)
        return el_r->c - el_l->c;
    else
        return el_l->a - el_r->a;
}

/*  Компоратор для элементов типа double.
    Принимает указатели на элементы r, l.
    Возвращает число 1, если l больше r, иначе - 0.
*/
static int compare_double(const void *l, const void *r)
{
    double *pl = (double *) l;
    double *pr = (double *) r;

    return IS_BIGGER(*pl, *pr); 
}

/*  Позитивный тест.
    Сортируется массив с 1 элементом.
*/
START_TEST(test_pos_my_sort_1_elem)
{
    int arr[] = { 1 };
    int expect[] = { 1 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется массив с 2 элементами.
*/
START_TEST(test_pos_my_sort_2_elems)
{
    int arr[] = { 2, 1 };
    int expect[] = { 1, 2 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется массив с отриц. элементами.
*/
START_TEST(test_pos_my_sort_withneg_elems)
{
    int arr[] = { 2, -1, 3 };
    int expect[] = { -1, 2, 3 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется отсорт. массив.
*/
START_TEST(test_pos_my_sort_sorted_elems)
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int expect[] = { 1, 2, 3, 4, 5 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется развернутый массив.
*/
START_TEST(test_pos_my_sort_reversorted_elems)
{
    int arr[] = { 6, 5, 4, 3, 2, 1 };
    int expect[] = { 1, 2, 3, 4, 5, 6 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется неотсорт. массив.
*/
START_TEST(test_pos_my_sort_unsorted_elems)
{
    int arr[] = { 1, 3, 5, -3, 4, 6, 7 };
    int expect[] = { -3, 1, 3, 4, 5, 6, 7 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется наполовину отсорт. массив.
*/
START_TEST(test_pos_my_sort_halfsorted_elems)
{
    int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
    int expect[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(int), compare_int);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(int), compare_int));
}
END_TEST

/*  Позитивный тест.
    Сортируется неотсорт. массив структур.
*/
START_TEST(test_pos_my_sort_unsorted_elems_el_t)
{
    el_t arr[] = { { 1, 'a'}, { 0, 'b' }, { 1, 'b' } };
    el_t expect[] = { { 0, 'b' }, { 1, 'b' }, { 1, 'a'} };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(el_t), compare_el_t);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(el_t), compare_el_t));
}
END_TEST

/*  Позитивный тест.
    Сортируется отсорт. массив структур.
*/
START_TEST(test_pos_my_sort_sorted_elems_el_t)
{
    el_t arr[] = { { 0, 'b' }, { 1, 'b' }, { 1, 'a'}, { 2, 'c'} };
    el_t expect[] = { { 0, 'b' }, { 1, 'b' }, { 1, 'a'}, { 2, 'c'} };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(el_t), compare_el_t);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(el_t), compare_el_t));
}
END_TEST

/*  Позитивный тест.
    Сортируется наполовину отсорт. массив вещественных чисел.
*/
START_TEST(test_pos_my_sort_halfsorted_doubles)
{
    double arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
    double expect[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(double), compare_double);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(double), compare_double));
}
END_TEST

/*  Позитивный тест.
    Сортируется неотсорт. массив вещественных чисел.
*/
START_TEST(test_pos_my_sort_unsorted_doubles)
{
    double arr[] = { 1, 3, 5, -3, 4, 6, 7 };
    double expect[] = { -3, 1, 3, 4, 5, 6, 7 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(double), compare_double);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(double), compare_double));
}
END_TEST

/*  Позитивный тест.
    Сортируется отсорт. массив вещественных чисел.
*/
START_TEST(test_pos_my_sort_sorted_doubles)
{
    double arr[] = { 1, 2, 3, 4, 5 };
    double expect[] = { 1, 2, 3, 4, 5 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, n, sizeof(double), compare_double);

    ck_assert_int_eq(ERR_OK, compare_arr(arr, expect, n, sizeof(double), compare_double));
}
END_TEST

Suite *mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_pos_my_sort_1_elem);
    tcase_add_test(tc_pos, test_pos_my_sort_2_elems);
    tcase_add_test(tc_pos, test_pos_my_sort_withneg_elems);
    tcase_add_test(tc_pos, test_pos_my_sort_sorted_elems);
    tcase_add_test(tc_pos, test_pos_my_sort_reversorted_elems);
    tcase_add_test(tc_pos, test_pos_my_sort_unsorted_elems);
    tcase_add_test(tc_pos, test_pos_my_sort_halfsorted_elems);
    tcase_add_test(tc_pos, test_pos_my_sort_unsorted_elems_el_t);
    tcase_add_test(tc_pos, test_pos_my_sort_sorted_elems_el_t);
    tcase_add_test(tc_pos, test_pos_my_sort_halfsorted_doubles);
    tcase_add_test(tc_pos, test_pos_my_sort_unsorted_doubles);
    tcase_add_test(tc_pos, test_pos_my_sort_sorted_doubles);
    suite_add_tcase(s, tc_pos);

    return s;
}

int mysort_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = mysort_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}