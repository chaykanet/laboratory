#include "diffequal.h"

#include <iostream>
#include <fstream>

static double u_0(double x)
{
    return 1 - x;
}

static double u_1(double x)
{
    return x * x - x;
}

static double u_2(double x)
{
    return x * x * x - x;
}

static double u_3(double x)
{
    return x * x * x * x- x;
}

static double func_1(double x)
{
    return 3 * x * x - 2 * x + 2;
}

static double func_2(double x)
{
    return 4 * x * x * x + 4 * x;
}

static double func_3(double x)
{
    return 5 * x * x * x * x + 12 * x * x - 2 * x; 
}

static double func_eq(double x)
{
    return 4 * x - 1;
}

diffequal::diffequal()
{
    double x = 0.0;

    while (x <= 1.0)
    {
        _points.push_back(x);
        x += 0.1;
    }
}

double diffequal::approximateEq(double x)
{
    double y = 0;    

    if (_coeffs.size() == 2)
        y = u_0(x) + _coeffs[0] * u_1(x) + _coeffs[1] * u_2(x);
    else if (_coeffs.size() == 3)
        y = u_0(x) + _coeffs[0] * u_1(x) + _coeffs[1] * u_2(x) + _coeffs[2] * u_3(x);
    
    return y;
}

void diffequal::solveFor2M()
{
    matrix A(2, vector(2));
    vector B(2);

    for (auto point : _points)
    {
        A[0][0] += func_1(point) * func_1(point);
        A[0][1] += func_1(point) * func_2(point);
        A[1][0] += func_1(point) * func_2(point);
        A[1][1] += func_2(point) * func_2(point);

        B[0] += func_eq(point) * func_1(point);
        B[1] += func_eq(point) * func_2(point);
    }
    
    _coeffs = solveByGauss(A, B);
}

void diffequal::solveFor3M()
{
    matrix A(3, vector(3));
    vector B(3);

    for (auto point : _points)
    {
        A[0][0] += func_1(point) * func_1(point);
        A[0][1] += func_1(point) * func_2(point);
        A[0][2] += func_1(point) * func_3(point);
        
        A[1][0] += func_2(point) * func_1(point);
        A[1][1] += func_2(point) * func_2(point);
        A[1][2] += func_2(point) * func_3(point);
                
        A[2][0] += func_3(point) * func_1(point);
        A[2][1] += func_3(point) * func_2(point);
        A[2][2] += func_3(point) * func_3(point);

        B[0] += func_eq(point) * func_1(point);
        B[1] += func_eq(point) * func_2(point);
        B[2] += func_eq(point) * func_3(point);
    }
    
    _coeffs = solveByGauss(A, B);
}

void diffequal::print()
{
    for (auto c : _coeffs)
    {
        std::cout << c << ' ';    
    }

    std::cout << std::endl;
}

void diffequal::fprintFor2M()
{
    std::ofstream file("de_out.txt");

    for (auto x : _points)
    {
        double y = approximateEq(x);
        
        file << x << ' ' << y << std::endl;
    }

    file.close();
}

void diffequal::fprintFor3M()
{
    std::ofstream file("de_out.txt");

    for (auto x : _points)
    {
        double y = approximateEq(x);
        
        file << x << ' ' << y << std::endl;
    }

    file.close();
}

void diffequal::solveForM(int M)
{
    matrix A(M, vector(M, 0.0));
    vector B(M, 0.0);

    for (auto x : _points)
    {
        vector f(4);
        f[0] = func_1(x);
        f[1] = func_2(x);
        f[2] = func_3(x);
        for (int i = 0; i < M; ++i) {
            B[i] += func_eq(x) * f[i];
            
            for (int j = i; j < M; ++j)
            {
                double product = f[i] * f[j];
                A[i][j] += product;
                
                if (i != j)
                {
                    A[j][i] += product;
                }
            }
        }
    }

    _coeffs = solveByGauss(A, B);
}
