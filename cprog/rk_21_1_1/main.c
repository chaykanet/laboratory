#include <stdio.h>
#include <stdlib.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERL_MIN 100
#define ERL_MAX 200
#define ERR_RANGE 3
#define DIV_BY_TEN 10
#define TEN 10

int find_posithion_max(int const num)
{
    int tmp = num, digit;
    int posithion = 0, count = 0;
    int max = tmp % DIV_BY_TEN;
    
    while (tmp != 0)
    {   
        count++;
        digit = tmp % DIV_BY_TEN;

        if (digit >= max)
        {
            max = digit;
            posithion = count;
        }
        tmp /= DIV_BY_TEN;
    }

    return posithion;
}

int find_posithion_min(int const num)
{
    int tmp = num, digit;
    int posithion = 0, count = 0;
    int min = tmp % DIV_BY_TEN;
    
    while (tmp != 0)
    {   
        count++;
        digit = tmp % DIV_BY_TEN;

        if (digit <= min)
        {
            min = digit;
            posithion = count;
        }
        tmp /= DIV_BY_TEN;
    }

    return posithion;
}

int find_erl_min_max(int const n)
{
    int tmp = n;
    int posithion_min;
    int posithion_max;

    posithion_max = find_posithion_max(tmp);
    posithion_min = find_posithion_min(tmp);

    if (posithion_max == posithion_min)
        return ERR_IO;

    if (posithion_max > posithion_min)
        return ERL_MAX;
    else
        return ERL_MIN;
}

int main(void)
{
    int n, rc;
    rc = scanf("%d", &n);

    if (rc != 1)
        return ERR_IO;
    
    if (n < 0)
        n = abs(n);

    if (0 <= n && n < TEN)
        return ERR_RANGE;

    rc = find_erl_min_max(n);

    if (rc == ERR_IO)
        return ERR_IO;

    if (rc == ERL_MIN)
        printf("min max\n");
    else
        printf("max min\n");

    return ERR_OK;
}
