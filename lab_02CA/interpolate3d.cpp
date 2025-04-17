#include "spline.h"

#include <cmath>
#include "interp.h"
#include "algorithm"

#include <iostream>

#include "interpolate3d.h"

using matrix = std::vector<std::vector<double>>;

// std::vector<int> getClosestIndexes(double value, int n, int maxIndex)
// {
//     int half = (n - 1) / 2;

//     int valueIndex = std::round(value);
//     int start = std::max(0, valueIndex - half);
//     start = std::min(start, maxIndex - n + 1);

//     std::vector<int> indexes;

//     for (int i = 0; i < n; ++i)
//         indexes.push_back(start + i);

//     return indexes;
// }

double spline_2d(std::vector<double> &data, double x)
{
    std::vector<Point> pairs;

    for (size_t i = 0; i < data.size(); ++i)
        pairs.push_back({i, data[i], 0, 0});

    Interp res = Interp(InterpError_t::ERR_OK, 0);

    std::cout << "X:" << std::endl;
    res = interSpline(x, pairs);
    return res.value;
}

double spline_3d(matrix &data, double x, double y)
{
    std::vector<Point> pairs;
    for (size_t i = 0; i < data.size(); ++i)
    {   
        double interValue = spline_2d(data[i], x);
        std::cout << interValue << std::endl;
        pairs.push_back({i, interValue, 0, 0});
    }
    
    Interp res = Interp(InterpError_t::ERR_OK, 0);
    std::cout << "Y:" << std::endl;
    res = interSpline(y, pairs);

    return res.value;
}

double spline_4d(matrix3d &data, Point3d &point)
{
    std::vector<Point> pairs;
    for (size_t i = 0; i < data.size(); ++i)
    {
        double interValue = spline_3d(data[i], point.x, point.y);
        pairs.push_back({i, interValue, 0, 0});
    }
    
    Interp res = Interp(InterpError_t::ERR_OK, 0);
    std::cout << "Z:" << std::endl;
    res = interSpline(point.z, pairs);

    return res.value;
}

double newton_2d(std::vector<double> &data, double x, int nx)
{
    std::vector<Point> pairs;

    for (size_t i = 0; i < data.size(); ++i)
        pairs.push_back({i, data[i], 0, 0});

    Interp res = Interp(InterpError_t::ERR_OK, 0);

    res = interpolate(pairs, x, nx, 0);
    return res.value;
}

double newton_3d(matrix &data, double x, double y, int nx, int ny)
{
    std::vector<Point> pairs;
    for (size_t i = 0; i < data.size(); ++i)
    {
        double interValue = newton_2d(data[i], x, nx);
        pairs.push_back({i, interValue, 0, 0});
    }
    
    Interp res = Interp(InterpError_t::ERR_OK, 0);

    res = interpolate(pairs, y, ny, 0);

    return res.value;
}

double newton_4d(matrix3d &data, Point3d &point, int nx, int ny, int nz)
{
    std::vector<Point> pairs;
    for (size_t i = 0; i < data.size(); ++i)
    {
        double interValue = newton_3d(data[i], point.x, point.y, nx, ny);
        pairs.push_back({i, interValue, 0, 0});
    }
    
    Interp res = Interp(InterpError_t::ERR_OK, 0);

    res = interpolate(pairs, point.z, nz, 0);

    return res.value;
}

// double interpolateByN(matrix3d &data, Point3d &point, int nx, int ny, int nz)
// {
//     const int X_MAX = 4;
//     const int Y_MAX = 4;
//     const int Z_MAX = 4;

//     std::vector<int> xNodes = getClosestIndexes(point.x, nx + 1, X_MAX);
//     std::vector<int> yNodes = getClosestIndexes(point.y, ny + 1, Y_MAX);
//     std::vector<int> zNodes = getClosestIndexes(point.z, nz + 1, Z_MAX);

//     std::cout << "DEBUG\n";

//     std::cout << xNodes.size();
//     std::cout << "DEBUG\n";
//     for (size_t i = 0; i < xNodes.size(); ++i)
//         std::cout << xNodes[i] << ' ';
//     std::cout << "\n";
//     for (size_t i = 0; i < yNodes.size(); ++i)
//         std::cout << yNodes[i] << ' ';
//     std::cout << "\n";
//     for (size_t i = 0; i < zNodes.size(); ++i)
//         std::cout << zNodes[i] << ' ';
//     std::cout << "\n";


//     std::vector<std::vector<double>>
//         tempYZ(yNodes.size(), std::vector<double>(xNodes.size()));

//     Interp YZ = Interp(InterpError_t::ERR_OK, 0);
//     Interp X = Interp(InterpError_t::ERR_OK, 0);
//     Interp Y = Interp(InterpError_t::ERR_OK, 0);

//     for (size_t zi = 0; zi < zNodes.size(); ++zi) 
//      {
//         int zIdx = zNodes[zi];
//         for (size_t yj = 0; yj < yNodes.size(); ++yj)
//         {
//             int yIdx = yNodes[yj];
            
//             std::vector<Point> xPoints;
//             for (int xk : xNodes) {
//                 xPoints.push_back({
//                     static_cast<double>(xk), 
//                     data[zIdx][yIdx][xk]  // [z][y][x]
//                 });
//             }

//             Interp XRes = interpolate(xPoints, point.x, nx, 0);
//             if (XRes.error == InterpError_t::ERR_OK)
//             {
//                 tempYX[yj][zi] = XRes.value;
//             }
//         }
//     }

//     // Интерполяция по Y
//     std::vector<double> tempX(xNodes.size());
//     for (size_t xi = 0; xi < xNodes.size(); ++xi)
//     {
//         std::vector<Point> yPoints;
//         for (size_t yi = 0; yi < yNodes.size(); ++yi)
//         {
//             yPoints.push_back({
//                 static_cast<double>(yNodes[yi]), 
//                 tempYZ[yi][xi]
//             });
//         }

//         Interp YRes = interpolate(yPoints, point.y, ny, 0);
//         if (YRes.error == InterpError_t::ERR_OK)
//         {
//             tempX[xi] = YRes.value;
//         } 
//     }

//     // Интерполяция по X
//     std::vector<Point> xPoints;
//     for (size_t xi = 0; xi < xNodes.size(); ++xi) 
//     {
//         xPoints.push_back({
//             static_cast<double>(xNodes[xi]), 
//             tempX[xi]
//         });
//     }

//     Interp XRes = interpolate(xPoints, point.x, nx, 0);

//     return XRes.value;
// }
