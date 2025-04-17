#ifndef SPLINE_H
#define SPLINE_H

#include <cstdlib>
#include <vector>

#include "interp.h"

using coeffs_t = std::vector<std::vector<double>>;

coeffs_t sweep(const std::vector<double> xValues, const std::vector<double> yValues,
               double lEdge, double rEdge);

#endif // SPLINE_H
