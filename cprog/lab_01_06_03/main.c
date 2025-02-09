#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1
#define UNCERT 3
#define INCOR_LINE 1
#define UPPER_LINE 0
#define ON_LINE 1
#define UNDER_LINE 2
#define CORRECT_IN 6
#define EPSILON 1e-9

/*  
    Функция получает координаты двух точек Q, R прямой и координату x точки P.
    Определяет уравнение прямой, не являющейся вертикальной.
    Возвращает значение функции в этой абсциссе.
*/ 
double value(double x_q, double y_q, double x_r, double y_r, double x_p)
{
    double b, k;

    k = (y_q - y_r) / (x_q - x_r);
    b = y_q - k * x_q;

    return k * x_p + b;
}

/*  
    Функция определяет положение точки P относительно прямой.
    Получает координаты точек Q, R, P.
    Возвращает код ошибки и код положения точки.
*/ 
void position(double x_q, double y_q, double x_r, \
double y_r, double x_p, double y_p, int *error, int *result)
{
    double value_func;

    if (fabs(x_q - x_r) < EPSILON && fabs(y_q - y_r) < EPSILON)
    {
        *error = INCOR_LINE;
        return;
    }

    if (fabs(x_q - x_r) < EPSILON)
    {
        if (fabs(x_q - x_p) < EPSILON)
        {
            *result = ON_LINE;
            *error = ERR_OK;
            return;
        }
        else
        {
            *error = UNCERT;
            return;
        }
    }

    value_func = value(x_q, y_q, x_r, y_r, x_p);

    if (fabs(y_p - value_func) < EPSILON)
    {
        *result = ON_LINE;
        *error = ERR_OK;
        return;
    }
    else if (y_p < value_func)
    {
        *result = UNDER_LINE;
        *error = ERR_OK;
        return;
    }
    else
    {
        *result = UPPER_LINE;
        *error = ERR_OK;
        return;
    }
}

int main(void)
{
    double x_q, y_q, x_r, y_r, x_p, y_p;
    
    int rc;
    int result, error;

    printf("Enter coordinates Q, R, P: ");
    rc = scanf("%lf%lf%lf%lf%lf%lf", &x_q, &y_q, &x_r, &y_r, &x_p, &y_p);

    if (rc != CORRECT_IN)
    {
        printf("Incorrect input\n");
        return ERR_IO;
    }

    position(x_q, y_q, x_r, y_r, x_p, y_p, &error, &result);
    
    if (error == INCOR_LINE)
    {
        printf("Incorrect input\n");
        return INCOR_LINE;
    }

    if (error == UNCERT)
    {
        printf("Uncertainty\n");
        return UNCERT;
    }
    else
    {
        if (result == ON_LINE)
        {
            printf("1\n");
            return ERR_OK;
        }

        if (result == UNDER_LINE)
        {
            printf("2\n");
            return ERR_OK;
        }

        if (result == UPPER_LINE)
        {
            printf("0\n");
            return ERR_OK;
        }
    }
} 
