#ifndef FIGURE_H
#define FIGURE_H

#include <Qt>
#include <QFileDialog>
#include <QPainter>

typedef QList<std::pair<int, int>>  Edges_t;

class Figure
{
private:
    QList<QPointF> points;
    QList<std::pair<int, int>> edges;
public:
    QPointF center;

    Figure(QList<QPointF> points, Edges_t edges);

    Figure() {};

    void setPoints(const QList<QPointF> &points);

    void setEdges(const Edges_t &edges);

    QPointF getCenter() const;

    Edges_t getEdges() const;

    QList<QPointF> getPoints() const;

    ~Figure() {};
};


class Ellipse
{
public:
    QPointF center = QPointF(0, 0);

    size_t numPoints = 100;

    QList<QPointF> points;

    qreal angle = 0;

    qreal a;
    qreal b;

    Ellipse(QPointF &_center, qreal _angle, qreal _a, qreal _b)
    {
        center = _center;
        angle = _angle;
        a = _a;
        b = _b;

        for (size_t i = 0; i < numPoints; ++i)
        {
            qreal theta = 2 * M_PI * i / (numPoints - 1);

            // Параметрическое уравнение эллипса
            qreal x = a * cos(theta);
            qreal y = b * sin(theta);

            // Смещение к центру
            points.append(QPointF(center.x() + x, center.y() + y));
        }
    };

    Ellipse() {};

    ~Ellipse() {};
};

class Fish
{
public:
    Figure head;
    Ellipse body;
    Ellipse eye;
    Figure tail;
    Figure fins;
    Figure arc;



    Fish() {};
    Fish(const Figure &_head, const Figure &_arc, const Ellipse &_body, const Ellipse &_eye, const Figure &_tail, const Figure &_fins)
    {
        head = _head;
        arc = _arc;
        body = _body;
        tail = _tail;
        fins = _fins;
        eye = _eye;
    }

    ~Fish() {};
};

void drawFish(QPainter &p, const Fish &fish);

void drawFigure(QPainter &p, const Figure &figure);

void drawEllipse(QPainter& painter, const Ellipse& ellipse);

void makeArc(QList<QPointF> &points, Edges_t &edges);

#endif // FIGURE_H
