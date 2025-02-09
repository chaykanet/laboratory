#include <check.h>
#include "check_solve_sle.h"
#include "check_comparators.h"

/* Позитивный тест для solve_sle_gauss.
   В матрица 1x2.
*/
START_TEST(test_pos_1x2_mat)
{   
    int rc;
    double m1[] = { 1, 2};
    double *mat[] = { m1 };
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double **vec = create_matrix(m - 1, 1);

    double ex[] = { 2 };
    double *vec_ex[] = { ex };

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(vec, m - 1, 1, vec_ex, m - 1, 1);
    
    free_matrix(vec, m - 1);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для solve_sle_gauss.
   Матрица 2x3.
*/
START_TEST(test_pos_2x3_mat)
{   
    int rc;

    double m1[] = { 1, 2, 3};
    double m2[] = { 2, 1, 3 };
    double *mat[] = { m1, m2 };

    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double **vec = create_matrix(m - 1, 1);
    double ex1[] = { 1 };
    double ex2[] = { 1 };
    double *vec_ex[] = { ex1, ex2 };

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(vec, m - 1, 1, vec_ex, m - 1, 1);
    
    free_matrix(vec, m - 1);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для solve_sle_gauss.
   Матрица 3x4. Числа с 6 нулями после запятой.
*/
START_TEST(test_pos_3x4_mat_6_zero)
{   
    int rc;
    
    double m1[] = { 0.0000001, 0.0000002, 0.0000003, 0.0000006 };
    double m2[] = { 0.0000002, 0.0000002, 0.0000004, 0.0000008 };
    double m3[] = { 0.0000002, 0.0000003, 0.0000004, 0.0000009 };
    double *mat[] = { m1, m2, m3 };
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double **vec = create_matrix(m - 1, 1);
    double ex1[] = { 1 };
    double ex2[] = { 1 };
    double ex3[] = { 1 };
    double *vec_ex[] = { ex1, ex2, ex3 };

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    ck_assert_int_eq(ERR_OK, rc);

    rc = compare_mat(vec, m - 1, 1, vec_ex, m - 1, 1);
    
    free_matrix(vec, m - 1);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Негативный тест для solve_sle_gauss.
   Матрица 3x4. Строки повторяются.
*/
START_TEST(test_neg_3x4_mat_eq_rows)
{   
    int rc;
    double m1[] = { 1, 2, 3, 4 };
    double m2[] = { 1, -2, -5, -8 };
    double m3[] = { 1, 2, 3, 4 };
    double *mat[] = { m1, m2, m3 };
      
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double **vec = create_matrix(m - 1, 1);

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    free_matrix(vec, m - 1);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

/* Негативный тест для solve_sle_gauss.
   Матрица 3x5 все нули.
*/
START_TEST(test_neg_3x5_mat_all_zero)
{   
    int rc;
    double m1[] = { 0, 0, 0, 0, 0 };
    double m2[] = { 0, 0, 0, 0, 0 };
    double m3[] = { 0, 0, 0, 0, 0 };
    double *mat[] = { m1, m2, m3};
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double **vec = create_matrix(m - 1, 1);

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    free_matrix(vec, m - 1);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

/* Негативный тест для solve_sle_gauss.
   Матрица 0x1.
*/
START_TEST(test_neg_0x1_mat)
{   
    int rc;
    double m1[] = { 0 };
    
    double *mat[] = { m1 };
    
    size_t n = 0;

    size_t m = 1;

    double **vec = create_matrix(1, 1);
    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    free_matrix(vec, 1);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

/* Негативный тест для solve_sle_gauss.
   Матрица 1x0.
*/
START_TEST(test_neg_1x0_mat)
{   
    int rc;
    double m1[] = { 0 };

    double *mat[] = { m1 };
    
    size_t n = 1;

    size_t m = 0;

    double **vec = create_matrix(1, 1);

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    free_matrix(vec, 1);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

/* Негативный тест для solve_sle_gauss.
   Матрица 2x2. Не nxn+1.
*/
START_TEST(test_neg_2x2_mat)
{   
    int rc;
    double m1[] = {1, 2 };
    double m2[] = {1, 2 };
    
    double *mat[] = { m1, m2 };
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double **vec = create_matrix(1, 1);

    rc = solve_sle_gauss(vec, m - 1, mat, n, m);

    free_matrix(vec, 1);

    ck_assert_int_eq(ERR_RANGE, rc);
}
END_TEST

Suite *solve_sle_gauss_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    
    s = suite_create("solve_sle_gauss");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_neg_0x1_mat);
    tcase_add_test(tc_neg, test_neg_1x0_mat);
    tcase_add_test(tc_neg, test_neg_2x2_mat);
    tcase_add_test(tc_neg, test_neg_3x5_mat_all_zero);
    tcase_add_test(tc_neg, test_neg_3x4_mat_eq_rows);
    
    suite_add_tcase(s, tc_neg);

    tcase_add_test(tc_pos, test_pos_1x2_mat);
    tcase_add_test(tc_pos, test_pos_2x3_mat);
    tcase_add_test(tc_pos, test_pos_3x4_mat_6_zero);

    suite_add_tcase(s, tc_pos);

    return s;
}

int sle_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = solve_sle_gauss_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

/* Позитивный тест для sub_rows.
   Строки содержат одинаковые элементы.
*/
START_TEST(test_pos_sub_rows_eq_leader)
{   
    int rc;
    double row_from[] = { 5, 5, 5, 5 };
    double row[] = { 5, 5, 5, 5 };

    double expect[] = { 0, 0, 0, 0 };

    size_t n_ex = sizeof(expect) / (sizeof(expect[0]));
    size_t n = sizeof(row_from) / (sizeof(row_from[0]));

    sub_rows(row_from, row, n, 0);

    rc = compare_arr(row_from, expect, n_ex);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sub_rows.
   Ведущий элемент с индексом 1.
*/
START_TEST(test_pos_sub_rows_from_second)
{   
    int rc;
    double row_from[] = { 0, 5, 5, 5 };
    double row[] = { 0, 5, 5, 5 };

    double expect[] = { 0, 0, 0, 0 };

    size_t n_ex = sizeof(expect) / (sizeof(expect[0]));
    size_t n = sizeof(row_from) / (sizeof(row_from[0]));

    sub_rows(row_from, row, n, 1);

    rc = compare_arr(row_from, expect, n_ex);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sub_rows.
   Ведущий элемент меньше первого элемента строки.
*/
START_TEST(test_pos_sub_rows_gt_leader)
{   
    int rc;
    double row_from[] = { 5, 5, 5, 5 };
    double row[] = { 4, 4, 4, 4 };

    double expect[] = { 0, 0, 0, 0 };

    size_t n_ex = sizeof(expect) / (sizeof(expect[0]));
    size_t n = sizeof(row_from) / (sizeof(row_from[0]));

    sub_rows(row_from, row, n, 0);

    rc = compare_arr(row_from, expect, n_ex);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sub_rows.
   Ведущий элемент больше первого элемента строки.
*/
START_TEST(test_pos_sub_rows_lt_leader)
{   
    int rc;
    double row_from[] = { 5, 5, 5, 5 };
    double row[] = { 8, 8, 8, 8 };

    double expect[] = { 0, 0, 0, 0 };

    size_t n_ex = sizeof(expect) / (sizeof(expect[0]));
    size_t n = sizeof(row_from) / (sizeof(row_from[0]));

    sub_rows(row_from, row, n, 0);
    
    rc = compare_arr(row_from, expect, n_ex);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для sub_rows.
   Ведущий элемент на последней позиции.
*/
START_TEST(test_pos_sub_rows_last_leader)
{   
    int rc;
    double row_from[] = { 0, 0, 0, 5 };
    double row[] = { 0, 0, 0, 8 };

    double expect[] = { 0, 0, 0, 0 };

    size_t n_ex = sizeof(expect) / (sizeof(expect[0]));
    size_t n = sizeof(row_from) / (sizeof(row_from[0]));

    sub_rows(row_from, row, n, 3);
    
    rc = compare_arr(row_from, expect, n_ex);
    
    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для find_vector.
   Ступенчатая матрица 2x3.
*/
START_TEST(test_pos_2x3_mat_vector)
{   
    int rc;
    double m1[] = { 1, 2, 3 };
    double m2[] = { 0, 2, 2 };
    double *mat[] = { m1, m2 };
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double v1[] = { 0 };
    double v2[] = { 0 }; 
    double *vec[] = { v1, v2 };

    size_t vec_n = sizeof(vec) / sizeof(vec[0]);

    double ex1[] = { 1 };
    double ex2[] = { 1 };
    double *vec_ex[] = { ex1, ex2 };

    size_t ex_n = sizeof(vec_ex) / sizeof(vec_ex[0]);

    find_vector(vec, vec_n, mat, n, m);

    rc = compare_mat(vec, vec_n, 1, vec_ex, ex_n, 1);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для find_vector.
   Ступенчатая матрица 3x4.
*/
START_TEST(test_pos_3x4_mat_vector)
{   
    int rc;
    double m1[] = { 1, 2, 3, 6 };
    double m2[] = { 0, 2, 2, 4 };
    double m3[] = { 0, 0, 2, 2 };

    double *mat[] = { m1, m2, m3 };
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double v1[] = { 0 };
    double v2[] = { 0 }; 
    double v3[] = { 0 };
    double *vec[] = { v1, v2, v3 };

    size_t vec_n = sizeof(vec) / sizeof(vec[0]);

    double ex1[] = { 1 };
    double ex2[] = { 1 };
    double ex3[] = { 1 };
    double *vec_ex[] = { ex1, ex2, ex3 };

    size_t ex_n = sizeof(vec_ex) / sizeof(vec_ex[0]);

    find_vector(vec, vec_n, mat, n, m);

    rc = compare_mat(vec, vec_n, 1, vec_ex, ex_n, 1);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

/* Позитивный тест для find_vector.
   Матрица нулей 4x5. 
*/
START_TEST(test_pos_4x5_mat_zeros_vector)
{   
    int rc;
    double m1[] = { 0, 0, 0, 0, 0 };
    double m2[] = { 0, 0, 0, 0, 0 };
    double m3[] = { 0, 0, 0, 0, 0 };
    double m4[] = { 0, 0, 0, 0, 0 };

    double *mat[] = { m1, m2, m3, m4 };
    
    size_t n = sizeof(mat) / sizeof(mat[0]);

    size_t m = sizeof(m1) / sizeof(double);

    double v1[] = { 0 };
    double v2[] = { 0 }; 
    double v3[] = { 0 };
    double v4[] = { 0 };
    double *vec[] = { v1, v2, v3, v4 };

    size_t vec_n = sizeof(vec) / sizeof(vec[0]);

    double ex1[] = { 0 };
    double ex2[] = { 0 };
    double ex3[] = { 0 };
    double ex4[] = { 0 };
    double *vec_ex[] = { ex1, ex2, ex3, ex4 };

    size_t ex_n = sizeof(vec_ex) / sizeof(vec_ex[0]);

    find_vector(vec, vec_n, mat, n, m);

    rc = compare_mat(vec, vec_n, 1, vec_ex, ex_n, 1);

    ck_assert_int_eq(ERR_OK, rc);
}
END_TEST

Suite *sub_rows_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    s = suite_create("sub_rows");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_pos_sub_rows_eq_leader);
    tcase_add_test(tc_pos, test_pos_sub_rows_from_second);
    tcase_add_test(tc_pos, test_pos_sub_rows_last_leader);
    tcase_add_test(tc_pos, test_pos_sub_rows_gt_leader);
    tcase_add_test(tc_pos, test_pos_sub_rows_lt_leader);

    suite_add_tcase(s, tc_pos);

    return s;
}

int sub_rows_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = sub_rows_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

Suite *find_vector_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("find_vector");

    tc_pos = tcase_create("positives");
  
    tcase_add_test(tc_pos, test_pos_2x3_mat_vector);
    tcase_add_test(tc_pos, test_pos_3x4_mat_vector);
    tcase_add_test(tc_pos, test_pos_4x5_mat_zeros_vector);

    suite_add_tcase(s, tc_pos);

    return s;
}

int find_vector_result(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = find_vector_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
