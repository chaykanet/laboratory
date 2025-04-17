#ifndef RENDERING_H
#define RENDERING_H

#include <QMainWindow>

#include "colors.h"

#include "algorithms.h"

using timesList = std::vector<double>;

using pointsList = std::vector<std::pair<size_t, double>>;

using graphList = std::vector<pointsList>; 

class Rendering : public Algorithms
{
private:
    QImage image;
    QPainter p;
    Colors clr;
    Colors fon;

public:
    Rendering() {};

    graphList calcStepAlgos();

    QImage getImage() {return image;};

    timesList calcTimesForN(size_t n);
        
    Rendering(QImage& _image, int _clr, int _fon);
    
    void drawBrunch(alg algos, QPainter &p, double angle, double lenLine);

    void rendering(alg algos,QPainter &p, int x1, int y1, int x2, int y2);

    void renderingDDA(QPainter &p, int x1, int y1, int x2, int y2);

    void renderingBresenham(QPainter &p, int x1, int y1, int x2, int y2);

    void renderingWu(QPainter &p, int x1, int y1, int x2, int y2);

    void renderingBresenhamUnStep(QPainter &p, int x1, int y1, int x2, int y2);

    void renderingBresenhamDouble(QPainter &p, double x1, double y1, double x2, double y2);

    ~Rendering() {};
};

#endif // RENDERING_H
