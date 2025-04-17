#include "spline.h"

#include <iostream>

#include <cmath>
#include <vector>

static size_t nearestNode(std::vector<double> xValues, double value)
{
    size_t i = 0;

    while (i < xValues.size() && xValues[i] < value)
        ++i;

    if (i == xValues.size())
        --i;

    return i;
}

double approximate(std::pair<double, double> inter, std::vector<double> coeffs)
{
    double sum = coeffs[0];

    for (int i = 1; i <= 3; ++i)
        sum += coeffs[i] * std::pow(inter.second - inter.first, i);

    return sum;
}

Interp interSpline(const double &xValue, const std::vector<Point> &points)
{
    InterpError_t rc = InterpError_t::ERR_OK;

    std::vector<double> xValues(points.size(), 0);
    std::vector<double> yValues(points.size(), 0);

    for (size_t i = 0; i < points.size(); ++i)
    {
        xValues[i] = points[i].x;
        yValues[i] = points[i].y;
    }

    size_t index = nearestNode(xValues, xValue);

    std::pair<double, double> xPair;
    if (index == 0)
        xPair = std::make_pair(0, xValues[index]);
    else
        xPair = std::make_pair(xValues[index], xValues[index + 1]);

    coeffs_t coeffs = sweep(xValues, yValues, 0, 0);

    double yValue = approximate(xPair, coeffs[index]);

    Interp result = Interp(rc, yValue);

    return result;
}

coeffs_t sweep(const std::vector<double> &xValues, const std::vector<double> &yValues,
                double lEdge, double rEdge)
{   
    size_t N = xValues.size();

    std::vector<double> h(N - 1, 0);
    std::vector<double> ksi(N - 1, 0);
    std::vector<double> et(N - 1, lEdge / 2);

    for (size_t i = 1; i <= N - 1; ++i)
        h[i - 1] = xValues[i] - xValues[i - 1];

    double A, B, D, F;
    for (size_t i = 1; i < ksi.size(); ++i)
    {   
        A = h[i - 1];
        B = -2 *(h[i - 1] + h[i]);
        D = h[i];
        F = -3 * ((yValues[i + 1] - yValues[i]) / h[i] - (yValues[i] - yValues[i - 1]) / h[i - 1]);
        ksi[i] = D / (B - A * ksi[i - 1]);
        et[i] = (A * et[i - 1] + F) / (B - A * ksi[i - 1]);

        if (F != -6)
            F = -6;
        std::cout << A<< ' ' << B<< ' ' << D << ' ' << F << std::endl;
    }

    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> d;
    std::vector<double> C(N, 0);

    C[N - 1] = rEdge / 2;
    C[0] = lEdge / 2;

    // C(N+1) = 0;
    for (ssize_t  i = N - 2; i > 0; --i)
        C[i] = ksi[i + 1] * C[i + 1] + et[i + 1];

    for (size_t i = 1; i < N; ++i)
    {
        a.push_back(yValues[i - 1]);
        b.push_back((yValues[i] - yValues[i - 1]) /
                        h[i - 1] - 1/3 * h[i - 1] * (C[i] + 2 * C[i - 1]));
        d.push_back((C[i] - C[i - 1]) / (3 * h[i - 1]));
    }

    coeffs_t coeffs;
    for (size_t i = 0; i < N - 1; ++i)
    {   
        
        // std::cout << a[i]<< ' ' << b[i]<< ' ' << C[i] << ' ' << d[i] << std::endl;
        std::vector<double> abcd = {a[i] ,b[i], C[i], d[i]};
        coeffs.push_back(abcd);
    }

    std::cout << std::endl;

    return coeffs;
}
