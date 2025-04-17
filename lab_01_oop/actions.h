#ifndef ACTIONS_H
#define ACTIONS_H

#include "error.h"

typedef struct vec_t vec_t;
typedef struct rotate_t rotate_t;
typedef struct scale_t scale_t;

struct vec_t
{
    double directionX;
    double directionY;
    double directionZ;
};

struct rotate_t
{
    double angleX;
    double angleY;
    double angleZ;
};

struct scale_t
{
    double kX;
    double kY;
    double kZ;
};

vec_t initVec(double dX, double dY, double dZ);

scale_t initScale(double kx, double ky, double kz);

rotate_t initRotate(double angleX, double angleY, double angleZ);

#endif // ACTIONS_H
