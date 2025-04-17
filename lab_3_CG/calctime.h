#ifndef CALCTIME_H
#define CALCTIME_H

#include <vector>

#include "algorithms.h"

using timesList = std::vector<double>;

class calcTime
{
public:
    calcTime();

    timesList calcTimesForN(size_t n, int x1, int y1, int x2, int y2);
};

#endif // CALCTIME_H
