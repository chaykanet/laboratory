#ifndef INTERP_H
#define INTERP_H

#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <deque>

using matrix3d = std::vector<std::vector<std::vector<double>>>;

enum class InterpError_t {
    ERR_OK,
    ERR_SOURCE,
    ERR_RANGE_XYVALUES,
    ERR_RANGE_POLYNOM,
    ERR_MISS_DERIVATIVE
};

class Interp
{
public:
    InterpError_t error;
    double value;
    Interp(InterpError_t err, double val);
};

class Point
{
public:
    double x;
    double y;
    double dy;
    double ddy;
};

Interp interpolate(std::vector<Point> sources, double xValue, int polyDegree, int mode);

#endif // INTERP_H
