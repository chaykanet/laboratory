#ifndef POINT_H
#define POINT_H

#include <stddef.h>

#include "error.h"
#include "actions.h"

typedef struct point_t point_t;

struct point_t
{
    double x;
    double y;
    double z;
};

void defaultPoint(point_t &point);

myerror_t readPoint(point_t &point, FILE *file);

void movePoint(point_t &point, const vec_t &vector);

void initPoint(point_t &point, double x, double y, double z);

void coordinatesPoint(double &x, double &y, double &z, const point_t &point);

void scalePoint(point_t &point, const scale_t &scale, const point_t &center);

void rotatePoint(point_t &point, const point_t &center, const rotate_t& rotate);

#endif // POINT_H
