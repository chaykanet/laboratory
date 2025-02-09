#include "check_sort.h"
#include "check_comparators.h"

/*  Позитивный тест для sort_array.
    Отсортированный массив.
*/
START_TEST(test_pos_sorted_5_elem)
{
    object_t arr[] = { { "wood", 200, 250 }, { "stone", 500, 250 }, { "stone2", 600, 250 }, { "wood2", 700, 250 }, { "wood3", 800, 250 } };

    object_t expect[] = { { "wood", 200, 250 }, { "stone", 500, 250 }, { "stone2", 600, 250 }, { "wood2", 700, 250 }, { "wood3", 800, 250 } };

    size_t n = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, n);

    int rc = compare_arr(arr, expect, n, sizeof(object_t), compare_object_t);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Позитивный тест для sort_array.
    Неотсортированный массив.
*/
START_TEST(test_pos_unsorted_4_elem)
{
    object_t arr[] = { { "stone2", 600, 250 }, { "wood", 200, 250 }, { "stone", 500, 250 }, { "wood2", 700, 250 } };

    object_t expect[] = { { "wood", 200, 250 }, { "stone", 500, 250 }, { "stone2", 600, 250 }, { "wood2", 700, 250 } };

    size_t n = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, n);

    int rc = compare_arr(arr, expect, n, sizeof(object_t), compare_object_t);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Позитивный тест для sort_array.
    Отсортированный массив из 2 элементов.
*/
START_TEST(test_pos_sorted_2_elem)
{
    object_t arr[] = { { "wood", 200, 250 }, { "stone", 500, 250 } };

    object_t expect[] = { { "wood", 200, 250 }, { "stone", 500, 250 } };

    size_t n = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, n);

    int rc = compare_arr(arr, expect, n, sizeof(object_t), compare_object_t);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Позитивный тест для sort_array.
    Неотсортированный массив из 2 элементов.
*/
START_TEST(test_pos_unsorted_2_elem)
{
    object_t arr[] = { { "stone", 500, 250 }, {"wood", 200, 250 }, };

    object_t expect[] = { { "wood", 200, 250 }, { "stone", 500, 250 } };

    size_t n = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, n);

    int rc = compare_arr(arr, expect, n, sizeof(object_t), compare_object_t);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Позитивный тест для sort_array.
    В массиве 1 элемент.
*/
START_TEST(test_pos_1_elem)
{
    object_t arr[] = { { "stone", 500, 250 } };

    object_t expect[] = { { "stone", 500, 250 } };

    size_t n = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, n);

    int rc = compare_arr(arr, expect, n, sizeof(object_t), compare_object_t);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

Suite *sort_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("sort_array");

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_pos_sorted_5_elem);
    tcase_add_test(tc_pos, test_pos_unsorted_4_elem);
    tcase_add_test(tc_pos, test_pos_sorted_2_elem);
    tcase_add_test(tc_pos, test_pos_1_elem);
    tcase_add_test(tc_pos, test_pos_unsorted_2_elem);

    suite_add_tcase(s, tc_pos);

    return s;
}

int sort_array_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = sort_array_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
