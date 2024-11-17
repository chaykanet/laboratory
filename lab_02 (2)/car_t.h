#ifndef CAR_T_H
#define CAR_T_H

#include <stdbool.h>

#define MAX_LEN_STR 20
#define BUFFER 256

typedef struct  // Структура нового состояния машины.
{   
    unsigned short serlife;
} newstate_t;

typedef struct // Структура использованног состояния машины.
{   
    unsigned short yearof;
        
    unsigned mileage;

    unsigned short owners;

    unsigned short repairs;
} oldstate_t;

typedef union // Структура состояния машины.
{
    newstate_t newstate;
    oldstate_t oldstate;
} state_t;

typedef struct car // Структура машины.
{
    char mark[MAX_LEN_STR];

    char country[MAX_LEN_STR];

    char color[MAX_LEN_STR];

    bool garanty;

    unsigned price;

    bool state_new;

    state_t state; 
 
} car_t;

#endif
