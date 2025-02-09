#include "check_sum_matrix.h"
#include "check_comparators.h"

/* Позитивный тест для sum_matrix.
   Матрицы размерностей 1x1 и 1x1.
*/
START_TEST(test_pos_sum_matrix_1x1_1x1)
{   
    int rc;
    double ma1[] = { 1 };

    double *matrix_a[] = { ma1 };

    double mb1[] = { 1 };
       
    double *matrix_b[] = { mb1 };

    double ex1[] = { 2.000000 };
    
    double *expect[] = { ex1 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n, m;

    rc = sum_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n, &m);
    
    ck_assert_int_eq(ERR_OK, rc);
   
    rc = compare_mat(matrix_c, n_a, m_a, expect, n_ex, m_ex);
    
    free_matrix(matrix_c, n_a);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sum_matrix.
   Матрицы размерностей 2x3 и 2x3.
*/
START_TEST(test_pos_sum_matrix_2x3_2x3)
{   
    int rc;
    double ma1[] = { 1, 2, 3 };
    double ma2[] = { 1, 2, 3 };

    double *matrix_a[] = { ma1, ma2 };

    double mb1[] = { 1, 2, 3 };
    double mb2[] = { 1, 2, 3 };
    
    double *matrix_b[] = { mb1, mb2 };

    double ex1[] = { 2.000000, 4.000000, 6.000000 };
    double ex2[] = { 2.000000, 4.000000, 6.000000 };
    
    double *expect[] = { ex1, ex2 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n, m;

    rc = sum_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n, &m);
    
    ck_assert_int_eq(ERR_OK, rc);
   
    rc = compare_mat(matrix_c, n_a, m_a, expect, n_ex, m_ex);
    
    free_matrix(matrix_c, n_a);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sum_matrix.
   Матрицы размерностей 3x3 и 3x3.
*/
START_TEST(test_pos_sum_matrix_3x3_3x3)
{   
    int rc;
    double ma1[] = { 1, 2, 3 };
    double ma2[] = { 1, 2, 3 };
    double ma3[] = { 1, 2, 3 };

    double *matrix_a[] = { ma1, ma2, ma3 };

    double mb1[] = { 1, 2, 3 };
    double mb2[] = { 1, 2, 3 };
    double mb3[] = { 1, 2, 3 };

    double *matrix_b[] = { mb1, mb2, mb3 };

    double ex1[] = { 2.000000, 4.000000, 6.000000 };
    double ex2[] = { 2.000000, 4.000000, 6.000000 };
    double ex3[] = { 2.000000, 4.000000, 6.000000 };
    
    double *expect[] = { ex1, ex2, ex3 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n, m;

    rc = sum_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n, &m);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_a, m_a, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_a);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sum_matrix.
   Матрицы размерностей 4x4 и 4x4, в матрице отрицательные вещественные числа.
*/
START_TEST(test_pos_sum_matrix_4x4_4x4_neg_elems)
{   
    int rc;
    double ma1[] = { 1, 2, 3, 4 };
    double ma2[] = { 1, 2, 3, 4 };
    double ma3[] = { 1, 2, 3, 4 };
    double ma4[] = { 1, 2, 3, 4 };

    double *matrix_a[] = { ma1, ma2, ma3, ma4 };

    double mb1[] = { 1, 2, 3, 4 };
    double mb2[] = { 1, 2, 3, 4 };
    double mb3[] = { 1, 2, 3, 4 };
    double mb4[] = { -1, -2, -3, -4 };

    double *matrix_b[] = { mb1, mb2, mb3, mb4 };

    double ex1[] = { 2.000000, 4.000000, 6.000000, 8.000000 };
    double ex2[] = { 2.000000, 4.000000, 6.000000, 8.000000 };
    double ex3[] = { 2.000000, 4.000000, 6.000000, 8.000000 };
    double ex4[] = { 0.000000, 0.000000, 0.000000, 0.000000 };
    
    double *expect[] = { ex1, ex2, ex3, ex4 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n, m;

    rc = sum_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n, &m);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_a, m_a, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_a);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Негативный тест для sum_matrix.
    Матрицы размеров 4x4 и 3x4.
*/  
START_TEST(test_neg_matrix_4x4_3x4)
{
    int rc;
    double ma1[] = { 1, 2, 3, 4 };
    double ma2[] = { 1, 2, 3, 4 };
    double ma3[] = { 1, 2, 3, 4 };
    double ma4[] = { 1, 2, 3, 4 };

    double *matrix_a[] = { ma1, ma2, ma3, ma4 };

    double mb1[] = { 1, 2, 3, 4 };
    double mb2[] = { 1, 2, 3, 4 };
    double mb3[] = { 1, 2, 3, 4 };

    double *matrix_b[] = { mb1, mb2, mb3 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n, m;

    rc = sum_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n, &m);

    ck_assert_int_eq(ERR_RANGE, rc);
}

/*  Негативный тест для sum_matrix.
    Матрицы размеров 3x3 и 3x4.
*/  
START_TEST(test_neg_matrix_3x3_3x4)
{
    int rc;
    double ma1[] = { 1, 2, 3 };
    double ma2[] = { 1, 2, 3 };
    double ma3[] = { 1, 2, 3 };

    double *matrix_a[] = { ma1, ma2, ma3 };

    double mb1[] = { 1, 2, 3, 4 };
    double mb2[] = { 1, 2, 3, 4 };
    double mb3[] = { 1, 2, 3, 4 };

    double *matrix_b[] = { mb1, mb2, mb3 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n, m;

    rc = sum_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n, &m);

    ck_assert_int_eq(ERR_RANGE, rc);
}

Suite *sum_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    
    s = suite_create("sum_matrix");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_neg_matrix_4x4_3x4);
    tcase_add_test(tc_neg, test_neg_matrix_3x3_3x4);
    
    tcase_add_test(tc_pos, test_pos_sum_matrix_1x1_1x1);
    tcase_add_test(tc_pos, test_pos_sum_matrix_2x3_2x3);
    tcase_add_test(tc_pos, test_pos_sum_matrix_3x3_3x3);
    tcase_add_test(tc_pos, test_pos_sum_matrix_4x4_4x4_neg_elems);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

int sum_matrix_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = sum_matrix_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
