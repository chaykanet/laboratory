#ifndef RENDER_H
#define RENDER_H

#include "algorithms.h"

#include <QThread>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QGraphicsPathItem>

#include "edge.h"

#include <chrono>
#include <QColor>

class Render : public Algorithms
{
    bool delay;
    
    QColor pen;
    QColor fon;
    QColor brush;
public:
    explicit Render();

    explicit Render(QColor &fon, QColor &edgeClr, QColor &fillClr, bool delay);
    
    double timeRender;

    void drawPixel(QImage &image, QColor &clr, int x, int y);

    void setPixelDelay(QGraphicsScene* scene, QImage &image);

    void setPixels(QGraphicsScene* scene, QImage &image);

    void drawEdges(QGraphicsScene* scene, QImage &image, const listEdges& edges);

    void fillWithFlag(QGraphicsScene* scene, QImage &image, const listEdges& edges);

    void renderPolygon(QGraphicsScene* scene, QImage &image, const listEdges& edges);

    void parseEdges(QGraphicsScene* scene, QImage &image, const  listEdges &edges);
};

#endif // RENDER_H
