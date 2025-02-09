//  Файл содержит мнемонические имена и струтуру, описывающую характеристики объекта.

#ifndef OBJECT_T_H
#define OBJECT_T_H

#include <stdio.h>
#include <stdlib.h>
#include "errcodes.h"
#include "my_limits.h"

#define SMALLER -1
#define BIGGER 1
#define EQUAL 0

typedef struct object 
{    
    char *name_object;  // название объекта.
    
    double mass;  // масса.
    
    double volume;  // объем.
} object_t;

/*  Функция выводит информацию об объекте на экран.
    Принимает указатель на переменную структурного типа object.
*/
void print_object(object_t const *object);

/*  Функция считывает объект из файла.
    Функция принимает файл, указатель на объект.
    Возвращает код ошибки.
*/
int read_object(FILE *txt, object_t *object);

/*  Функция сравнивает объекты по их плотности.
    Функция  принимает указатели на два объекта first и second. 
    Возвращает код BIGGER, если плотность превого больше, SMALLER - если меньше, иначе EQUAl.
*/
int compare_density(void const *first, void const *second);

/*  Функция освобождает память выделенную под объект.
    Функция принимает указатель на object.
*/
void free_object(object_t *object);

/*  Функция инициализирует поля структуры object.
    Функция принимает указатель на структуру object, строку name, вещественные значения mass, volume.
    Возвращает код ошибки.
*/
int init_object(object_t *object, char *name, double mass, double volume);

#endif
