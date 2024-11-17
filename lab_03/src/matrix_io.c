#include "matrix_io.h"

int input_vector(vec_t **vector)
{   
    int rc = ERR_OK;
    int none_zero_count, vec_len;

    printf("Введите длину вектора: \n");

    if (scanf("%d", &vec_len) != 1 || vec_len < 0)
        return ERR_IO;

    printf("Введите кол-во не нулевых элементов: \n");

    if (scanf("%d", &none_zero_count) != 1 || none_zero_count <= 0)
        return ERR_IO;

    if (vec_len < none_zero_count)
        return ERR_IO;

    int *pB = malloc(sizeof(int) * none_zero_count);
    int *pJB = malloc(sizeof(int) * none_zero_count);

    int prev = -1;
    
    for (int i = 0; rc == ERR_OK && i < none_zero_count; i++)
    {
        printf("Введите %d-го значение, индекс: \n", i);

        if (scanf("%d %d", &pB[i], &pJB[i]) != 2 || pJB[i] < 0 || prev >= pJB[i] || pJB[i] >= vec_len)
            rc = ERR_IO;
        
        prev = pJB[i];

        if (pB[i] == 0)
        {
            i--;
            prev--;
        }
    }

    if (rc == ERR_OK && pB && pJB)
        *vector = create_vector(pB, pJB, none_zero_count, vec_len);

    if (!vector)
        rc = ERR_IO;

    free(pB);
    free(pJB);

    return rc;
}

int input_matrix_xy(int **matrix, size_t const n, size_t const m)
{   
    int rc = ERR_OK;
    int none_zero_count = 0;

    printf("Введите кол-во не нулевых элементов: \n");

    if (scanf("%d", &none_zero_count) != 1 || none_zero_count <= 0)
        return ERR_IO;

    if (n * m < (size_t) none_zero_count)
        return ERR_IO;
    
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            matrix[i][j] = 0;

    for (int i = 0; rc == ERR_OK && i < none_zero_count; i++)
    {
        printf("Введите %d-го значение, индекс x, индекс y: \n", i);
        int tmp, x, y;
        if (scanf("%d %d %d", &tmp, &x, &y) != 3 || x < 0 || y < 0 || tmp == 0 || (int) n <= x || (int) m <= y)
            rc = ERR_IO;

        if (rc == ERR_OK)
            matrix[x][y] = tmp;
    }

    return rc;
}

int fget_vector(char *filename, vec_t **vector)
{
    FILE *f = fopen(filename, "r");

    int *pB = NULL, *pJB = NULL;

    if (!f)
        return ERR_FILE;
    
    int vec_len = 0;
    int none_zero_count = 0;
    int tmp, rc;

    while ((rc = fscanf(f, "%d", &tmp)) == 1)
    {    
        if (tmp != 0)
            none_zero_count++;
        vec_len++;
    }
    
    if (none_zero_count > vec_len)
        rc = ERR_IO;

    if (rc == EOF)
        rc = ERR_OK;

    if (rc == ERR_OK)
    {
        pB = malloc(sizeof(int) * none_zero_count);
        pJB = malloc(sizeof(int) * none_zero_count);

        fseek(f, 0, SEEK_SET);

        int index = 0;
        for (int i = 0; i < vec_len && index < none_zero_count; i++)
        {
            if (fscanf(f, "%d", &tmp) != 1)
            {
                rc = ERR_IO;
                break;
            }
            
            if (rc == ERR_OK && tmp != 0)
            {
                pB[index] = tmp;
                pJB[index] = i;
                index++;
            }
        }
        
        if (rc == ERR_OK)
            *vector = create_vector(pB, pJB, none_zero_count, vec_len);

        free(pB);
        free(pJB);
    }

    fclose(f);

    return rc;
}

int input_matrix(int **matrix, size_t const n, size_t const m)
{   
    printf ("Вводите элементы:\n");

    for (size_t i = 0 ; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return ERR_IO;
    
    printf("Ввод окончен.\n");

    return ERR_OK;
}

int read_matrix(FILE *file, int **matrix, size_t const n, size_t const m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {   
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
                return ERR_IO;
        }
    return ERR_OK;
}

void print_matrix(int **matrix, size_t const n, size_t const m)
{
    printf("Вывод матрицы: \n");

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

void print_vector(vec_t *vector)
{   
    if (!vector)
        return;

    int index = 0;

    for (int i = 0; i < vector->vec_len; i++)
    {
        if (index < vector->numNonZero && i == vector->JB[index])
        {
            printf("%d ", vector->B[index]);
            index++;
        }
        else
            printf("0 ");
    }
    printf("\n");
}

void print_csc(sparseMatrix_t *csc)
{   
    printf("Вектор значений A: { ");
    for (int i = 0; i < csc->numNonZero; i++)
        printf("%d ", csc->A[i]);
    printf ("}\n");

    printf("Вектор индексов строк IA: { ");
    for (int i = 0; i < csc->numNonZero; i++)
        printf("%d ", csc->IA[i]);
    printf ("}\n");

    printf("Вектор столбцов JA: { ");
    for (int i = 0; i <= csc->row_len; i++)
        printf("%d ", csc->JA[i]);
    printf ("}\n");
}

void print_result(vec_t *vec)
{   
    if (!vec)
        return;

    printf("Результат: ");
    printf("B: { ");
    for (size_t i = 0; (int) i < vec->numNonZero; i++)
        printf("%d ", vec->B[i]);
    printf("}\n");

    printf("JB: { ");
    for (size_t i = 0; (int) i < vec->numNonZero; i++)
        printf("%d ", vec->JB[i]);
    printf("}");

    printf("\n");
}