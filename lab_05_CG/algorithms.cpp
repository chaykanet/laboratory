#include "algorithms.h"

void Algorithms::drawPointWithClr(QPainter &p, QColor &clr, double x, double y, double rf)
{
    p.setPen(clr);
    p.drawPoint(x, y);
}

void Algorithms::rendering(alg algos, QPainter &p, QColor &clr, int x1, int y1, int x2, int y2)
{
    switch (algos)
    {
    case alg::Alg_DDA:
        renderingDDA(p, clr, x1, y1, x2, y2);
        break;
    case alg::Alg_Bres:
        renderingBresenham(p, clr, x1, y1, x2, y2);
        break;
    case alg::Alg_BresD:
        renderingBresenhamDouble(p, clr, x1, y1, x2, y2);
        break;
    case alg::Alg_BresUnStep:
        renderingBresenhamUnStep(p, clr, x1, y1, x2, y2);
        break;
    case alg::Alg_Wu:
        renderingWu(p, clr, x1, y1, x2, y2);
        break;
    default:
        break;
    }
}

void Algorithms::renderingBresenham(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2)
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
        drawPointWithClr(p, clr, x, y, 255);

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

void Algorithms::renderingBresenhamDouble(QPainter &p, QColor &clr, double x1, double y1, double x2, double y2)
{
    double dx = fabs(x2 - x1);
    double dy = fabs(y2 - y1);
    double sx = (x1 < x2) ? 1.0 : -1.0;
    double sy = (y1 < y2) ? 1.0 : -1.0;
    
    double err = dx - dy;
    double eps = 1e-7;
    
    while (true)
    {
        drawPointWithClr(p, clr, x1, y1, 255.0);
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

void Algorithms::renderingDDA(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2) 
{
    if (x1 == x2 && y1 == y2)
    {
        drawPointWithClr(p, clr, x1, y1, 255);
        return;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;
    int len = std::max(abs(dx), abs(dy));

    double stepX = static_cast<double>(dx) / len;
    double stepY = static_cast<double>(dy) / len;

    double x = x1 + 0.5;
    double y = y1 + 0.5;

    for (int i = 0; i <= len; ++i)
    {
        drawPointWithClr(p, clr, x, y, 255);
        x += stepX;
        y += stepY;
    }
}

void Algorithms::renderingBresenhamUnStep(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2)
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
    drawPointWithClr(p, clr, x, y, m * 255.0);
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
        drawPointWithClr(p, clr, x, y, err * 255.0);
    }
}

void Algorithms::renderingWu(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2) 
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
        {
            drawPointWithClr(p, clr, y_floor, x, (1 - rf) * 255.0);
            drawPointWithClr(p, clr, y_floor + 1, x, rf * 255.0);
        }
        else
        {
            drawPointWithClr(p, clr, x, y_floor, (1 - rf) * 255.0);
            drawPointWithClr(p, clr, x, y_floor + 1, rf * 255.0);
        }

        y += gradient;
    }
}
