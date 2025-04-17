#include "point.h"

#include <fstream>

point::point(double _x, double _y, double _z, double _p)
{
    x = _x;
    y = _y;
    z = _z;
    p = _p;
}

Points::Points(std::string filename, int mode=0)
{
    points = readPoints(filename, mode);
    len = points.size();
}

std::vector<point> Points::readPoints(std::string filename, int mode)
{
    std::ifstream file(filename);
    
    double x, y, z, p;
    
    std::vector<point> _points;

    if (mode == 0)
    {
        while (file >> x >> y >> p)
            _points.push_back(point(x, y, 0, p));
    }
    else if (mode == 1)
    {
        while (file >> x >> y >> z >> p)
            _points.push_back(point(x, y, z, p));
    }

    return _points;
}

void Points::changeWeiht(size_t index, double _p)
{
    points[index].p = _p;
}

point Points::center()
{
    double x = 0;
    double y = 0;
    double weight = 0;
    
    for (auto point : points)
    {
        x += point.x * point.p;
        y += point.y * point.p;
        weight += point.p;
    }

    return point(x / weight, y / weight, 0, weight);
}
