#include <stdio.h>
#include <math.h>

#define ERR_IO 1
#define ERR_OK 0
#define CORRECT_IN 2


/*  Функция принимает целое число a и его целую степень n.
    Возвращает целое число a, возведенное в эту степень.
*/
int power(int a, int n)
{   
    int tmp = a;

    for (int i = 0; i < n - 1; ++i)
        a *= tmp;
    
    return a;
}

int main(void)
{
    int a, n, ans;
    int rc;

    printf("Enter your a, n: ");

    rc = scanf("%d%d", &a, &n);

    if (rc != CORRECT_IN)
    {
        printf("Incorrect input\n");
        return ERR_IO;
    }

    if (n <= 0)
    {
        printf("Incorrect input\n");
        return ERR_IO;
    }

    ans = power(a, n);
    printf("Your a^n: %d\n", ans);

    return ERR_OK;
}
