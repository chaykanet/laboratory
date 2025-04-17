#ifndef POINT_H
#define POINT_H

#include <vector>
#include <string>

class point
{
public:
    double x;
    double y;
    double z;
    double p;

    explicit point(double _x, double _y, double _z, double _p);
    explicit point() {};
};

class Points
{
public:
    size_t len;    

    Points(){};

    point center();
    
    std::vector<point> points;
    
    Points(std::string filename, int mode);

    void changeWeiht(size_t index, double _p);
    
    std::vector<point> readPoints(std::string filename, int mode);
};

#endif // POINT_H
