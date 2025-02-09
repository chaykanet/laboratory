//  Файл содержит мнемонические имена и струтуру, описывающую характеристики объекта.

#ifndef OBJECT_T_H
#define OBJECT_T_H

#include <stdio.h>
#include "limits.h"

#define SMALLER -1
#define BIGGER 1
#define EQUAL 0

struct object_t 
{    
    char name_object[MAX_LEN_NAME_OBJ];  // название объекта.
    
    double mass;  // масса.
    
    double volume;  // объем.
};

/*  Функция выводит информацию об объекте на экран.
    Принимает указатель на переменную структурного типа object.
*/
void print_object(struct object_t const *object);

/*  Функция считывает объект из файла.
    Функция принимает файл, указатель на объект.
    Возвращает код ошибки.
*/
int read_object(FILE *txt, struct object_t *object);

/*  Функция сравнивает объекты по их плотности.
    Функция  принимает указатели на два объекта first и second. 
    Возвращает код BIGGER, если плотность превого больше, SMALLER - если меньше, иначе EQUAl.
    Если плотность невозможно определить возвращает код ошибки. 
*/
int compare_density(struct object_t const *first, struct object_t const *second);

#endif
