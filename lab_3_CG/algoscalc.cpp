#include "algoscalc.h"

#include <cmath>

void AlgosCalc::DDA(int x1, int y1, int x2, int y2) const
{
    if (x1 == x2 && y1 == y2)
    {
        return;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;
    int len = std::max(abs(dx), abs(dy));

    double stepX = static_cast<double>(dx) / len;
    double stepY = static_cast<double>(dy) / len;

    double x = x1;
    double y = y1;

    for (int i = 0; i <= len; ++i)
    {
        x += stepX;
        y += stepY;
    }
}

void AlgosCalc::Bresenham(int x1, int y1, int x2, int y2) const
{
    int x = x1;
    int y = y1;

    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;
    int err2 = 0;

    while (true)
    {
        if (x2 == x && y2 == y)
            break;

        err2 = err << 1;

        if (err2 > -dy)
        {
            err -= dy;
            x += sx;
        }

        if (err2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void AlgosCalc::Wu(int x1, int y1, int x2, int y2) const
{
    bool steep = std::abs(y2 - y1) > std::abs(x2 - x1);

    if (steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    double dx = x2 - x1;
    double dy = y2 - y1;
    double gradient = (dx == 0) ? 1 : dy / dx;

    double y = y1;

    for (int x = x1; x <= x2; x++)
    {
        double y_floor = std::floor(y);
        double rf = y - y_floor;

        if (steep)
            rf = y - y_floor;
        else
            rf = y - y_floor;

        y += gradient;
    }
}

void AlgosCalc::BresenhamUnStep(int x1, int y1, int x2, int y2) const
{
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    double eps = 1e-7;

    if (std::fabs(dx) < eps && std::fabs(dy) < eps)
    {
        return;
    }

    int sx = (dx > 0) ? 1 : -1;
    int sy = (dy > 0) ? 1 : -1;
    
    dx = abs(dx);
    dy = abs(dy);
    
    bool swap = false;

    if (dx < dy)
    {
        std::swap(dx, dy);
        swap = true;
    }

    double err = 0.5; 
    double m = static_cast<double>(dy) / dx; 
    double w = 1.0 - m;
    
    for (int i = 0; i <= dx; i++)
    {
        if (err < w)
        {
            if (!swap)
                x += sx;
            else
                y += sy;
            err += m;
        }
        else
        {
            x += sx;
            y += sy;
            err -= w;
        }
    }
}

void AlgosCalc::BresenhamDouble(double x1, double y1, double x2, double y2) const
{
    double dx = fabs(x2 - x1);
    double dy = fabs(y2 - y1);
    double sx = (x1 < x2) ? 1.0 : -1.0;
    double sy = (y1 < y2) ? 1.0 : -1.0;
    
    double err = dx - dy;
    double eps = 1e-7;
    
    while (true)
    {
        if (fabs(x1 - x2) < eps && fabs(y1 - y2) < eps)
            break;
    
        double e2 = 2 * err;
    
        if (e2 > -dy)
        { 
            err -= dy;
            x1 += sx;
        }
    
        if (e2 < dx)
        { 
            err += dx;
            y1 += sy;
        }
    }
}

size_t AlgosCalc::calcStepWu(double x1, double y1, double x2, double y2) const
{
    bool steep = std::abs(y2 - y1) > std::abs(x2 - x1);

    if (steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    double dx = x2 - x1;
    double dy = y2 - y1;
    double gradient = (dx == 0) ? 1 : dy / dx;

    double y = y1;
    double prev_y = std::floor(y);
    int prev_x = x1;
    size_t clc = 0;

    for (int x = x1; x <= x2; x++)
    {
        double y_floor = std::floor(y);
        double rf = y - y_floor;

        if (y_floor != prev_y && x != prev_x)
        {
            prev_y = y_floor;
            prev_x = x;
            clc++;
        }
       
        if (steep)
            rf = y - y_floor;
        else
            rf = y - y_floor;

        y += gradient;
    }

    return clc;
}

size_t AlgosCalc::calcStepDDA(int x1, int y1, int x2, int y2) const
{
    if (x1 == x2 && y1 == y2)
    {
        return 0;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;
    int len = std::max(abs(dx), abs(dy));

    double stepX = static_cast<double>(dx) / len;
    double stepY = static_cast<double>(dy) / len;

    double x = x1 + 0.5;
    double y = y1 + 0.5;

    size_t clc = 0;

    double prev_y = std::round(y);
    double prev_x = std::round(x);
    
    for (int i = 0; i <= len; ++i)
    {
        if (std::round(y) != prev_y && std::round(x) != prev_x)
        {
            prev_y = std::round(y);
            prev_x = std::round(x); 
            clc++;
        }
        
        x += stepX;
        y += stepY;
    }

    return clc;
}

size_t AlgosCalc::calcStepBresenham(int x1, int y1, int x2, int y2) const
{
    int x = x1;
    int y = y1;

    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;
    int err2 = 0;

    size_t clc = 0;
    int prev_x = 0, prev_y = 0;
    while (true)
    {
        if (y != prev_y && x != prev_x)
        {
            prev_y = y;
            prev_x = x;
            clc++;
        }

        if (x2 == x && y2 == y)
            break;

        err2 = err << 1;

        if (err2 > -dy)
        {
            err -= dy;
            x += sx;
        }
            
        if (err2 < dx)
        {
            err += dx;
            y += sy;
        }
    }

    return clc;
}

size_t AlgosCalc::calcStepBresenhamDouble(double x1, double y1, double x2, double y2) const
{
    double dx = fabs(x2 - x1);
    double dy = fabs(y2 - y1);
    double sx = (x1 < x2) ? 1.0 : -1.0;
    double sy = (y1 < y2) ? 1.0 : -1.0;

    double err = dx - dy;
    double eps = 1e-7;

    double prev_y = std::round(y1);
    double prev_x = std::round(x1);
    size_t clc = 0;
    
    while (true)
    {
        if (std::round(y1) != prev_y && std::round(x1) != prev_x)
        {
            prev_y = std::round(y1);
            prev_x = std::round(x1);
            clc++;
        }
        
        if (fabs(x1 - x2) < eps && fabs(y1 - y2) < eps)
            break;
    
        double e2 = 2 * err;
    
        if (e2 > -dy)
        { 
            err -= dy;
            x1 += sx;
        }
    
        if (e2 < dx)
        { 
            err += dx;
            y1 += sy;
        }
    }

    return clc;
}
size_t AlgosCalc::calcStepBresenhamUnStep(int x1, int y1, int x2, int y2) const
{
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    double eps = 1e-7;

    if (std::fabs(dx) < eps && std::fabs(dy) < eps)
    {
        return 0;
    }

    int sx = (dx > 0) ? 1 : -1;
    int sy = (dy > 0) ? 1 : -1;
    
    dx = abs(dx);
    dy = abs(dy);
    
    bool swap = false;

    if (dx < dy)
    {
        std::swap(dx, dy);
        swap = true;
    }

    double err = 0.5; 
    double m = static_cast<double>(dy) / dx; 
    double w = 1.0 - m;
    size_t clc =0;
    for (int i = 0; i <= dx; i++)
    {
        if (err < w)
        {
            if (!swap)
                x += sx;
            else
                y += sy;
            err += m;
        }
        else
        {
            x += sx;
            y += sy;
            clc++;
            err -= w;
        }
    }
    
    return clc;
}
