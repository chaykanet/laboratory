#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QColor>
#include <QPainter>
#include <QMainWindow>

enum class alg { Alg_DDA, Alg_Bres, Alg_BresD, Alg_BresUnStep, Alg_Wu };

class Algorithms
{
private:  
    void drawPointWithClr(QPainter &p, QColor &clr, double x, double y, double rf);
public:
    Algorithms() {};

    void rendering(alg algos, QPainter &p, QColor &clr, int x1, int y1, int x2, int y2);

    void renderingDDA(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2);

    void renderingBresenham(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2);

    void renderingWu(QPainter &p, QColor &clr,int x1, int y1, int x2, int y2);

    void renderingBresenhamUnStep(QPainter &p, QColor &clr, int x1, int y1, int x2, int y2);

    void renderingBresenhamDouble(QPainter &p, QColor &clr, double x1, double y1, double x2, double y2);
};

#endif // ALGORITHMS_H
