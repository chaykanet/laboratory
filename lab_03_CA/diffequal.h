#ifndef DIFFEQUAL_H
#define DIFFEQUAL_H

#include "gauss.h"

class diffequal : public gauss 
{
    vector _points;

    vector _coeffs;
public:
    diffequal();

    void solveForM(int M);

    void solveFor2M();

    void solveFor3M();

    void fprintFor2M();

    void fprintFor3M();

    void print();
    
    double approximateEq(double x);
};

#endif // DIFFEQUAL_H
