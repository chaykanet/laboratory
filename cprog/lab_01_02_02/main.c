#include <stdio.h>
#include <math.h>

#define ERR_OK 0

/*  
    Функция принимает координаты двух точек.
    Возвращает длину отрезка.
*/
double len(double xa, double xb, double ya, double yb)
{
    return sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
}

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    double ab, ac, bc, p;

    printf("Your coordinates: ");
    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);

    ab = len(xa, xb, ya, yb);

    ac = len(xa, xc, ya, yc);

    bc = len(xb, xc, yb, yc);

    p = ac + ab + bc;

    printf("Your perimeter: %lf\n", p);

    return ERR_OK;
}
