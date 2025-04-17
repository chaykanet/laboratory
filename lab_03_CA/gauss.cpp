#include "gauss.h"
#include "iostream"

#include <cmath>

gauss::gauss(std::vector<point> _points)
{
    points = _points;
};

vector gauss::solveByGauss(matrix &A, vector &B)
{
    size_t k = A.size();
    for (size_t g = 0; g < k; ++g)
    {
        for (size_t i = g + 1; i < k; ++i)
        {
            double factor = A[i][g] / A[g][g];

            for (size_t j = g; j < k; ++j) {
                A[i][j] -= factor * A[g][j];
            }

            B[i] -= factor * B[g];
        }
    }

    // Обратный ход
    vector coeffs(k);
    for (int i = k - 1; i >= 0; --i)
    {
        coeffs[i] = B[i];
        
        for (size_t j = i + 1; j < k; ++j) {
            coeffs[i] -= A[i][j] * coeffs[j];
        }
        
        coeffs[i] /= A[i][i];
    }
    
    _coeffs = coeffs;

    return coeffs;
}


vector gauss::solveByGaussFor1D(int degree)
{
    size_t n = points.size();
    size_t k = degree + 1;

    // Создание матрицы системы уравнений
    matrix A(k, vector(k));
    vector B(k);

    // Заполнение матрицы (определитель грамма)
    for (size_t i = 0; i < k; ++i)
    {
        for (size_t j = 0; j < k; ++j)
        {
            for (size_t m = 0; m < n; ++m) {
                A[i][j] += pow(points[m].x, i + j) * points[m].p;
            }
        }

        for (size_t m = 0; m < n; ++m) {
            B[i] += points[m].y * pow(points[m].x, i) * points[m].p;
        }
    }
    
    return solveByGauss(A, B);
}

vector gauss::solveByGaussFor2D(int degree)
{
    size_t k = degree + 2;
    // Создание матрицы системы уравнений
    matrix A (k, vector(k));
    vector B(k);
    
    if (degree == 1)
    {
        for (const auto& p : points)
        {
            A[0][0] += 1 * p.p;
            A[0][1] += p.x * p.p;
            A[0][2] += p.y * p.p;
            B[0] += p.z;
            
            A[1][0] += p.x * p.p;
            A[1][1] += p.x * p.x * p.p;
            A[1][2] += p.x * p.y * p.p;
            B[1] += p.x * p.z * p.p;
            
            A[2][0] += p.y * p.p;
            A[2][1] += p.x * p.y * p.p;
            A[2][2] += p.y * p.y * p.p;
            B[2] += p.y * p.z * p.p;
        }
    }

    return solveByGauss(A, B);
}

void gauss::print1D(int degree)
{
    size_t n = points.size();
    size_t k = degree + 1;

    matrix A(k, vector(k));
    vector B(k);

    for (size_t i = 0; i < k; ++i)
    {
        for (size_t j = 0; j < k; ++j)
        {
            for (size_t m = 0; m < n; ++m) {
                A[i][j] += pow(points[m].x, i + j) * points[m].p;
            }
        }

        for (size_t m = 0; m < n; ++m) {
            B[i] += points[m].y * pow(points[m].x, i) * points[m].p;
        }
    }
    
    std::cout << "Matrix A:" << std::endl;
    for (size_t i = 0; i < k; ++i)
    {
        for (size_t j = 0; j < k; ++j)
            std::cout << A[i][j] << ' ';
        std::cout << std::endl;
    }
    
    std::cout << "Vector B:" << std::endl;
    for (size_t i = 0; i < k; ++i)
        std::cout << B[i] << ' ';
    
    std::cout << std::endl;
}

void gauss::print2D(int degree)
{
    size_t k = degree + 2;
    // Создание матрицы системы уравнений
    matrix A (k, vector(k));
    vector B(k);
    
    if (degree == 1)
    {
        for (const auto& p : points)
        {
            A[0][0] += 1 * p.p;
            A[0][1] += p.x * p.p;
            A[0][2] += p.y * p.p;
            B[0] += p.z;
            
            A[1][0] += p.x * p.p;
            A[1][1] += p.x * p.x * p.p;
            A[1][2] += p.x * p.y * p.p;
            B[1] += p.x * p.z * p.p;
            
            A[2][0] += p.y * p.p;
            A[2][1] += p.x * p.y * p.p;
            A[2][2] += p.y * p.y * p.p;
            B[2] += p.y * p.z * p.p;
        }
    }
    
    std::cout << "Matrix A:" << std::endl;
    for (size_t i = 0; i < k; ++i)
    {
        for (size_t j = 0; j < k; ++j)
            std::cout << A[i][j] << ' ';
        std::cout << std::endl;
    }
    
    std::cout << "Vector B:" << std::endl;
    for (size_t i = 0; i < k; ++i)
        std::cout << B[i] << ' ';
    
    std::cout << std::endl;
}

void gauss::printCoeffs()
{
    std::cout << "Коэффициенты:";

    for (size_t i = 0; i < _coeffs.size(); ++i)
        std::cout << _coeffs[i] << ' ';

    std::cout << std::endl;
}
