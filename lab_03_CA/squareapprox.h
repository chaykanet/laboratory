#ifndef SQUAREAPPROX_H
#define SQUAREAPPROX_H

#include "vector"

#include "point.h"
#include "gauss.h"

using polinomValues = std::vector<std::pair<double, double>>;

class squareApprox
{
public:
    squareApprox();
    
    double approximateFor1D(double xValue, const std::vector<double> &coeffs);

    double approximateFor2D(double xValue, double yValue, const std::vector<double> &coeffs);

    vector calcCoeffs(const std::vector<point> &points, int degree);

    vector calcCoeffsFor1D(const std::vector<point> &points, int degree);

    vector calcCoeffsFor2D(const std::vector<point> &points, int degree);

    polinomValues approximatePolinomFor1D(const std::vector<point> &points, int degree);
    
    polinomValues approximatePolinomFor2D(const std::vector<point> &points, int degree);

    polinomValues calcPolinomFor1D(const std::vector<point> &points, const std::vector<double> &coeffs);
    
    polinomValues calcPolinomFor2D(const std::vector<point> &points, const std::vector<double> &coeffs);
};

#endif // SQUAREAPPROX_H
