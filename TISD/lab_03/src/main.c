#include <time.h>
#include "errcodes.h"
#include "matrix_io.h"
#include "csc_matrix.h"
#include "csc_operations.h"

#define MAX_LEN_STR 256

int main(void)
{
    int rc = ERR_OK;
    char filename[MAX_LEN_STR];

    printf("Введите имя файла: \n");
    scanf("%s", filename);

    FILE *file_matrix;
    while (!(file_matrix = fopen(filename, "r")))
    {
        printf("Файл не наден, повторите ввод:\n");
        scanf("%s", filename);
    }

    int move = 100;
    
    int **new_matrix = NULL;
    int **matrix = NULL;
    int n_t, m_t;
    size_t n, m;

    int **matrix_csc = NULL;
    size_t n_csc, m_csc;

    sparseMatrix_t *csc = NULL;

    vec_t *vector = NULL;
    vec_t *vector_res = NULL;

    int *result = NULL;
    size_t res_len;

    double start, end;
    double time_mat = 0, time_csc = 0;
    size_t valume_mat = 0, valume_csc = 0;

    if (fscanf(file_matrix, "%d %d", &n_t, &m_t) != 2 || n_t < 0 || m_t < 0)
        rc = ERR_IO;

    if (rc == ERR_OK)
    {   
        n = n_t;
        m = m_t;
        matrix = create_matrix(n, m);

        if (matrix)
            rc = read_matrix(file_matrix, matrix, n, m);
        else
            rc = ERR_ALLOC;
    }

    fclose(file_matrix);

    if (rc == ERR_OK)
    {
        do 
        {   
            printf("Меню\n");
            printf("Введите номер действия :\n1.Вывести матрицу на экран.\n2.Вывести матрицу csc на экран.\n3.Ввести матрицу.\n");
            printf("4.Ввести вектор-строку.\n");
            printf("5.Вывести вектор-строку.\n");
            printf("6.Умножить csc матрицу на вектор-строку.\n");
            printf("7.Умножить матрицу на вектор-строку (Стандартный алгоритм).\n");
            printf("8.Считать матрицу из файла.\n");
            printf("9.Считать вектор строку из файла.\n");
            printf("10.Перевести матрицу в csc формат.\n");
            printf("11.Перевести csc матрицу в стандартную\n");
            printf("12.Сравнить методы умножения матриц на вектор-строку\n");
            printf("13.Ввод матрицы по координатам\n");
            printf("0.Выход\n");
            rc = scanf("%d", &move);

            if (rc != 1) 
            {
                printf("Неверный номер действия.\n");
                
                while (getchar() != '\n');

                continue;
            }

            switch (move)
            {
            case 1:
                printf("--------------------------------------\n");
                if (new_matrix)
                    matrix = new_matrix;
                if (matrix)
                    print_matrix(matrix, n, m);
                else
                    printf("Матрица пустая.\n");
                break;
            case 2:
                printf("--------------------------------------\n");
                if (!csc)
                {
                    printf("Матрица csc пустая.\n");
                    break;
                }
                print_csc(csc);
                break;
            case 3:
                printf("--------------------------------------\n");
                free_matrix(matrix);
                printf("Введите размеры матрицы n, m: \n");
                if (scanf("%d %d", &n_t, &m_t) != 2 || n_t < 0 || m_t < 0)
                {
                    printf("Ошибка ввода.\n");
                    break;
                }
                n = n_t;
                m = m_t;
                matrix = create_matrix(n, m);
                rc = input_matrix(matrix, n , m);

                if (rc != ERR_OK)
                {
                    printf("Ошибка ввода.\n");
                    break;
                }
                printf("Успешный ввод.\n");
                break;
            case 4:
                printf("--------------------------------------\n");
                free_vector(vector);
                rc = input_vector(&vector);
               
                if (rc != ERR_OK || !vector)
                {
                    printf("Ошибка ввода вектора строки\n");
                    break;
                }
                break;
            case 5:
                printf("--------------------------------------\n");
                if (!vector)
                {
                    printf("Ошибка ввода вектора строки\n");
                    break;
                }

                print_vector(vector);
                break;
            case 6:
                printf("--------------------------------------\n");
                if (!vector)
                {
                    printf("Вектор строка - пуст");
                    break;
                }
                if (!csc)
                {
                    printf("Csc матрица пуста.");
                    break;
                }

                start = clock();
                result = multvec_csc(&res_len, csc, vector);
                end = clock();

                time_csc = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                valume_csc = sizeof(sparseMatrix_t*) + sizeof(int) * csc-> numNonZero * 2 + sizeof(int) * (csc->row_len + 1);

                if (!result)
                {
                    printf("Ошибка умножения.\n");
                    break;
                }

                if (vector_res)
                    free_vector(vector_res);
                
                vector_res = convert_from_arr(result, res_len);
                
                print_result(vector_res);
                
                free(result);
                break;
            case 7:
                printf("--------------------------------------\n");
                if (!vector)
                {
                    printf("Вектор строка - пуст");
                    break;
                }
                if (!matrix)
                {
                    printf("Стнд. матрица пуста.");
                    break;
                }

                size_t vec_n;
                int *vec = vecconvert_toarr(&vec_n, vector); 
                
                if (!vec)
                {
                    printf("Ошибка в форматировании вектора строки\n");
                    break;
                }

                start = clock();
                result = multvec_mat(&res_len, matrix, n, m, vec, vec_n);
                end = clock();

                time_mat = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                valume_mat = sizeof(int) * n * m + sizeof(int *) * n;

                if (!result)
                {   
                    free(vec);
                    printf("Ошибка умножения.\n");
                    break;
                }

                if (vector_res)
                    free_vector(vector_res);

                vector_res = convert_from_arr(result, res_len);
                print_result(vector_res);
                
                free(vec);
                free(result);
                break;
            case 8:
                printf("--------------------------------------\n");
                printf("Введите имя файла: \n");
                scanf("%s", filename);
                while (!(file_matrix = fopen(filename, "r")))
                {
                    printf("Файл не наден, повторите ввод:\n");
                    scanf("%s", filename);
                }
                
                rc = ERR_OK;

                rewind(file_matrix);

                if (fscanf(file_matrix, "%d %d", &n_t, &m_t) != 2 || n_t < 0 || m_t < 0)
                    rc = ERR_IO;

                if (rc == ERR_OK)
                {   
                    n = n_t;
                    m = m_t;
                    matrix = create_matrix(n, m);

                    if (matrix)
                        rc = read_matrix(file_matrix, matrix, n, m);
                    else
                        rc = ERR_ALLOC;
                }
            
                fclose(file_matrix);
                if (rc == EOF)
                    rc = ERR_OK;

                if (rc != ERR_OK)
                {
                    printf("Ошибка чтения матрицы из файла.\n");
                }
                break;
            case 9:
                printf("--------------------------------------\n");
                printf("Введите имя файла: \n");
                scanf("%s", filename);
                
                if (!vector)
                    free_vector(vector);
                rc = fget_vector(filename, &vector);

                if (rc != ERR_OK)
                {
                    printf("Ошибка  считывания вектора строк\n");
                    break;
                }
                break;
            case 10:
                printf("--------------------------------------\n");
                freeSparseMatrix(csc);
                csc = matconvert_tocsc(matrix, n, m);
                if (!csc)
                {
                    printf("Ошибка перевода в csc формат.\n");
                    break;
                }
                printf("Матрица переведена в формат csc\n");
                break;
            case 11:
                printf("--------------------------------------\n");
                matrix_csc = csc_convert_tomat(&n_csc, &m_csc, csc);

                if (!matrix_csc)
                {
                    printf("Ошибка перевода в стандартный формат.\n");
                    break;
                }
                print_matrix(matrix_csc, n_csc, m_csc);
                break;
            case 12:
                printf("--------------------------------------\n\n");
                if (!time_csc || !time_mat)
                {
                    printf("Недостаточно данных. Проведите операции умножения.\n");
                    printf("--------------------------------------\n\n");
                    break;
                }

                printf("Время выполнения умножения матрицы на вектор строку (стандарт.) в мс.: %lf\n", time_mat);
                printf("Память матрицы в байтах: %lu\n", valume_mat);
                printf("Время выполнения умножения матрицы csc на вектор строку в мс.: %lf\n", time_csc);
                printf("Память матрицы в байтах: %lu\n\n", valume_csc);
                printf("--------------------------------------\n\n");
                break;
            case 13:
                printf("--------------------------------------\n");
                free_matrix(matrix);
                printf("Введите размеры матрицы n, m: \n");
                if (scanf("%d %d", &n_t, &m_t) != 2 || n_t < 0 || m_t < 0)
                {
                    printf("Ошибка ввода.\n");
                    break;
                }
                n = n_t;
                m = m_t;
                matrix = create_matrix(n, m);

                rc = input_matrix_xy(matrix, n , m);

                if (rc != ERR_OK)
                {
                    printf("Ошибка ввода.\n");
                    break;
                }
                printf("Успешный ввод.\n");
                break;
            default:
                break;
            }
        }
        while (move != 0);
    }

    if (matrix)
        free_matrix(matrix);

    if (matrix_csc)
    
        free_matrix(matrix_csc);

    if (csc)
        freeSparseMatrix(csc);

    if (vector)
        free_vector(vector);

    return rc;
}