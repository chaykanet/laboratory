#include "squareapprox.h"

#include <cmath>

squareApprox::squareApprox(){};

double squareApprox::approximateFor1D(double xValue, const std::vector<double> &coeffs)
{
    double funcValue = 0;

    for (size_t i = 0; i < coeffs.size(); ++i)
        funcValue += coeffs[i] * pow(xValue, i);

    return funcValue;
}

// a0 + a1x + a2y

// 3 + 3x - 4y

static double funcFor2DFor1Degree(double xValue, double yValue, const std::vector<double> &coeffs)
{
    return coeffs[0] + coeffs[1] * xValue + coeffs[2] * yValue;
}

// a0 + a1x + a2y + a3xy + a4x^2 + a5y^2
static double funcFor2DFor2Degree(double xValue, double yValue, const std::vector<double> &coeffs)
{
    return coeffs[0] + coeffs[1] * xValue + coeffs[2] * yValue +
            coeffs[3] * yValue * xValue + coeffs[4] * xValue * xValue + coeffs[5] * yValue * yValue; 
}

double squareApprox::approximateFor2D(double xValue, double yValue, const std::vector<double> &coeffs)
{
    double funcValue = 0;
    
    if (coeffs.size() == 3)
        return funcFor2DFor1Degree(xValue, yValue, coeffs);
    else
        funcFor2DFor2Degree(xValue, yValue, coeffs);

    return funcValue;
}

std::vector<double> squareApprox::calcCoeffsFor1D(const std::vector<point> &points, int degree)
{
    gauss matrixCoeffs (points);
    
    std::vector<double> polinomCoeffs = matrixCoeffs.solveByGaussFor1D(degree);

    matrixCoeffs.printCoeffs();    

    return polinomCoeffs;
}

std::vector<double> squareApprox::calcCoeffsFor2D(const std::vector<point> &points, int degree)
{
    gauss matrixCoeffs (points);    
    
    std::vector<double> polinomCoeffs = matrixCoeffs.solveByGaussFor2D(degree);

    matrixCoeffs.printCoeffs();    

    return polinomCoeffs;
}

polinomValues squareApprox::calcPolinomFor1D(const std::vector<point> &points, const std::vector<double> &coeffs)
{
    polinomValues funcValues = {};

    for (size_t i = 0; i < points.size(); ++i)
    {
        double funcValue = approximateFor1D(points[i].x, coeffs);
        funcValues.emplace_back(funcValue, points[i].x);    
    }

    return funcValues;
}

polinomValues squareApprox::calcPolinomFor2D(const std::vector<point> &points, const std::vector<double> &coeffs)
{
    polinomValues funcValues = {};

    for (size_t i = 0; i < points.size(); ++i)
    {
        double funcValue = approximateFor2D(points[i].x, points[i].y, coeffs);
        funcValues.emplace_back(funcValue, points[i].x);    
    }

    return funcValues;
}

polinomValues squareApprox::approximatePolinomFor1D(const std::vector<point> &points, int degree)
{
    gauss matrixCoeffs (points);

    matrixCoeffs.print1D(degree);
    
    std::vector<double> polinomCoeffs = matrixCoeffs.solveByGaussFor1D(degree);
    
    return calcPolinomFor1D(points, polinomCoeffs);
}

polinomValues squareApprox::approximatePolinomFor2D(const std::vector<point> &points, int degree)
{
    gauss matrixCoeffs (points);
    
    matrixCoeffs.print2D(degree);    

    std::vector<double> polinomCoeffs = matrixCoeffs.solveByGaussFor2D(degree);
    
    return calcPolinomFor2D(points, polinomCoeffs);
}
