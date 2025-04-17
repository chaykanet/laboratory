#ifndef ALGORITHMSRENDER_H
#define ALGORITHMSRENDER_H

#include "algorithms.h"
#include <QPainter>

inline void drawPoint(QPainter &p, double x, double y);

class AlgorithmsRender
{
public:
    AlgorithmsRender();

    void MidpointСircle(QPainter &p, double xCenter, double yCenter, double radius);

    void CanonicalСircle(QPainter &p, double xCenter, double yCenter, double radius);

    void BresenhamСircle(QPainter &p, double xCenter, double yCenter, double radius);
    
    void ParametricСircle(QPainter &p, double xCenter, double yCenter, double radius);

    void MidpointСircle(QPainter &p, double xCenter, double yCenter,double a, double b);
    
    void CanonicalEllipse(QPainter &p, double xCenter, double yCenter, double a, double b);

    void ParametricEllipse(QPainter &p, double xCenter, double yCenter, double a, double b);

    void BresenhamEllipse(QPainter &p, double xCenter, double yCenter, double a, double b);

    void MidpointEllipse(QPainter &p, double xCenter, double yCenter, double a, double b);
    
    void Circle(alg algos, QPainter &p, double xCenter, double yCenter, double radius);

    void Ellipse(alg algos, QPainter &p, double xCenter, double yCenter, double a, double b);


    void CircleSpector(alg algos, QPainter &p, double xCenter, double yCenter, double radius, int step, size_t n);

    void EllipseSpector(alg algos, QPainter &p, double xCenter, double yCenter, double a, double b, int step, size_t n);
};

#endif // ALGORITHMSRENDER_H
