#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define ERR_OK 0
#define ERR_IO 1
#define CORR_IN 1
#define ERR_RANGE 3
#define N 10
#define EMPTY 2

/* Функция принимает код ошибки.
   Затем определяет ошибку и выводит сообщение о ней*/
void print_err(int const rc)
{
    if (rc == ERR_IO)
        printf("Incorrect input\n");
    else if (rc == EMPTY)
        printf("New array is empty\n");
    else
        printf("Unknown error\n");
}

/*  Функция выводит массив на экран.
    Функция принимает массив и его длину.*/
void print_array(size_t const n, int const *arr)
{
    printf("Your new array: ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/*  Возвращает истину если число является полным квадратом, иначе ложь.
    Функция принимает число.*/
bool is_needed(int const num)
{   
    if (num == 1)
        return true;
        
    int tmp = 1;
    while (tmp < num)
    {
        if (tmp * tmp == num)
            return true;
        ++tmp;
    }

    return false;
}

/*  Функция удаляет из массива элемент под этим индексом.
    Возвращает изменненый массив.
    Функция  принимает массив, его длину, индекс элемента.*/
void delete_index(int *arr, size_t *n, size_t index)
{   
    if (index == *n - 1)
    {
        *n -= 1;
        return;
    }

    for (size_t i = index; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    *n -= 1;
}

/*  Фильтрует массив, удаляя числа, являющиеся полными квадратами.
    Возвращает измененный массив, его длину и код ошибки.
    Функция принимает массив, его длину.*/
void delete_sq(int *arr, size_t *n)
{   
    size_t i = 0;

    while (i < *n)
    {
        if (!is_needed(arr[i]))
            i++;
        else
            delete_index(arr, n, i);
    }
}

/*  Далее заполняет массив элементами до нужного размера.
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
    int rc;
    int n;

    printf("Enter your n: ");

    if (scanf("%d", &n) != CORR_IN)
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

    rc = input_arr(arr, n);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    }

    delete_sq(arr, &a_n);

    if (a_n == 0)
    {
        print_err(EMPTY);
        return EMPTY;
    }

    print_array(a_n, arr);

    return ERR_OK;
}
