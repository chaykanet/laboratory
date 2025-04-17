#ifndef ACTIONS_H
#define ACTIONS_H

#include "figure.h"
#include "error.h"

class Rotate {
public:
    double angle;
    Rotate(double _angle)
    {
        angle = _angle;
    }

    ~Rotate() {};
};

class Scale {
public:
    double kX, kY;

    Scale(double kx, double ky)
    {
        kX = kx;
        kY = ky;
    }

    ~Scale() {};
};

class Vect {
public:
    double dX, dY;

    Vect(double dx, double dy)
    {
        dX = dx;
        dY = dy;
    }

    ~Vect() {};
};

void movePoint(QPointF &point, const Vect &vector);

myerror_t moveFish(Fish &fish, const Vect &vector);

myerror_t scaleFish(Fish &fish, const Scale &scale);

myerror_t rotateFish(Fish &fish, const Rotate &rotate);

void moveEllipse(Ellipse &ellipse, const Vect &vector);

void rotateEllipse(Ellipse &ellipse, const Rotate &rotate);

void scaleEllipse(Ellipse &ellipse, const Scale &scale);

myerror_t moveFigure(Figure &figure, const Vect &vector);

myerror_t scaleFigure(Figure &figure, const Scale &scale);

myerror_t rotateFigure(Figure &figure, const Rotate &rotate);

#endif // ACTIONS_H
