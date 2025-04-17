#ifndef ALGOSCALC_H
#define ALGOSCALC_H

#include <stdlib.h>

class AlgosCalc
{
public:
    AlgosCalc() {};

    void Wu(int x1, int y1, int x2, int y2) const;

    void DDA(int x1, int y1, int x2, int y2) const;
    
    void Bresenham(int x1, int y1, int x2, int y2) const;
    
    void BresenhamUnStep(int x1, int y1, int x2, int y2) const;
    
    void BresenhamDouble(double x1, double y1, double x2, double y2) const;
    
    size_t calcStepWu(double x1, double y1, double x2, double y2) const;
    
    size_t calcStepDDA(int x1, int y1, int x2, int y2) const;
    
    size_t calcStepBresenham(int x1, int y1, int x2, int y2) const;
    
    size_t calcStepBresenhamDouble(double x1, double y1, double x2, double y2) const;
    
    size_t calcStepBresenhamUnStep(int x1, int y1, int x2, int y2) const;
};

#endif // ALGOSCALC_H
