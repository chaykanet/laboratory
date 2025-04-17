#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "algoscalc.h"

#include "colors.h"
#include <QPainter>
#include <QMainWindow>

enum class alg { Alg_DDA, Alg_Bres, Alg_BresD, Alg_BresUnStep, Alg_Wu };

class Algorithms: public AlgosCalc
{
private:  
    void drawPointWithClr(QPainter &p, Colors &clr, double x, double y, double rf);
public:
    Algorithms() {};

    void rendering(alg algos, QPainter &p, Colors &clr, int x1, int y1, int x2, int y2);

    void renderingDDA(QPainter &p, Colors &clr, int x1, int y1, int x2, int y2);

    void renderingBresenham(QPainter &p, Colors &clr, int x1, int y1, int x2, int y2);

    void renderingWu(QPainter &p, Colors &clr,int x1, int y1, int x2, int y2);

    void renderingBresenhamUnStep(QPainter &p, Colors &clr, int x1, int y1, int x2, int y2);

    void renderingBresenhamDouble(QPainter &p, Colors &clr, double x1, double y1, double x2, double y2);
};

#endif // ALGORITHMS_H
