#ifndef INPUT_H
#define INPUT_H

#include "error.h"
#include "figure.h"

myerror_t dowlandFigure(Figure &figure, const char *filename);

myerror_t dowlandEllipse(Ellipse &ellipse, const char *filename);

#endif // INPUT_H
