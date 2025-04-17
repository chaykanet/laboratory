#include "figure.h"

#include "actions.h"
#include "figure.h"

#define PIXEL_X 1000
#define PIXEL_Y 800

Figure::Figure(QList<QPointF> points, Edges_t edges) {
    this->points = points;
    this->edges = edges;
}

void Figure::setPoints(const QList<QPointF> &points) {
    this->points = points;
}

void Figure::setEdges(const Edges_t &edges) {
    this->edges = edges;
}

QList<QPointF> Figure::getPoints() const {
    return points;
}

Edges_t Figure::getEdges() const{
    return edges;
}

void drawFish(QPainter &p, const Fish &fish)
{
    drawEllipse(p, fish.eye);
    drawEllipse(p, fish.body);
    drawFigure(p, fish.head);
    drawFigure(p, fish.fins);
    drawFigure(p, fish.tail);
    drawFigure(p, fish.arc);
}

void drawFigure(QPainter &p, const Figure &figure)
{
    QList<QPointF> points = figure.getPoints();
    Edges_t edges = figure.getEdges();

    for (const auto &edge : edges)
    {
        int startIndex = edge.first;
        int endIndex = edge.second;

        if (startIndex >= 0 && startIndex < points.size() && endIndex >= 0 && endIndex < points.size())
        {

            QPointF pointA = points[startIndex];
            QPointF pointB = points[endIndex];

            Vect toCenter = Vect(PIXEL_X / 2, PIXEL_Y / 2);
            movePoint(pointA, toCenter);
            movePoint(pointB, toCenter);

            p.drawLine(pointA, pointB);
        }
    }
}

void drawEllipse(QPainter& painter, const Ellipse& ellipse)
{
    QList<QPointF> points = ellipse.points;

    for (size_t i = 0; i < (size_t) ellipse.points.size() - 1; ++i)
    {
        QPointF pointA = points[i];
        QPointF pointB = points[i + 1];

        Vect toCenter = Vect(PIXEL_X / 2, PIXEL_Y / 2);
        movePoint(pointA, toCenter);
        movePoint(pointB, toCenter);

        painter.drawLine(pointA, pointB);
    }
}

void makeArc(QList<QPointF> &points, Edges_t &edges)
{
    size_t numPoints = 360;
    qreal yStart = -60;
    qreal yEnd = 60;
    for (size_t i = 0; i < numPoints; ++i)
    {
        qreal y = yStart + i * (yEnd - yStart) / numPoints;
        qreal x = std::sqrt(-(y * y) + 600) - 90;

        points.append(QPointF(x, y));
    }

    for (size_t i = 0; i < numPoints - 1; ++i)
        edges.append(std::make_pair(i, i + 1));
}
