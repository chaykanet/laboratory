#include "logic.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

size_t find_and_determine_month(char *str, char (*months)[WORD_LEN], char **month_point)
{   
    for (size_t i = 0; str[i] != '\0'; i++)
        str[i] = (char) tolower(str[i]);

    size_t i = 0;
    bool not_finded = true;
    bool is_correct_month = false;
    char *p;

    while (i < MONTHS_N && not_finded)
    {
        if ((p = strstr(str, months[i])))
            not_finded = false;

        ++i;
    }
    
    if (!not_finded)
    {
        if (p != str && *(p - 1) == ' ')
        {
            if (*(p + strlen(months[i - 1])) == ' ')
                is_correct_month = true;
        }
    }

    if (is_correct_month)
    {
        *month_point = p;
        return i;
    }
    else
    {
        *month_point = NULL;
        return MONTHS_N + 1;
    }
}

int find_day_and_year(char *str, char **point_day, char **point_year)
{   
    bool is_correct_day = false;
    bool is_correct_year = false;

    char *p_st, *p_en;
    
    p_st = strpbrk(str, INTEGERS);

    p_en = p_st;

    while (*p_en && isdigit(*p_en))
        ++p_en; 

    if (p_st == str && *p_en == ' ')
    {   
        *point_day = p_st; 
        is_correct_day = true;
    }
    else if (*p_en != ' ')
    {
        return ERR_DATA;
    }
    else if (isspace(*(p_st - 1)) && *p_en == ' ')
    {
        *point_day = p_st; 
        is_correct_day = true;
    }
    else
        return ERR_DATA;

    p_st = strpbrk(p_en, INTEGERS);

    if (!p_st || *(p_st - 1) != ' ')
        return ERR_DATA;

    p_en = p_st;

    while (*p_en != '\0' && isdigit(*p_en))
        p_en++;

    if (isspace(*p_en) || *p_en == '\0')
    {   
        *point_year = p_st; 
        is_correct_year = true;
    }

    if (is_correct_day && is_correct_year)
        return ERR_OK;
    else
        return ERR_DATA;
}

int check_data(char *str, char (*months)[WORD_LEN])
{   
    int rc = ERR_OK;
    char *p_day = NULL;
    char *p_year = NULL;
    char *p_month = NULL;

    size_t num_month = find_and_determine_month(str, months, &p_month);
 
    if (num_month > MONTHS_N)
        return ERR_DATA;

    rc = find_day_and_year(str, &p_day, &p_year);

    if (rc != ERR_OK)
        return ERR_DATA;

    rc = check_format(str, p_day, p_month, p_year);

    if (rc != ERR_OK)
        return ERR_DATA;

    int max_days;

    int day = atoi(p_day);
    int year = atoi(p_year);

    
    if (day <= 0 || year < MIN_YEAR || year > MAX_YEAR || num_month > MONTHS_N)
        return ERR_DATA;
    
    switch (num_month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            max_days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_days = 30;
            break;
        default:
            max_days = 28;
    }
    
    if ((year % DIV_BY_FOUR == 0 && year % DIV_BY_HUNDRED != 0) || year % DIV_BY_FOUR_HUNDRED == 0)
    {    
        if (num_month == SECOND_MONTH && day <= MAX_VES_FEBRUARY)
            return ERR_OK;
        
        if (day <= max_days)
            return ERR_OK;
        else
            return ERR_DATA;
    }
    else
    {
        if (day <= max_days)
            return ERR_OK;
        else
            return ERR_DATA;
    }
}

int check_format(char *str, char *p_day, char *p_month, char *p_year)
{   
    if (p_day >= p_month || p_month >= p_year)
        return ERR_DATA;

    char const *p = str;
    char const *px;

    while (isspace(*p))
        p++;

    if (p != p_day)
        return ERR_DATA;

    while (strchr(INTEGERS, *p))
        p++;

    while (*p == ' ' && p <= p_month)
        p++;

    if (p != p_month)
        return ERR_DATA;

    while (!isspace(*p) && p < p_year)
        p++;

    if (p == p_year)
        return ERR_DATA;

    while ((isspace(*p) && p < p_year))
        p++;

    if (p != p_year)
        return ERR_DATA;

    while (*p && strchr(INTEGERS, *p))
        p++;

    while (*p && isspace(*p))
        p++;

    if (*p == '\0')
        return ERR_OK;

    return ERR_DATA;
    // !isspace(*p) || *p == ' '
    // while (*px && px <= p_year + 4 && ((!isspace(*p) || *p == ' ') && (!isspace(*px) || *px == ' '))) 
    // {
    //     p++;
    //     px++;
    // }

    if (px <= p_year)
        return ERR_DATA;

    while (*px && isspace(*px))
        px++;


    if (*px == '\0')
        return ERR_OK;    

    return ERR_DATA; 
}
