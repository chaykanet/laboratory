#include "render.h"
#include "qapplication.h"

#include <qpainter.h>

#include <QPointF>

Render::Render()
{

}

Render::Render(QColor &fon, QColor &edgeClr, QColor &fillClr, bool delay)
{
    this->fon = fon;
    this->pen = edgeClr;
    this->brush = fillClr;
    this->delay = delay;
}

void Render::drawPixel(QImage &image, QColor &clr, int x, int y)
{
    image.setPixelColor(x, y, clr);
}

void Render::setPixelDelay(QGraphicsScene* scene, QImage &image)
{
    QPixmap pixmap = QPixmap::fromImage(image);
    
    scene->clear();
    scene->addPixmap(pixmap);
    scene->update();

    QCoreApplication::processEvents();
    QThread::msleep(1);   
}

void Render::setPixels(QGraphicsScene* scene, QImage &image)
{
    QPixmap pixmap = QPixmap::fromImage(image);
    
    scene->clear();
    scene->addPixmap(pixmap);
    scene->update();
}

void Render::renderPolygon(QGraphicsScene* scene, QImage &image, const listEdges& edges)
{
    drawEdges(scene, image, edges);

    parseEdges(scene, image, edges);
    
    auto start = std::chrono::steady_clock::now();
    fillWithFlag(scene, image, edges);
    auto end = std::chrono::steady_clock::now();
    
    timeRender = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    drawEdges(scene, image, edges);
}

void Render::drawEdges(QGraphicsScene* scene, QImage &image, const listEdges& edges)
{
    QPainter p (&image);

    for (auto &edge : edges)
    {
        p.drawLine(edge.A(), edge.B());
        rendering(alg::Alg_Bres, p, pen, edge.A().x(), edge.A().y(), edge.B().x(), edge.B().y());
    }

    setPixels(scene, image);
}

void Render::parseEdges(QGraphicsScene* scene, QImage &image, const listEdges &edges)
{
    QColor tempColorCheck = Qt::magenta;

    for (const auto &edge : edges)
    {
        QPointF p1 = edge.A();
        QPointF p2 = edge.B();

        if (p1.y() == p2.y()) continue;

        QPointF lower = p1;
        QPointF upper = p2;
        
        if (lower.y() > upper.y())
        {
            std::swap(lower, upper);
        }

        int yMin = lower.y();
        int yMax = upper.y();

        float dx = static_cast<float>(upper.x() - lower.x());
        float dy = static_cast<float>(upper.y() - lower.y());
        float k = dx / dy;

        for (int y = yMin; y < yMax; ++y)
        {
            float x = lower.x() + k * (y - lower.y());
            int xInt = static_cast<int>(x);
            
            int xCheck = xInt + 1;
            if (xCheck >= 0 && y >= 0)
            {
                if (image.pixelColor(xCheck, y) != tempColorCheck)
                {
                    drawPixel(image, tempColorCheck, xCheck, y);
                }
                else
                {
                    int xSet = xInt + 2;
                    if (xSet >= 0)
                    {
                        drawPixel(image, tempColorCheck, xSet, y);
                    }
                }
            }
        }
    }

    setPixels(scene, image);
}

void Render::fillWithFlag(QGraphicsScene* scene, QImage &image, const listEdges& edges)
{
    if (!scene) return;

    double xMin = std::numeric_limits<double>::max();
    double xMax = -xMin;
    double yMin = xMin, yMax = -xMin;
    
    for (auto &edge : edges)
    {
        QPointF A = edge.A();
        QPointF B = edge.B();
        xMin = std::min(xMin, std::min(A.x(), B.x()));
        xMax = std::max(xMax, std::max(A.x(), B.x()));
        yMin = std::min(yMin, std::min(A.y(), B.y()));
        yMax = std::max(yMax, std::max(A.y(), B.y()));
    }

    for (int y = yMax - 1; y >= yMin; --y)
    {
        bool flag = false;
        
        for (int x = xMin; x < xMax + 2; ++x)
        {
            QColor clr = image.pixelColor(x, y);
            
            if (clr == Qt::magenta)
            {
                flag = !flag;
            }

            if (flag)
            {
                drawPixel(image, brush, x, y);
                if (delay)
                setPixelDelay(scene, image);    
            }
            else
            {
                drawPixel(image, fon, x, y);
                if (delay)
                setPixelDelay(scene, image);                   
            }
        }
    }
    
    if (!delay)
    {
        setPixels(scene, image);
    }
}
