#include "check_compare_density.h"

/*  Позитивный тест.
    Элементы объекты равны.
*/
START_TEST(test_pos_eq_elem_eq_name)
{
    object_t l = { "wood", 500, 200 };
    object_t r = { "wood", 500, 200 };

    ck_assert_uint_eq(EQUAL, compare_density(&l, &r));
}

/*  Позитивный тест.
    Элементы плотности равны.
*/
START_TEST(test_pos_eq_density_not_eq_name)
{
    object_t l = { "wood", 500, 200 };
    object_t r = { "stone", 500, 200 };

    ck_assert_uint_eq(EQUAL, compare_density(&l, &r));
}

/*  Позитивный тест.
    Плотность первого меньше.
*/
START_TEST(test_pos_lt_density)
{
    object_t l = { "wood", 500, 200 };
    object_t r = { "wood1", 600, 200 };

    ck_assert_uint_eq(SMALLER, compare_density(&l, &r));
}

/*  Позитивный тест.
    Плотность второго меньше.
*/
START_TEST(test_pos_gt_density)
{
    object_t l = { "wood", 700, 200 };
    object_t r = { "stone", 600, 200 };

    ck_assert_uint_eq(BIGGER, compare_density(&l, &r));
}

Suite *compare_density_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("compare_density_array");

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_pos_eq_elem_eq_name);
    tcase_add_test(tc_pos, test_pos_eq_density_not_eq_name);
    tcase_add_test(tc_pos, test_pos_lt_density);
    tcase_add_test(tc_pos, test_pos_gt_density);

    suite_add_tcase(s, tc_pos);

    return s;
}

int compare_density_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = compare_density_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
