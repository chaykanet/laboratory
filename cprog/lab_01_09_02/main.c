#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define ERR_IO 1
#define ERR_OK 0
#define CORRECT_IN 1

/*  
    Функция возвращает значение фунции g.
    Для n
    int -> double для верных вычислений.
    Иначе 1 / n = 0;
*/ 
double g_sum(int n, double sum)
{   
    return (1 / (double) n) * sum;
}


/*  
    Функция принимает ввод последовательности по концевому признаку.
    В случае правильного выполенния выводит значение функции g
    и возвращает верное выполнение.
    Иначе возвращает неверное выполнение.
*/ 
int sequence(double *sum_g)
{
    int n = 0, rc;
    double x, sum = 0;

    rc = scanf("%lf", &x);

    if (rc != CORRECT_IN || x < 0)
        return ERR_IO;

    do
    {
        ++n;

        sum += sqrt(n + x);

        if (scanf("%lf", &x) != CORRECT_IN)
            return ERR_IO;
    }
    while (x >= 0 && rc == CORRECT_IN);

    *sum_g = g_sum(n, sum);

    return ERR_OK;
}

int main(void)
{
    int result;
    double sum_g = 0;
    result = sequence(&sum_g);
    
    if (result == ERR_OK)
    {
        printf("Your g(x): %lf\n", sum_g);
        return ERR_OK;
    }
    else
    {   
        printf("Incorrect input\n");
        return ERR_IO;
    }
}
