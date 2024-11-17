#include "st_big_num.h"

int take_num(char const *buffer, struct big_num *num)
{   
    char *p_st = (char *) buffer;

    if (!p_st)
        return ERR_IO;

    if (strchr(buffer, 'e') != strrchr(buffer, 'e'))
        return ERR_IO;

    char *p_k = strchr(buffer, 'e');
    
    if (strchr(buffer, '.') != strrchr(buffer, '.'))
        return ERR_IO;

    char *p_point = strchr(buffer, '.');
    
    if (!p_k && !p_point)  // число без "e" и ".".
    {   
        size_t i = strlen(buffer);
        size_t index = 0;

        if (*p_st == '+' || *p_st == '-')
        {   
            p_st++;
            i--;
        }

        if (i >= LEN_MANTISA)
            return ERR_IO;
        
        while (p_st != p_st + i - 1)
        {   
            if (isdigit(*(p_st + i - 1)))
            {
                num -> massive[index] = *(p_st + i - 1) - '0';
                num -> len++;
            }
            else
                return ERR_IO;

            i--;
            index++;
        }

        if (isdigit(*p_st))
        {
            num -> massive[index] = *(p_st + i - 1) - '0';
            num -> len++;
            num -> point_pos = 1 * (num -> len);
        }
        else if (*p_st == '-' || *p_st == '+')
        {
            num -> sign = *p_st;
            num -> point_pos = 1 * (num -> len);
        }
        else
            return ERR_IO;

        num -> power = 0;
    }

    if (p_point && !p_k)  // число без "e".
    {
        size_t i = strlen(buffer);

        if (i - 1 >= LEN_MANTISA)
            return ERR_IO;

        size_t index = 0;

        while (p_st != p_st + i - 1)
        {
            if (isdigit(*(p_st + i - 1)))
            {
                num -> massive[index] = *(p_st + i - 1) - '0';
                num -> len++;
            }
            else if (*(p_st + i - 1) == '.')
            {    
                num -> point_pos = i - 1;
                index--;
            }
            else
                return ERR_IO;
            
            i--;
            index++;
        }

        if (isdigit(*p_st))
        {
            num -> massive[index] = *(p_st + i - 1) - '0';
            num -> len++;
        }
        else if (p_point - p_st == 1 && !isdigit(*p_st))
            return ERR_IO;
        else if (*p_st == '+' || *p_st == '-')
        {
            num -> sign = *p_st;
            num -> point_pos--;
        }
        else if (p_st != p_point)
            return ERR_IO;

        num -> power = 0;
    }

    if (p_k && !p_point)  // число без ".".
    {   
        if (*p_st == '+' || *p_st == '-')
            p_st++;

        if (p_k - p_st >= LEN_MANTISA)
            return ERR_IO;

        if (p_k == p_st)
            return ERR_IO;

        size_t i = 0;
        size_t index = 0;

        while (p_st != p_k - i - 1)
        {
            if (isdigit(*(p_k - i - 1)))
            {
                num -> massive[index] = *(p_k - i - 1) - '0';
                num -> len++;
            }
            
            i++;
            index++;
        }

        if (isdigit(*p_st))
        {
            num -> massive[index] = *(p_st) - '0';
            num -> len++;
        }
        else if (*p_st == '+' || *p_st == '-')
            num -> sign = *p_st;
        else
            return ERR_IO;
        
        size_t j = 1, c = 1;

        if (*(p_k + j) == '-' || *(p_k + j) == '+')
        {   
            j++;
            c--;
        }
        
        while (*(p_k + j) != '\0')
        {   
            if (!isdigit(*(p_k + j)))
                return ERR_IO;
            j++;
            c++;
        }
        
        if (c - 1 > LEN_POWER)
            return ERR_IO;

        num -> power = atoi(p_k + 1);
        num -> point_pos = num -> len;
    }

    if (p_k && p_point)  // число с "e" и ".".
    {    
        if (*p_st == '+' || *p_st == '-')
        {
            num -> sign = *p_st;
            num -> len = 0;

            p_st++;
        }

        if (p_k - p_st > LEN_MANTISA)
            return ERR_IO;

        if (!isdigit(*p_st))
            return ERR_IO;

        size_t i = 1;
        size_t index = 0;

        while(p_k - i != p_st)
        {   
            if (isdigit(*(p_k - i)))
            {
                num -> massive[index] = *(p_k - i) - '0';
                num -> len++;
            }
            else if (p_k - i == p_point)
                index--;
            else
                return ERR_IO;
            
            i++;
            index++;
        }

        num -> point_pos = p_point - p_st;
        num -> massive[index] = *(p_st) - '0';
        num -> len++;

        size_t j = 1, c = 1;

        if (*(p_k + j) == '-' || *(p_k + j) == '+')
        {
            j++;
            c--;
        }
        
        while (*(p_k + j) != '\0')
        {   
            if (!isdigit(*(p_k + j)))
                return ERR_IO;
            j++;
            c++;
        }

        if (c - 1 > LEN_POWER)
            return ERR_IO;

        num -> power = atoi(p_k + 1);
    }


    if (*(buffer) == '+' || *(buffer) == '-')
        num -> sign = *(buffer);

    if (num -> massive[num -> len - 1] != 0 && num -> point_pos != 1)
        if (abs(num -> power) > MAX_POWER)
            return ERR_NULL;

    if (num -> sign == 0)
        num -> sign = '+';

    return ERR_OK;
}

void print_num(struct big_num num)
{   
    if (num.massive[num.len - 1] == 0 && num.point_pos == 1)
    {   
        printf("%c", num.sign);
        printf("%d.", num.massive[num.len - 1]);

        for (size_t i = num.len - 1; i != 0 ; i--)
            printf("%d", num.massive[i - 1]);

        printf("e%d\n", num.power);
    }
    else if (num.massive[0] == 0 && num.len == 0)
        printf("0.0e0");
    else
    {   
        printf("%c", num.sign);
        printf("0.");

        for (size_t i = num.len; i != 0 ; i--)
            printf("%d", num.massive[i - 1]);

        printf("e%d\n", num.power + num.point_pos);
    }
}
