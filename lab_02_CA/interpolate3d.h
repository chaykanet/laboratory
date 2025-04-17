#ifndef INTERPOLATE3D_H
#define INTERPOLATE3D_H

#include <vector>

class Point3d
{
public:
    double x;
    double y;
    double z;
    Point3d(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    Point3d() {};
};

using matrix3d = std::vector<std::vector<std::vector<double>>>;

double interpolateByN(matrix3d &data, Point3d &point, int nx, int ny, int nz);

#endif // INTERPOLATE3D_H
