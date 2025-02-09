#include "check_arr.h"

#define ERR_OK 0
#define ERR_EQUAL 1

/// Тесты для функции fill_prime ///

/*  Позитивный тест.
    Массив длины 1.
*/
START_TEST(test_pos_fill_prime_arr_size_1)
{
    int arr[] = { 10 };

    int exp[] = { 2 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(arr) / sizeof(arr[0]);

    int rc = fill_prime(arr, n);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив длины 2.
*/
START_TEST(test_pos_fill_prime_arr_size_2)
{
    int arr[] = { 10, 9 };

    int exp[] = { 2, 3 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(arr) / sizeof(arr[0]);

    int rc = fill_prime(arr, n);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив четное кол-во элементов.
*/
START_TEST(test_pos_fill_prime_arr_size_even)
{
    int arr[] = { 1, 2, 3, 4 };

    int exp[] = { 2, 3, 5, 7 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(arr) / sizeof(arr[0]);

    int rc = fill_prime(arr, n);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив нечетное кол-во элементов.
*/
START_TEST(test_pos_fill_prime_arr_size_odd)
{
    int arr[] = { 1, 2, 3, 4, 5 };

    int exp[] = { 2, 3, 5, 7, 11 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(arr) / sizeof(arr[0]);

    int rc = fill_prime(arr, n);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Негативный тест.
    Массив NULL.
*/
START_TEST(test_neg_fill_prime_arr_null)
{
    int *arr = NULL;

    size_t n = 1;

    int rc = fill_prime(arr, n);

    ck_assert_int_eq(ERR_OPERATION, rc);
}
END_TEST

/*  Негативный тест.
    Размер массива 0.
*/
START_TEST(test_neg_fill_prime_arr_size_0)
{
    int arr[] = { 1, 2 };

    size_t n = 0;

    int rc = fill_prime(arr, n);

    ck_assert_int_eq(ERR_OPERATION, rc);
}
END_TEST

Suite *fill_prime_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    
    s = suite_create("fill_prime");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_neg_fill_prime_arr_null);
    tcase_add_test(tc_neg, test_neg_fill_prime_arr_size_0);

    suite_add_tcase(s, tc_neg);

    tcase_add_test(tc_pos, test_pos_fill_prime_arr_size_1);
    tcase_add_test(tc_pos, test_pos_fill_prime_arr_size_2);
    tcase_add_test(tc_pos, test_pos_fill_prime_arr_size_even);
    tcase_add_test(tc_pos, test_pos_fill_prime_arr_size_odd);

    suite_add_tcase(s, tc_pos);

    return s;
}

int fill_prime_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = fill_prime_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


/// Тесты для функции add_num_after_even ///

/*  Позитивный тест.
    Массив длины 1, число четное.
*/
START_TEST(test_pos_add_num_after_even_arr_size_1_even)
{
    int arr[] = { 2 };

    int new_arr[] = { 0, 0 };

    int exp[] = { 2, 0 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);

    int num = 0;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив длины 1, число нечетное.
*/
START_TEST(test_pos_add_num_after_even_arr_size_1_odd)
{
    int arr[] = { 1 };

    int new_arr[] = { 0 };

    int exp[] = { 1 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);

    int num = 0;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);
    
    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив длины 2, числа четные.
*/
START_TEST(test_pos_add_num_after_even_arr_size_2_even)
{
    int arr[] = { 2, 4 };

    int new_arr[] = { 0, 0, 0, 0 };

    int exp[] = { 2, -1, 4, -1 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);

    int num = -1;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив длины 2, числа нечетные.
*/
START_TEST(test_pos_add_num_after_even_arr_size_2_odd)
{
    int arr[] = { 1, 3 };

    int new_arr[] = { 0, 0 };

    int exp[] = { 1, 3 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);

    int num = -1;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив длины 2.
*/
START_TEST(test_pos_add_num_after_even_arr_size_2)
{
    int arr[] = { 1, 4 };

    int new_arr[] = { 0, 0, 0 };

    int exp[] = { 1, 4, -1 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);

    int num = -1;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив четной длины.
*/
START_TEST(test_pos_add_num_after_even_arr_size_even)
{
    int arr[] = { 1, 2, 3, 4 };

    int new_arr[] = { 0, 0, 0, 0, 0, 0 };

    int exp[] = { 1, 2, -1, 3, 4, -1 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);

    int num = -1;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

/*  Позитивный тест.
    Массив нечетной длины.
*/
START_TEST(test_pos_add_num_after_even_arr_size_odd)
{
    int arr[] = { 1, 2, 3, 4, 5 };

    int new_arr[] = { 0, 0, 0, 0, 0, 0, 0 };

    int exp[] = { 1, 2, -1, 3, 4, -1, 5};

    size_t n = sizeof(arr) / sizeof(arr[0]);
    size_t ex = sizeof(exp) / sizeof(arr[0]);
    
    int num = -1;

    size_t new_len = 0;

    int rc = add_num_after_even(new_arr, &new_len, arr, n, num);

    ck_assert_int_eq(new_len, ex);

    ck_assert_int_eq(ERR_OK, rc);

    ck_assert_int_eq(ERR_OK, memcmp(new_arr, exp, ex * sizeof(int)));
}
END_TEST

Suite *add_num_after_even_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("add_num_after_even");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_1_even);
    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_1_odd);
    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_2_even);
    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_2_odd);
    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_2);
    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_even);
    tcase_add_test(tc_pos, test_pos_add_num_after_even_arr_size_odd);

    suite_add_tcase(s, tc_pos);

    return s;
}

int add_num_after_even_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = add_num_after_even_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


/// Тесты для calc_even ///

/*  Позитивный тест.
    Массив длиный 1. Число четное.
*/
START_TEST(test_pos_calc_even_arr_size_1_even)
{
    int arr[] = { 2 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    size_t ex = 1;

    size_t len = calc_even(arr, n);

    ck_assert_int_eq(ex, len);
}
END_TEST

/*  Позитивный тест.
    Массив длиный 1. Число нечетное.
*/
START_TEST(test_pos_calc_even_arr_size_1_odd)
{
    int arr[] = { 1 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    size_t ex = 0;

    size_t len = calc_even(arr, n);

    ck_assert_int_eq(ex, len);
}
END_TEST

/*  Позитивный тест.
    Массив длиный 2.
*/
START_TEST(test_pos_calc_even_arr_size_2)
{
    int arr[] = { 1, 2 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    size_t ex = 1;

    size_t len = calc_even(arr, n);

    ck_assert_int_eq(ex, len);
}
END_TEST

/*  Позитивный тест.
    Массив четной длины.
*/
START_TEST(test_pos_calc_even_arr_size_even)
{
    int arr[] = { 1, 2, 3, 4 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    size_t ex = 2;

    size_t len = calc_even(arr, n);

    ck_assert_int_eq(ex, len);
}
END_TEST

/*  Позитивный тест.
    Массив нечетной длины.
*/
START_TEST(test_pos_calc_even_arr_size_odd)
{
    int arr[] = { 1, 2, 3, 4, 5 };

    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    size_t ex = 2;

    size_t len = calc_even(arr, n);

    ck_assert_int_eq(ex, len);
}
END_TEST

Suite *calc_even_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("calc_even");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_pos_calc_even_arr_size_1_even);
    tcase_add_test(tc_pos, test_pos_calc_even_arr_size_1_odd);
    tcase_add_test(tc_pos, test_pos_calc_even_arr_size_2);
    tcase_add_test(tc_pos, test_pos_calc_even_arr_size_even);
    tcase_add_test(tc_pos, test_pos_calc_even_arr_size_odd);

    suite_add_tcase(s, tc_pos);

    return s;
}

int calc_even_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = calc_even_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}