#include <check.h>
#include <stdlib.h>

#include "matrix_io.h"
#include "check_comparators.h"
#include "matrix_operations.h"

#define N 10

/* Позитивный тест для multy_matrix.
   Матрицы одинаковых размерностей 4x4.
*/
START_TEST(test_pos_multy_matrix_4x4_pos)
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
    double mb4[] = { 1, 2, 3, 4 };

    double *matrix_b[] = { mb1, mb2, mb3, mb4 };

    double **matrix_c = NULL;

    double ex1[] = { 10.000000, 20.000000, 30.000000, 40.000000 };
    double ex2[] = { 10.000000, 20.000000, 30.000000, 40.000000 };
    double ex3[] = { 10.000000, 20.000000, 30.000000, 40.000000 };
    double ex4[] = { 10.000000, 20.000000, 30.000000, 40.000000 };

    double *expect[] = { ex1, ex2, ex3, ex4 };

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_c, m_c, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_c);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для multy_matrix.
   Матрицы одинаковых размерностей 4x4, отрицательные вещественные числа.
*/
START_TEST(test_pos_multy_matrix_4x4_neg)
{   
    int rc;
    double ma1[] = { 1, 2, 3, 4 };
    double ma2[] = { 1, 2, 3, 4 };
    double ma3[] = { -1, -2, -3, -4 };
    double ma4[] = { -1, -2, -3, -4 };

    double *matrix_a[] = { ma1, ma2, ma3, ma4 };

    double mb1[] = { -1, -2, -3, -4 };
    double mb2[] = { -1, -2, -3, -4 };
    double mb3[] = { 1, 2, 3, 4 };
    double mb4[] = { 1, 2, 3, 4 };

    double *matrix_b[] = { mb1, mb2, mb3, mb4 };

    double **matrix_c = NULL;

    double ex1[] = { 4.000000, 8.000000, 12.000000, 16.000000 };
    double ex2[] = { 4.000000, 8.000000, 12.000000, 16.000000 };
    double ex3[] = { -4.000000, -8.000000, -12.000000, -16.000000 };
    double ex4[] = { -4.000000, -8.000000, -12.000000, -16.000000 };

    double *expect[] = { ex1, ex2, ex3, ex4 };

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_c, m_c, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_c);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для multy_matrix.
   Матрицы размерностей 2x3 и 3x2.
*/
START_TEST(test_pos_multy_matrix_2x3_3x2)
{   
    int rc;
    double ma1[] = { 1, 2, 3 };
    double ma2[] = { 1, 2, 3 };

    double *matrix_a[] = { ma1, ma2 };

    double mb1[] = { 1, 2 };
    double mb2[] = { 1, 2 };
    double mb3[] = { 1, 2 };

    double *matrix_b[] = { mb1, mb2, mb3 };

    double **matrix_c = NULL;

    double ex1[] = { 6.000000, 12.000000 };
    double ex2[] = { 6.000000, 12.000000 };
    
    double *expect[] = { ex1, ex2 };

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_c, m_c, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_c);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Позитивный тест для multy_matrix.
    Матрицы размерностей 1x4 и 4x1.
*/
START_TEST(test_pos_multy_matrix_1x4_4x1)
{   
    int rc;
    double ma1[] = { 1, 2, 3, 4 };

    double *matrix_a[] = { ma1 };

    double mb1[] = { 1 };
    double mb2[] = { 1 };
    double mb3[] = { 1 };
    double mb4[] = { 1 };

    double *matrix_b[] = { mb1, mb2, mb3, mb4 };

    double **matrix_c = NULL;

    double ex1[] = { 10 };
    
    double *expect[] = { ex1 };

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_c, m_c, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_c);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/*  Позитивный тест для multy_matrix.
    Матрицы размерностей 4x1 и 1x4.
*/
START_TEST(test_pos_multy_matrix_4x1_1x4)
{   
    int rc;
    double ma1[] = { 1 };
    double ma2[] = { 1 };
    double ma3[] = { 1 };
    double ma4[] = { 1 };

    double *matrix_a[] = { ma1, ma2, ma3, ma4 };

    double mb1[] = { 1, 1, 1, 1 };

    double *matrix_b[] = { mb1 };

    double **matrix_c = NULL;

    double ex1[] = { 1, 1, 1, 1 };
    double ex2[] = { 1, 1, 1, 1 };
    double ex3[] = { 1, 1, 1, 1 };
    double ex4[] = { 1, 1, 1, 1 };

    double *expect[] = { ex1, ex2, ex3, ex4 };

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_ex = sizeof(expect) / sizeof(expect[0]);
    size_t m_ex = sizeof(ex1) /  sizeof(expect[0][0]);

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(matrix_c, n_c, m_c, expect, n_ex, m_ex);

    free_matrix(matrix_c, n_c);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Негативный тест для multy_matrix.
   Матрицы размерностей 2x4 и 3x2.
*/
START_TEST(test_neg_multy_matrix_2x4_3x2)
{   
    int rc;

    double ma1[] = { 1, 2, 3, 4 };
    double ma2[] = { 1, 2, 3, 4 };

    double *matrix_a[] = { ma1, ma2 };

    double mb1[] = { 1, 2 };
    double mb2[] = { 1, 2 };
    double mb3[] = { 1, 2 };

    double *matrix_b[] = { mb1, mb2, mb3 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = sizeof(matrix_b) / sizeof(matrix_b[0]);
    size_t m_b = sizeof(mb1) / sizeof(matrix_b[0][0]);

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

/* Негативный тест для multy_matrix.
   Матрицы размерностей 2x4 и 0x0.
*/
START_TEST(test_neg_multy_matrix_2x4_0x0)
{   
    int rc;
    double ma1[] = { 1, 2, 3, 4 };
    double ma2[] = { 1, 2, 3, 4 };

    double *matrix_a[] = { ma1, ma2 };

    double mb1[] = { 0 };

    double *matrix_b[] = { mb1 };

    double **matrix_c = NULL;

    size_t n_a = sizeof(matrix_a) / sizeof(matrix_a[0]);
    size_t m_a = sizeof(ma1) / sizeof(matrix_a[0][0]);

    size_t n_b = 0;
    size_t m_b = 0;

    size_t n_c, m_c;

    rc = multy_matrix(matrix_a, n_a, m_a, matrix_b, n_b, m_b, &matrix_c, &n_c, &m_c);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

Suite *multy_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    
    s = suite_create("multy_matrix");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_pos, test_pos_multy_matrix_4x4_pos);
    tcase_add_test(tc_pos, test_pos_multy_matrix_4x4_neg);
    tcase_add_test(tc_pos, test_pos_multy_matrix_2x3_3x2);
    tcase_add_test(tc_pos, test_pos_multy_matrix_1x4_4x1);
    tcase_add_test(tc_pos, test_pos_multy_matrix_4x1_1x4);

    tcase_add_test(tc_neg, test_neg_multy_matrix_2x4_3x2);
    tcase_add_test(tc_neg, test_neg_multy_matrix_2x4_0x0);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);

    return s;
}

int multy_matrix_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = multy_matrix_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
