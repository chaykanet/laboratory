#ifndef LINE_H
#define LINE_H

#include "error.h"
#include "point.h"

typedef struct line_t line_t;

struct line_t
{
    point_t pointA;
    point_t pointB;
};

myerror_t formLine(const point_t &a, const point_t &b);

#endif // LINE_H
