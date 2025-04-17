#include "line.h"

line_t formLine(line_t &line, const point_t &a, const point_t &b)
{
    line.pointA = a;
    line.pointB = b;
}
