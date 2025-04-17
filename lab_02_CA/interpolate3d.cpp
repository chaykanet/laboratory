#include "spline.h"

#include <cmath>
#include "interp.h"
#include "algorithm"

#include "interpolate3d.h"

std::vector<int> getClosestIndexes(double value, int n, int maxIndex)
{
    int half = (n - 1) / 2;

    int valueIndex = std::round(value);
    int start = std::max(0, valueIndex - half);
    start = std::min(start, maxIndex - n + 1);

    std::vector<int> indexes;

    for (int i = 0; i < n; ++i)
        indexes.push_back(start + i);

    return indexes;
}


double interpolateByN(matrix3d &data, Point3d &point, int nx, int ny, int nz)
{
    const int X_MAX = 4;
    const int Y_MAX = 4;
    const int Z_MAX = 4;

    std::vector<int> xNodes = getClosestIndexes(point.x, nx, X_MAX);
    std::vector<int> yNodes = getClosestIndexes(point.y, ny, Y_MAX);
    std::vector<int> zNodes = getClosestIndexes(point.z, nz, Z_MAX);

    std::vector<std::vector<double>>
        tempYZ(yNodes.size(), std::vector<double>(xNodes.size()));

    Interp YZ = Interp(InterpError_t::ERR_OK, 0);
    Interp X = Interp(InterpError_t::ERR_OK, 0);
    Interp Y = Interp(InterpError_t::ERR_OK, 0);

    for (size_t xi = 0; xi < xNodes.size(); ++xi)
    {
        int xDx = xNodes[xi];

        for (size_t yi = 0; yi < yNodes.size(); ++yi)
        {
            int yDx = yNodes[yi];

            std::vector<Point> zPoints;

            for (int zk : zNodes)
                zPoints.push_back({(double) zk, data[zk][xDx][yDx], 0 , 0 });

            YZ = interpolate(zPoints, point.z, nz, 0);

            if (YZ.error == InterpError_t::ERR_OK)
                tempYZ[yi][xi] = YZ.value;
        }
    }

    std::vector<double> tempX(xNodes.size());
    for (size_t xi = 0; xi < xNodes.size(); ++xi)
    {
        std::vector<Point> yPoints;
        for (size_t yj = 0; yj < yNodes.size(); ++yj)
        {
            yPoints.push_back({
                static_cast<double>(yNodes[yj]), // Координата y (Point.x)
                tempYZ[yj][xi], 0, 0                // Значение (Point.y)
            });
        }

        // Интерполируем по Y
        X = interpolate(yPoints, point.y, ny, 0);
        if (YZ.error == InterpError_t::ERR_OK)
            tempX[xi] = X.value;
    }

    // Интерполяция по X
    std::vector<Point> xPoints;
    for (size_t xi = 0; xi < xNodes.size(); ++xi)
    {
        xPoints.push_back({
            static_cast<double>(xNodes[xi]), // Координата x (Point.x)
            tempX[xi], 0, 0                          // Значение (Point.y)
        });
    }

    Interp res = interpolate(xPoints, point.x, nx, 0);
    return res.value;
}
