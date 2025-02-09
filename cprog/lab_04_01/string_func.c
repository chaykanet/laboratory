#include "string_func.h"
#include <stdbool.h>

/*  Функция возвращет указатель на первое вхождение в str из набора символов strCharSet.
    Возвращает NULL, если отсутствует вхождение.
    Функция принимает строку str, набор символов strCharSet.
*/
char *my_strpbrk(char const *str, char const *strcharset)
{
    char const *beg = NULL;
    
    size_t i = 0;
    size_t j = 0;

    while (str[i] != '\0' && beg == NULL)
    {
        while (strcharset[j] != '\0' && beg == NULL)
        {
            if (str[i] == strcharset[j])
                beg = &str[i];
            ++j;
        }

        j = 0;
        ++i;
    }

    return ((char *) beg);
}

/*  Возвращает целочисленное значение, указывающее длину подстроки,
    str которая состоит полностью из символов strCharSet
    Если str начинается символ не в strCharSet, функция возвращает значение 0.
    Функция принимает строку str, набор символов strCharSet.
*/
size_t my_strspn(char const *str, char const *strcharset)
{
    size_t len = 0;
    char const *px = str;
    bool finded = true;

    while (*px != '\0' && finded)
    {   
        char const *it = strcharset;
        finded = false;
        while (*it != '\0' && !finded)
        {
            if (*it == *px)
                finded = true;

            it++;
        }

        if (finded)
            len++;

        px++; 
    }

    return len;
}

/*  Эти функции возвращают индекс первого символа в str, который находится в strCharSet.
    Если ни один из символов в str не находится в strCharSet, то возвращаемое значение представляет собой длину str.
    Функция принимает строку str, набор символов strCharSet.
*/
size_t my_strcspn(char const *str, char const *strcharset)
{
    size_t index = 0;
    char const *px = str;
    bool finded = false;

    while (*px != '\0' && !finded)
    {   
        char const *it = strcharset;
        finded = false;
        while (*it != '\0' && !finded)
        {
            if (*it == *px)
                finded = true;

            it++;
        }

        if (!finded)
            ++index;

        px++; 
    }

    return index;
}

/*  Возвращает указатель на первое вхождение в str символа c.
    Возвращает NULL, если отсутствует вхождение символа с.
    Учитывается символ '\0'.
    Функция принимает строку str, символ c.
*/
char *my_strchr(char const *str, int c)
{   
    char const *beg = NULL;
    char const *cur = str;

    while (*cur != '\0' && beg == NULL)
    {
        if (*cur == c && beg == NULL)
            beg = cur;
        
        cur++;
    }
    
    if (beg)
        return ((char *) beg);
    else if (*cur == c)
        return ((char *) cur);

    return (0);
}

/*  Возвращает указатель на последнее вхождение в str символа c.
    Возвращает NULL, если отсутствует вхождение символа с.
    Учитывается символ '\0'.
    Функция принимает строку str, символ c.
*/
char *my_strrchr(char const *str, int c)
{   
    char const *bend = NULL;
    char const *cur = str;

    while (*cur != '\0')
    {
        if (*cur == c)
            bend = cur;
        
        cur++;
    }

    if (bend)
        return ((char *) bend);
    else if (*cur == c)
        return ((char *) cur);

    return (0);   
}
