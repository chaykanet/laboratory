#include <stdio.h>
#include <stddef.h>

#define ERR_OK 0
#define ERR_IO 1
#define CORR_IN 1
#define NO_NEG 2
#define ERR_RANGE 3
#define N 10

/* Функция принимает код ошибки.
   Затем определяет ошибку и выводит сообщение о ней*/
void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Incorrect input\n");
    else if (rc == NO_NEG)
        printf("No negetives elements\n");
    else
        printf("Unknown error\n");
}

/*  Находит среднее арифметическое отрицательный чисел, возвращает код ошибки и ср. арф., если оно есть.
    Функция принимает массив, его длину, код ошибки.*/
int find_average_neg(int const *arr, size_t const n, double *avg)
{   
    double sum = 0;
    size_t count = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
            ++count;
        }
    }

    if (count == 0)
        return NO_NEG;
    
    *avg = sum / count;

    return ERR_OK;
}

/*  Функция заполняет массив элементами до нужного размера.
    Возвращает массив и код ошибки.
    Функция принимает массив и его длину.*/
int input_arr(int *arr, size_t const n)
{   
    printf("Enter your numbers: \n");

    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != CORR_IN)
            return ERR_IO;
    }

    return ERR_OK;
}

int main(void)
{
    int n, rc;

    double average_neg = 0;

    printf("Enter your n: ");
    rc = scanf("%d", &n);

    if (rc != CORR_IN)
    {
        printf("Incorrect input\n");
        return ERR_IO;
    }

    if (n <= 0 || n > N)
    {
        printf("Out of range\n");
        return ERR_RANGE;
    }

    size_t a_n = (size_t) n;

    int arr[N];

    rc = input_arr(arr, a_n);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    rc = find_average_neg(arr, a_n, &average_neg);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    printf("Your average neg: %lf\n", average_neg);
    return ERR_OK;
}
