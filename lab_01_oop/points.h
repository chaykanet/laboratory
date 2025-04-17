#ifndef POINTS_H
#define POINTS_H

#include "point.h"
#include "error.h"

typedef struct points_t points_t;

struct points_t
{
    point_t *arr;

    size_t len;
};

void freePoints(points_t &points);

void defaultPoints(points_t &points);

myerror_t allocPoints(point_t **points, size_t len);

myerror_t freadPoints(points_t &points, FILE *file);

myerror_t movePoints(points_t &points, const vec_t &vector);

myerror_t scalePoints(points_t &points, const point_t &center, const scale_t &scale);

myerror_t rotatePoints(points_t &points, const point_t &center, const rotate_t& rotate);

#endif // POINTS_H
