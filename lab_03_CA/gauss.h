#ifndef GAUSS_H
#define GAUSS_H

#include "point.h"

using vector = std::vector<double>;
using matrix = std::vector<std::vector<double>>;
using basisvec = std::vector<std::pair<size_t, size_t>>;

class gauss
{
    std::vector<point> points;

    vector _coeffs;
public:
    gauss() {};
    
    gauss(std::vector<point> _points);
    
    vector solveByGaussFor1D(int degree);

    vector solveByGaussFor2D(int degree);
    
    vector solveByGauss(matrix &A, vector &B);
    
    void print1D(int degree);

    void print2D(int degree);

    void printCoeffs();

    matrix matrixFor1D(int degree);    
};

#endif // GAUSS_H
