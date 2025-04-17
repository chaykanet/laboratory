#include "algorithmsRender.h"

#include <cmath>

void drawPoint(QPainter &p, double x, double y)
{
    p.drawPoint(x, y);
}

AlgorithmsRender::AlgorithmsRender(){};

void AlgorithmsRender::Circle(alg algos, QPainter &p, double xCenter, double yCenter, double radius)
{
    switch (algos)
    {
    case alg::Alg_CANON:
    {
        CanonicalСircle(p, xCenter, yCenter, radius);
        break;
    }
    case alg::Alg_PARAM:
    {
        ParametricСircle(p, xCenter, yCenter, radius);
        break;
    }    
    case alg::Alg_BRES:
    {    
        BresenhamСircle(p, xCenter, yCenter, radius);
        break;
    }
    case alg::Alg_MID:
    {
        MidpointСircle(p, xCenter, yCenter, radius);
        break;
    }    
    case alg::Alg_STD:
    {
        p.drawEllipse(QPointF(xCenter, yCenter), radius, radius);
    }
    }
}

void AlgorithmsRender::Ellipse(alg algos, QPainter &p, double xCenter, double yCenter, double a, double b)
{
    switch (algos)
    {
    case alg::Alg_CANON:
    {
        CanonicalEllipse(p, xCenter, yCenter, a, b);
        break;
    }
    case alg::Alg_PARAM:
    {
        ParametricEllipse(p, xCenter, yCenter, a, b);
        break;
    }    
    case alg::Alg_BRES:
    {    
        BresenhamEllipse(p, xCenter, yCenter, a, b);
        break;
    }
    case alg::Alg_MID:
    {
        MidpointEllipse(p, xCenter, yCenter, a, b);
        break;
    }
    case alg::Alg_STD:
    {
        p.drawEllipse(QPointF(xCenter, yCenter), a, b);
    }
    }
}

void AlgorithmsRender::CircleSpector(alg algos, QPainter &p, double xCenter, double yCenter, double radius, int step, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        double r = radius + i * step;

        Circle(algos, p, xCenter, yCenter, r);
    }
}

void AlgorithmsRender::EllipseSpector(alg algos, QPainter &p, double xCenter, double yCenter, double a, double b, int step, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        double _a = a + i * step;
        double _b = b + i * step;
        
        Ellipse(algos, p, xCenter, yCenter, _a, _b);
    }
}

void AlgorithmsRender::CanonicalСircle(QPainter &p, double xCenter, double yCenter, double radius)
{
    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
        drawPoint(p, xCenter + dy, yCenter + dx);
        drawPoint(p, xCenter - dy, yCenter + dx);
        drawPoint(p, xCenter + dy, yCenter - dx);
        drawPoint(p, xCenter - dy, yCenter - dx);
    };
    
    double maxX = radius * std::sqrt(0.5); // radius / sqrt(2)

    for (double x = 0; x <= maxX; x += 1.0)
    {
        double y1 = sqrt(radius * radius - x * x); 

        drawSymmetry(x, y1);
    }
}

void AlgorithmsRender::ParametricСircle(QPainter &p, double xCenter, double yCenter, double radius)
{
    double step = 1 / radius;

    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
        drawPoint(p, xCenter + dy, yCenter + dx);
        drawPoint(p, xCenter - dy, yCenter + dx);
        drawPoint(p, xCenter + dy, yCenter - dx);
        drawPoint(p, xCenter - dy, yCenter - dx);
    };

    double maxAngle = M_PI / 4;

    for (double angle = 0.0; angle < maxAngle; angle += step)
    {
        double x = radius * std::cos(angle);
        double y = radius * std::sin(angle);

        drawSymmetry(x, y);
    }
}

void AlgorithmsRender::MidpointСircle(QPainter &p, double xCenter, double yCenter, double radius)
{
    if (radius <= 0) return;

    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
        drawPoint(p, xCenter + dy, yCenter + dx);
        drawPoint(p, xCenter - dy, yCenter + dx);
        drawPoint(p, xCenter + dy, yCenter - dx);
        drawPoint(p, xCenter - dy, yCenter - dx);
    };

    int x = 0;
    int y = radius;
    int func = 5.0 / 4.0 - radius;
    
    drawSymmetry(x, y);

    while (x <= y)
    {
        ++x;
        if (func < 0)
        {
            func += 2 * x + 1;
        }
        else
        {
            --y;
            func += 2 * (x - y) + 1;
        }
        
        drawSymmetry(x, y);
    }
}

// Δi < 0
// δ <= 0 выбираем пиксел (xi + 1, yi) ==> Mh
// δ > 0 выбираем пиксел (xi + 1, yi — 1) ==> Md
// Δi > 0
// δ’ <= 0 выбираем пиксел (xi + 1, yi — 1) ==> Md
// δ’ > 0 выбираем пиксел (xi, yi — 1) ==> Mv
// Δi = 0 выбираем пиксел (xi + 1, yi — 1) ==> Md

// Для шага Mh Δi+1 = Δi + 2xi+1 + 1
// Аналогично координаты нового пиксела и значение Δi для шага Md к пикселу (xi + 1, yi — 1) таковы:
// xi+1 = xi + 1
// yi+1 = yi — 1
// Δi+1 = Δi + 2yi+1 + 1

// То же самое для шага Mv к (xi, yi — 1)
// xi+1 = xi
// yi+1 = yi — 1
// Δi+1 = Δi — 2yi+1 + 1

void AlgorithmsRender::BresenhamСircle(QPainter &p, double xCenter, double yCenter, double radius)
{
    int x = 0;
    int y = radius;
    int d = 2 * (1 - y);
    
    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
        drawPoint(p, xCenter + dy, yCenter + dx);
        drawPoint(p, xCenter - dy, yCenter + dx);
        drawPoint(p, xCenter + dy, yCenter - dx);
        drawPoint(p, xCenter - dy, yCenter - dx);
    };
    
    while (y >= x)
    {
        drawSymmetry(x, y);
        
        if (d < 0)
        {
            int delta = 2 * (d - y) + 1;

            if (delta > 0)
            {
                ++x;
                --y;
                d += 2 * y - 1; 
            }    
            else
            {
                ++x;
                d += 2 * x + 1;                
            }
        }
        else if (d > 0)
        {
            int delta = 2 * (d - x) - 1;
            
            if (delta > 0)
            {
                --y;
                d -= 2 * y + 1; 
            }
            else
            {
                ++x;
                --y;
                d += 2 * y - 1; 
            }
        }
        else
        {
            ++x;
            --y;
            d += 2 * y - 1; 
        }
    }
}

void AlgorithmsRender::CanonicalEllipse(QPainter &p, double xCenter, double yCenter, double a, double b)
{
    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy); 
        drawPoint(p, xCenter - dx, yCenter + dy); 
        drawPoint(p, xCenter - dx, yCenter - dy); 
        drawPoint(p, xCenter + dx, yCenter - dy); 
    };

    for (double x = 0; x <= a; x += 1.0)
    {
        double y = b * std::sqrt(1 - (x * x) / (a * a));
        drawSymmetry(x, y);
    }
        
    for (double y = 0; y <= b; y += 1.0)
    {
        double x = a * std::sqrt(1 - (y * y) / (b * b));
        drawSymmetry(x,y);
    }
}

void AlgorithmsRender::ParametricEllipse(QPainter &p, double xCenter, double yCenter, double a, double b)
{
    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
    };

    const double maxAngle = M_PI_2;
    const double step = 1.0 / std::max(a, b);
    
    for (double angle = 0; angle <= maxAngle; angle += step)
    {
        double dx = a * std::cos(angle);
        double dy = b * std::sin(angle);
        drawSymmetry(dx, dy);
    }
}


void AlgorithmsRender::BresenhamEllipse(QPainter &p, double xCenter, double yCenter, double a, double b)
{
    int x = 0;
    int y = b;
    int d = a * a - b * b * (2 * b + 1);
    
    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
    };
    
    while (y >= 0)
    {
        drawSymmetry(x, y);

        if (d < 0)
        {
            double delta = 2 * d + a * (2 * y + 2);

            ++x;
            
            if (delta < 0)
                d += b * b  * (2 * x + 1);
            else
            {
                --y;
                d += b * b * (2 * x + 1) + a * a * (1 - 2 * y);
            }
        }
        else if (d > 0)
        {
            double delta = 2 * d + b * b * (2 - 2 * x);
            --y;
            if (delta > 0)
            {
                d += a * a * (1 - 2 * y);        
            }
            else
            {
                ++x;
                d += b * b * (2 * x + 1) + a * a * (1 - 2 * y);
            }
        }
        else
        {
            --y;
            ++x;
            d += b * b * (2 * x + 1) + a * a * (1 - 2 * y);
        }
    }       
}


void AlgorithmsRender::MidpointEllipse(QPainter &p, double xCenter, double yCenter, double a, double b)
{
    double x = 0;
    double y = b;
    
    // Начальные значения для первого региона
    double d1 = b * b - a * a * b + 0.25 * a * a;
    double dx = 2 * b * b * x;
    double dy = 2 * a * a * y;

    auto drawSymmetry = [&](int dx, int dy)
    {
        drawPoint(p, xCenter + dx, yCenter + dy);
        drawPoint(p, xCenter - dx, yCenter + dy);
        drawPoint(p, xCenter + dx, yCenter - dy);
        drawPoint(p, xCenter - dx, yCenter - dy);
    };
    
    // Первый регион (наклон < -1)
    while(dx < dy)
    {
        drawSymmetry(x, y);
  
        if(d1 < 0)
        {
            ++x;
            dx += 2 * b * b;
            d1 += dx + b * b;
        }
        else
        {
            ++x;
            --y;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += dx - dy + b * b;
        }
    }
    
    // Начальные значения для второго региона
    double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    
    // Второй регион (наклон >= -1)
    while(y >= 0)
    {
        drawSymmetry(x, y);
        
        if(d2 > 0)
        {
            --y;
            dy -= 2 * a * a;
            d2 += a * a - dy;
        }
        else
        {
            ++x;
            --y;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += dx - dy + a * a;
        }
    }
}
