#include "check_read_array.h"
#include "check_comparators.h"

/*  Позитивный тест для read_array
    Неотсортированный список.
*/
START_TEST(test_pos_unsorted_list)
{
    char file[] = "./func_tests/data/pos_01_in.txt";
    
    object_t *list = NULL;

    object_t expect[] = { {"computer", 30, 60 }, {"dog", 14, 10 }, {"fridge", 80, 120 }, {"microwave", 15, 5 }, {"tv", 50, 20 } };

    size_t n = 0;
    size_t n_ex = sizeof(expect) / sizeof(expect[0]);

    int rc = read_array(file, &list, &n);

    rc = compare_arr(list, expect, n, sizeof(object_t), compare_object_t);

    free_array(list, n);

    ck_assert_int_eq(n, n_ex);
    
    ck_assert_int_eq(rc, ERR_OK);
}
END_TEST

/*  Позитивный тест для read_array
    Отсортированный список.
*/
START_TEST(test_pos_sorted_list)
{
    char file[] = "./func_tests/data/pos_02_in.txt";
    
    object_t *list = NULL;

    object_t expect[] = { {"computer", 30, 60 }, {"fridge", 80, 120 }, {"dog", 14, 10 }, {"tv", 50, 20 }, {"microwave", 15, 5 } };

    size_t n = 0;
    size_t n_ex = sizeof(expect) / sizeof(expect[0]);

    int rc = read_array(file, &list, &n);

    rc = compare_arr(list, expect, n, sizeof(object_t), compare_object_t);

    free_array(list, n);

    ck_assert_int_eq(n, n_ex);
    
    ck_assert_int_eq(rc, ERR_OK);
}
END_TEST

/*  Позитивный тест для read_array
    Равные элементы по плотности в списке.
*/
START_TEST(test_pos_sorted_eq_elem_list)
{
    char file[] = "./func_tests/data/pos_03_in.txt";
    
    object_t *list = NULL;

    object_t expect[] = { 
     {"computer", 30, 60 }, {"dog", 14, 10 }, {"fridge", 80, 120 }, {"fridge2", 80, 120 },
     {"microwave", 15, 5 }, {"tv", 50, 20 }, {"cat", 2.5, 5 }, {"playstation", 14, 5.6 }  
    };

    size_t n = 0;
    size_t n_ex = sizeof(expect) / sizeof(expect[0]);

    int rc = read_array(file, &list, &n);

    rc = compare_arr(list, expect, n, sizeof(object_t), compare_object_t);

    free_array(list, n);

    ck_assert_int_eq(n, n_ex);
    
    ck_assert_int_eq(rc, ERR_OK);
}
END_TEST

/*  Позитивный тест для read_array
    Один элемент в списке.
*/
START_TEST(test_pos_one_elem_list)
{
    char file[] = "./func_tests/data/pos_04_in.txt";
    
    object_t *list = NULL;

    object_t expect[] = { {"computer", 30, 60 } };

    size_t n = 0;
    size_t n_ex = sizeof(expect) / sizeof(expect[0]);

    int rc = read_array(file, &list, &n);

    rc = compare_arr(list, expect, n, sizeof(object_t), compare_object_t);

    free_array(list, n);

    ck_assert_int_eq(n, n_ex);
    
    ck_assert_int_eq(rc, ERR_OK);
}
END_TEST

/*  Негативный тест для read_array
    Файл не существует.
*/
START_TEST(test_neg_file_not_exist)
{
    char file[] = "./func_tests/data/neg_1000_in.txt";
    
    object_t *list = NULL;

    size_t n = 0;
   
    int rc = read_array(file, &list, &n);

    free_array(list, n);

    ck_assert_int_eq(rc, ERR_FILE);
}
END_TEST

/*  Негативный тест для read_array
    Пустой файл.
*/
START_TEST(test_neg_file_empty)
{
    char file[] = "./func_tests/data/neg_03_in.txt";
    
    object_t *list = NULL;

    size_t n = 0;
   
    int rc = read_array(file, &list, &n);

    free_array(list, n);

    ck_assert_int_eq(rc, ERR_IO);
}
END_TEST

/*  Негативный тест для read_array
    Неверная запись в файле.
*/
START_TEST(test_neg_incorrect_record)
{
    char file[] = "./func_tests/data/neg_04_in.txt";
    
    object_t *list = NULL;

    size_t n = 0;
   
    int rc = read_array(file, &list, &n);

    free_array(list, n);

    ck_assert_int_eq(rc, ERR_IO);
}
END_TEST

/*  Негативный тест для read_array
    Нулевая масса объекта в файле.
*/
START_TEST(test_neg_zero_mass_record)
{
    char file[] = "./func_tests/data/neg_05_in.txt";
    
    object_t *list = NULL;

    size_t n = 0;
   
    int rc = read_array(file, &list, &n);

    free_array(list, n);

    ck_assert_int_eq(rc, ERR_IO);
}
END_TEST

/*  Негативный тест для read_array
    Нулевой объем объекта в файле.
*/
START_TEST(test_neg_zero_volume_record)
{
    char file[] = "./func_tests/data/neg_06_in.txt";
    
    object_t *list = NULL;

    size_t n = 0;
   
    int rc = read_array(file, &list, &n);

    free_array(list, n);

    ck_assert_int_eq(rc, ERR_IO);
}
END_TEST

/*  Негативный тест для read_array
    Отрицательная характеристика объекта в файле.
*/
START_TEST(test_neg_chactersitcs_record)
{
    char file[] = "./func_tests/data/neg_07_in.txt";
    
    object_t *list = NULL;

    size_t n = 0;
   
    int rc = read_array(file, &list, &n);

    free_array(list, n);

    ck_assert_int_eq(rc, ERR_IO);
}
END_TEST

Suite *read_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    
    s = suite_create("read_array");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_pos, test_pos_unsorted_list);
    tcase_add_test(tc_pos, test_pos_sorted_list);
    tcase_add_test(tc_pos, test_pos_one_elem_list);
    tcase_add_test(tc_pos, test_pos_sorted_eq_elem_list);
    
    tcase_add_test(tc_neg, test_neg_file_not_exist);
    tcase_add_test(tc_neg, test_neg_file_empty);
    tcase_add_test(tc_neg, test_neg_incorrect_record);
    tcase_add_test(tc_neg, test_neg_zero_mass_record);
    tcase_add_test(tc_neg, test_neg_zero_volume_record);
    tcase_add_test(tc_neg, test_neg_chactersitcs_record);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

int read_array_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = read_array_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
