#include "st_big_num_math.h"

/*  Вспомогательная функция.
    Возвращает true если число типа big_num равно 0, иначе false.
*/
static bool zero_check (struct big_num num);

/*  Вспомогательная функция.
    Принимает указатель на число num. 
    Возвращает число с развернутым массивом цифр.
*/
static void reverse_num (struct big_num *num);

/*  Вспомогательная функция.
    Смещает запятую и удаляет незначащие нули.
    Принимает указатель на число num.
*/
static void to_format (struct big_num *num);

/*  Вспомогательная функция. 
    Сравнивает целые числа.
    Принимает числа типа big_num num_1, num_2.
    Возвращает 1, если num_1 > num_2, если num_1 = num_2, то 2, иначе 0.
*/
static int to_compare(struct big_num num_1, struct big_num num_2);

int complex_devide(struct big_num *num_1, struct big_num *num_2, struct big_num *result)
{   
    if (zero_check(*num_2))
        return ERR_DATA;

    to_format(num_1);
    to_format(num_2);

    int rc = ERR_OK;
    struct big_num dvd = *num_1, s_dvd;

    bool success = false, clear = false, point = false, find = false;

    int index = num_1 -> len - 1, i;
    int index_res = 0;

    s_dvd.len = 0;
    result -> len = 0;

    while (!success)
    {   
        if (!clear)
        {   
            i = s_dvd.len;

            if (index < 0)
            {
                s_dvd.massive[i] = 0;

                if (!point)
                {
                    result -> point_pos = result -> len;
                    point = true;
                }
            }
            else
            {
                s_dvd.massive[i] = dvd.massive[index];
                index--;
            }

            i++;
            s_dvd.len++;
        }
        else
        {   
            if (clear && point)
                success = true;
        
            i = 0;
            s_dvd.len = 0;

            clear = false;
            
            continue;
        }

        reverse_num(&s_dvd);

        if (to_compare(s_dvd, *num_2))
        {   
            find = true;

            struct big_num tmp = s_dvd;
            struct big_num tmp_2 = *num_2;

            int t, t_1 = 0, t_2;

            t_2 = num_2 -> massive[num_2 -> len - 1];

            for (size_t i = num_2 -> len - 1; i < tmp.len; i++)
                t_1 += pow(TEN, (i - num_2 -> len + 1)) * tmp.massive[i];

            t = t_1 / t_2;
        
            if (t >= TEN)
                t = NINE;

            rc = simple_multy(&tmp_2, t);
            
            if (rc != ERR_OK)
                return rc;
            
            while (to_compare(tmp_2, tmp) == 1)
            {
                t--;

                tmp_2 = *num_2;

                rc = simple_multy(&tmp_2, t);

                if (rc != ERR_OK)
                    return rc;
            }

            if (result -> len < LEN_MANTISA - 1)
            {   
                result -> massive[index_res] = t;
                result -> len++;
                index_res++;
            }
            else
            {   
                size_t i = 0;
                if (t >= FIVE)
                {   
                    index_res--;

                    while (result -> massive[index_res - i] + 1 == TEN)
                    {
                        result -> massive[index_res - i] = 0;
                        i++;
                    }

                    result -> massive[index_res - i]++;
                }
                
                result -> len++;

                success = true;
                continue;
            }

            to_sub(&tmp, &tmp_2);

            s_dvd = tmp;

            if (zero_check(s_dvd))
                clear = true;
            
            if (clear && point)
                success = true;
        }
        else if (find)
        {   
            if (result -> len < LEN_MANTISA)
            {    
                result -> massive[index_res] = 0;
                result -> len++;
                index_res++;
            }
            else
                success = true;
        }

        reverse_num(&s_dvd);

        if (zero_check(s_dvd))
            clear = true;
    }

    if (abs(num_1 -> power - num_2 -> power + result -> point_pos) <= MAX_POWER)  // Степень числа.
        result -> power = num_1 -> power - num_2 -> power;
    else
        return ERR_NULL;

    if (num_1 -> sign == num_2 -> sign)  // Знак числа.
        result -> sign = num_1 -> sign;
    else
        result -> sign = '-';

    while (result -> massive[result -> len - 1] == 0 && result -> len > 1)
        result -> len--;

    reverse_num(result);

    return ERR_OK;
}

void reverse_num (struct big_num *num)
{
    for (size_t i = 0; i < num -> len / 2; i++)
    {   
        int tmp;
        tmp = num -> massive[i];
        num -> massive[i] = num -> massive[num -> len - i - 1];
        num -> massive[num -> len - i - 1] = tmp;
    }
}

bool zero_check(struct big_num num)
{
    bool zero = true;

    size_t i = 0;
    while (zero && i < num.len)
    { 
        if (num.massive[i] > 0)
            zero = false;

        i++;
    }

    return zero;
}

void to_format(struct big_num *num)
{   
    num -> power = num -> power - (num -> len - num -> point_pos);
    num -> point_pos = num -> len;

    while (num -> massive[num -> len - 1] == 0 && num -> len > 1)
    {   
        num -> len--;
        num -> point_pos--;
    }
}

int to_compare(struct big_num num_1, struct big_num num_2)
{
    if (num_1.len > num_2.len)
        return 1;
    if (num_1.len < num_2.len)
        return 0;

    for (size_t i = num_1.len; i > 0; i--)
    {
        if (num_1.massive[i - 1] > num_2.massive[i - 1])
            return 1;

        if (num_1.massive[i - 1] < num_2.massive[i - 1])
            return 0; 
    }

    return 2;
}

int simple_multy(struct big_num *num, int multy)
{   
    int ost = 0;
    int tmp;

    for (size_t i = 0; i < num -> len; i++)
    {   
        
        if (num -> massive[i] * multy + ost >= 10)
        {  
            tmp = num -> massive[i];

            num -> massive[i] = (num -> massive[i] * multy + ost) % 10;

            ost = (tmp * multy + ost) / 10;
        }
        else
        {
            num -> massive[i] = num -> massive[i] * multy + ost;
            
            ost = 0;
        }
    }

    if (ost && num -> len + 1 <= LEN_MANTISA)
    {   
        num -> massive[num -> len] = ost;
        num -> len++;
        num -> point_pos++;
    }
    else if (num -> len + 1 > LEN_MANTISA && ost)
    {
        for (size_t j = 0; j < num -> len - 1; j++)  // сдвиг числа вправо.
                num -> massive[j] = num -> massive[j + 1];
                
        num -> massive[num -> len - 1] = ost;

        num -> point_pos++;

        if (num -> power < MAX_POWER)
            num -> power++;
        else
            return ERR_NULL;
    }

    return ERR_OK;
}

int to_sub(struct big_num *num_1, struct big_num *num_2)
{
    int ost = 0;

    for (size_t i = 0; i < num_2 -> len; i++)
    {
        size_t j = i;

        int sub = num_2 -> massive[i];

        for (; j < num_1 -> len; j++)
        {
            if (num_1 -> massive[j] < sub + ost)
            {
                num_1 -> massive[j] = 10 - (sub + ost - num_1 -> massive[j]);

                ost = 1;

                sub = 0;
            }
            else
            {
                num_1 -> massive[j] = num_1 -> massive[j] - (sub + ost);

                ost = 0;

                sub = 0;
            }
        }
    }

    while (num_1 -> massive[num_1 -> len - 1] == 0 && num_1 -> len > 1)
    {
        num_1 -> len--;
        num_1 -> point_pos--;
    }
    
    return ERR_OK;
}

