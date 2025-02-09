#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_OW 1
#define CORRECT_IN 1


/*  
    Функция принимает вещественное число и точность вычислений.
    Возвращает приблизительную сумму ряда Тейлара для функции exp с данной точностью.
*/
double to_sum(double x, double e)
{
    int n = 0;
    double s = 1, tmp = 1;

    while (fabs(tmp) >= e)
    {
        n++;
        tmp = (x / n) * tmp;
        s += tmp;
    }

    return s;
}

int main(void)
{
    int rc;
    double x, e;
    double app_sum, exact_sum, abs_error, rel_error;

    printf("Enter your x: ");
    rc = scanf("%lf", &x);

    if (rc != CORRECT_IN)
    {
        printf("Incorrect input");
        return ERR_IO;
    }

    printf("Enter your e: ");
    rc = scanf("%lf", &e);

    if (rc != CORRECT_IN)
    {
        printf("Incorrect input");
        return ERR_IO;
    }

    if (e > 1 || e <= 0)
    {
        printf("Out of range");
        return ERR_OW;
    }

    app_sum = to_sum(x, e);
    exact_sum = exp(x);
    abs_error = fabs(app_sum - exact_sum);
    rel_error = abs_error / fabs(exact_sum);

    printf("Your app sum: %lf\n", app_sum);
    printf("Your exact sum: %lf\n", exact_sum);
    printf("Your abs error: %lf\n", abs_error);
    printf("Your rel error: %lf\n", rel_error);

    return ERR_OK;
}
