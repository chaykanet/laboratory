
#ifndef STRING_FUNC_H
#define STRING_FUNC_H

#include <string.h>

/*  Функция возвращет указатель на первое вхождение в str из набора символов strCharSet.
    Возвращает NULL, если отсутствует вхождение.
    Функция принимает строку str, набор символов strCharSet.
*/
char *my_strpbrk(char const *str, char const *strcharset);

/*  Возвращает целочисленное значение, указывающее длину подстроки,
    str которая состоит полностью из символов strCharSet
    Если str начинается символ не в strCharSet, функция возвращает значение 0.
    Функция принимает строку str, набор символов strCharSet.
*/
size_t my_strspn(char const *str, char const *strcharset);

/*  Эти функции возвращают индекс первого символа в str, который находится в strCharSet.
    Если ни один из символов в str не находится в strCharSet, то возвращаемое значение представляет собой длину str.
    Функция принимает строку str, набор символов strCharSet.
*/
size_t my_strcspn(char const *str, char const *strcharset);

/*  Возвращает указатель на первое вхождение в str символа c.
    Возвращает NULL, если отсутствует вхождение символа с.
    Функция принимает строку str, символ c.
*/
char *my_strchr(char const *str, int c);

/*  Возвращает указатель на последнее вхождение в str символа c.
    Возвращает NULL, если отсутствует вхождение символа с.
    Функция принимает строку str, символ c.
*/
char *my_strrchr(char const *str, int c);

#endif
