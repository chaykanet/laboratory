#ifndef ALGOSCALC_H
#define ALGOSCALC_H

#include "algorithms.h"

#include <vector>

using times = std::vector<double>;

using algosTimes = std::vector<times>;

class algoscalc : public Algorithms
{
public:
    algoscalc();

    algosTimes calcForRCircle(double R);

    algosTimes calcForabEllipse(double a, double b);
};

#endif // ALGOSCALC_H
