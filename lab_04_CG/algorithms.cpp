#include "algorithms.h"


#include <cmath>
Algorithms::Algorithms(){}

void Algorithms::CanonicalСircle(double xCenter, double yCenter, double radius)
{
    double maxX = radius * std::sqrt(2);

    for (double x = 0; x <= maxX; x += 1.0)
    {
        double y1 = sqrt(radius * radius - x * x); 
    }
}

void Algorithms::ParametricСircle(double xCenter, double yCenter, double radius)
{
    double step = 1 / radius;
    double maxAngle = M_PI / 4;

    for (double angle = 0.0; angle < maxAngle; angle += step)
    {
        double x = radius * std::cos(angle);
        double y = radius * std::sin(angle);
    }
}

void Algorithms::MidpointСircle(double xCenter, double yCenter, double radius)
{
    if (radius <= 0) return;

    int x = 0;
    int y = radius;
    int func = 5.0 / 4.0 - radius;

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
    }
}

void Algorithms::BresenhamСircle(double xCenter, double yCenter, double radius)
{
    int y = radius;
    int d = 2 * (1 - y);
  
    for (int x = 0; x <= radius; ++x)
    {    
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


void Algorithms::CanonicalEllipse(double xCenter, double yCenter, double a, double b)
{
    for (double x = 0; x <= a; x += 1.0)
    {
        double y = b * std::sqrt(1 - (x * x) / (a * a));
    }

    for (double y = 0; y <= b; y += 1.0)
    {
        double x = a * std::sqrt(1 - (y * y) / (b * b));
    }
}

void Algorithms::ParametricEllipse(double xCenter, double yCenter, double a, double b)
{
    const double maxAngle = M_PI_2;
    const double step = 1.0 / std::max(a, b);
    
    for (double angle = 0; angle <= maxAngle; angle += step)
    {
        double dx = a * std::cos(angle);
        double dy = b * std::sin(angle);
    }
}


void Algorithms::BresenhamEllipse(double xCenter, double yCenter, double a, double b)
{
    int x = 0;
    int y = b;
    int d = a * a - b * b * (2 * b + 1);

    while (y >= 0)
    {
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

void Algorithms::MidpointEllipse(double xCenter, double yCenter, double a, double b)
{
    double x = 0;
    double y = b;
    
    // Начальные значения для первого региона
    double d1 = b * b - a * a * b + 0.25 * a * a;
    double dx = 2 * b * b * x;
    double dy = 2 * a * a * y;

    // Первый регион (наклон < -1)
    while(dx < dy)
    {
        if(d1 < 0)
        {
            --x;
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
