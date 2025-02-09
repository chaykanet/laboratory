#include "matrix_operations.h"
#include "matrix_io.h"

void sub_rows(double *from_row, double *row, const size_t len, const size_t index)
{      
    double multy = from_row[index] / row[index];

    for (size_t i = index; i < len; i++)
        from_row[i] -= row[i] * multy;
}

/*  Функция проверят на наличие нулевых столбцов.
    Функция принимает матрицу matrix и ее размеры n, m.
    Возвращает код ошибки.
*/
static bool check_clmn_zero(double **matrix, const size_t n, const size_t m)
{   
    for (size_t j = 0; j < m; j++)
    {   
        bool is_zero = true;
        
        for (size_t i = 0; i < n; i++)
            if (fabs(matrix[i][j]) >= EPS)
                is_zero = false;

        if (is_zero)
            return true;
    }

    return false;
}

/*  Функция проверят на наличие нулевых строк.
    Функция принимает матрицу matrix и ее размеры n, m.
    Возвращает код ошибки.
*/
static bool check_row_zero(double **matrix, const size_t n, const size_t m)
{   
    for (size_t i = 0; i < n; i++)
    {   
        bool is_zero = true;
        
        for (size_t j = 0; j < m; j++)
            if (fabs(matrix[i][j]) >= EPS)
                is_zero = false;

        if (is_zero)
            return true;
    }

    return false;
}

void bring_mat_to_step(double **matrix, const size_t n, const size_t m)
{  
    size_t index_lead;

    //  Итерации по столбцам. (по m - 1 так как m столбец свободных членов)
    for (size_t i = 0; i < m - 1; i++)
    {      
        index_lead = i; //  Индекс ведущего элемента.

        double leader = matrix[i][i], prevleader = leader;

        // Итерации по строкам.
        for (size_t j = i; j < n; j++) 
        {   
            // Нахождение ведущего элемента (по модулю)
            leader = fabs(leader) - fabs(matrix[j][i]) > 0 ? leader : matrix[j][i];

            if (leader - prevleader > EPS)
            {
                prevleader = leader;
                index_lead = j;
            }
        }

        // Если найден ведущий элемент не равный начальному, то меняем местами строки, содержащие их.
        if (index_lead != i)
        {   
            double *tmp = matrix[index_lead];
            matrix[index_lead] = matrix[i];
            matrix[i] = tmp;
        }

        if (fabs(leader) >= EPS)
        {
            // Наичная с i + 1 индекса строки по n - 1 складываем со строкой i, умножая на коэффициент.
            for (size_t j = i + 1; j <= n - 1; j++)
                sub_rows(matrix[j], matrix[i], m, i);
        }
    }
}

void find_vector(double **vector, const size_t vec_n, double **step_matrix, const size_t n, const size_t m)
{  
    //  Начиная с последней строки по 0-вую.
    for (size_t i = vec_n; i > 0; i--)
    {    
        double sum = 0;
        
        //  Подсчитываем все известные переменные в i уравнении (строке).
        for (size_t j = n; j > i; j--)
            sum += step_matrix[i - 1][j - 1] * vector[j - 1][0];

        // Находим i-ю координату вектора.
        vector[i - 1][0] = (step_matrix[i - 1][m - 1] - sum) / step_matrix[i - 1][i - 1];
    }
}

int solve_sle_gauss(double **vector, size_t const vec_n, double **matrix, size_t const n, size_t const m)
{
    int rc = ERR_OK;
    bool is_zero = false;
    
    if (n == 0 || n + 1 != m)
        return ERR_RANGE;

    if (vec_n != m - 1)
        return ERR_RANGE;

    is_zero = check_clmn_zero(matrix, n, m - 1);
    
    if (!is_zero)
        is_zero = check_row_zero(matrix, n, m - 1);
        
    if (!is_zero)
        bring_mat_to_step(matrix, n, m);
    
    if (!is_zero)
        is_zero = check_row_zero(matrix, n, m - 1);
    
    if (!is_zero)
        find_vector(vector, vec_n, matrix, n, m);
    
    if (is_zero)
        rc = ERR_RANGE;

    return rc;
}

int sum_matrix(double **matrix_a, size_t const n_a, size_t const m_a, double **matrix_b, size_t const n_b, size_t const m_b, double ***matrix_dst, size_t *n_dst, size_t *m_dst)
{   
    if (n_a != n_b || m_a != m_b)
        return ERR_RANGE;

    double **ptrs = create_matrix(n_a, m_a);

    if (!ptrs)
        return ERR_ALLOC;

    for (size_t i = 0; i < n_a; i++)
        for (size_t j = 0; j < m_a; j++)
            ptrs[i][j] = matrix_a[i][j] + matrix_b[i][j];
    
    *matrix_dst = ptrs;
    *n_dst = n_a;
    *m_dst = m_a;

    return ERR_OK;
}

int multy_matrix(double **matrix_f, size_t const n_f, size_t const m_f, double **matrix_s, size_t const n_s, size_t const m_s, double ***matrix, size_t *n, size_t *m)
{   
    if (m_f != n_s)
        return ERR_RANGE;

    double **ptrs = create_matrix(n_f, m_s);

    if (!ptrs)
        return ERR_ALLOC;

    for (size_t g = 0; g < n_f; g++)
    {
        for (size_t i = 0; i < m_s; i++)
        {
            double sum = 0;

            for (size_t k = 0; k < m_f; k++)
                sum += matrix_f[g][k] * matrix_s[k][i];

            ptrs[g][i] = sum;
        }
    }

    *n = n_f;
    *m = m_s;

    *matrix = ptrs;

    return ERR_OK;
}

