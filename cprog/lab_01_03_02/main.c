#include <stdio.h>
#include <math.h>

#define ERR_OK 0

/*  Функция принимает спортивление резисторов.
    Возвращает общее сопративление.
*/
double resist(double r1, double r2, double r3)
{
    return 1 / (1 / r1 + 1 / r2 + 1 / r3);
}

int main(void)
{
    double r1, r2, r3;
    double r;

    printf("Enter your resistanses:\n");
    scanf("%lf%lf%lf", &r1, &r2, &r3);
    
    r = resist(r1, r2, r3);
    printf("Your common resistance: %lf\n", r);

    return ERR_OK;
}
