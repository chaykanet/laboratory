#ifndef CHART_H
#define CHART_H

#include <QApplication>
#include <QtCharts>

#include "diffequal.h"
#include "squareapprox.h"

class chart : public squareApprox, diffequal
{
private:
    Points _points1D;
    Points _points2D;
    int _degree, _mode;
public:
    explicit chart(Points &points1D, Points &points2D, int degree, int mode);

    void setP();

    void eqFor2M(QLineSeries *line);

    void eqFor3M(QLineSeries *line);
    
    void funcFor1D(QLineSeries *line);

    void funcFor2D();

    void plotPolynomial(int argc, char *argv[]);

    void plotDiffEqual(int argc, char *argv[]);
};

#endif // CHART_H
