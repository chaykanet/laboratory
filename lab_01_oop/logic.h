#ifndef LOGIC_H
#define LOGIC_H

#include <stdlib.h>

struct point_t
{
    double x;
    double y;
    double z;
};

struct edge_t
{
    point_t first;

    point_t second;
};

struct arr_point_t
{
    point_t *arr;

    size_t len;
};


#endif // LOGIC_H
