#include "actions.h"

void movePoint(QPointF &point, const Vect &vector)
{
    double x = point.x() + vector.dX;
    double y = point.y() + vector.dY;

    point = QPointF(x, y);
}

static myerror_t movePoints(QList<QPointF> &points, const Vect &vector)
{
    myerror_t rc = ERR_OK;

    if (points.size() == 0)
    {
        rc = ERR_EMPTY_FIGURE;
    }
    else
    {
        for (size_t i = 0; i < (size_t ) points.size(); ++i)
            movePoint(points[i], vector);
    }

    return rc;
}

static void scalePoint(QPointF &point, const QPointF &center, const Scale &scale)
{
    double x = (point.x() - center.x()) * scale.kX + center.x();
    double y = (point.y() - center.y()) * scale.kY + center.y();

    point = QPointF(x, y);
}

static myerror_t scalePoints(QList<QPointF> &points, const QPointF &center, const Scale &scale)
{
    myerror_t rc = ERR_OK;

    if (points.size() == 0)
    {
        rc = ERR_EMPTY_FIGURE;
    }
    else
    {
        if (!scale.kX || !scale.kY)
        {
            rc = ERR_DEGENERATE_FIGURE;
        }
        else
        {
            for (size_t i = 0; i < (size_t ) points.size(); ++i)
                scalePoint(points[i], center, scale);
        }
    }

    return rc;
}

static void rotatePoint(QPointF &point, const QPointF &center, const Rotate& rotate)
{
    qreal cosX = std::cos(rotate.angle);
    qreal sinX = std::sin(rotate.angle);

    double x = (point.x() - center.x()) * cosX - sinX * (point.y() - center.y());
    double y = (point.x() - center.x()) * sinX + cosX * (point.y() - center.y());

    x += center.x();
    y += center.y();

    point = QPointF(x, y);
}

static myerror_t rotatePoints(QList<QPointF> &points, const QPointF &center, const Rotate &rotate)
{
    myerror_t rc = ERR_OK;

    if (points.size() == 0)
    {
        rc = ERR_EMPTY_FIGURE;
    }
    else
    {
        for (size_t i = 0; i < (size_t ) points.size(); ++i)
            rotatePoint(points[i], center, rotate);
    }

    return rc;
}

myerror_t rotateFish(Fish &fish, const Rotate &rotate)
{
    myerror_t rc = ERR_OK;

    rc = rotateFigure(fish.head, rotate);

    if (rc == ERR_OK)
        rc = rotateFigure(fish.fins, rotate);

    if (rc == ERR_OK)
        rc = rotateFigure(fish.tail, rotate);

    if (rc == ERR_OK)
        rc = rotateFigure(fish.arc, rotate);

    if (rc == ERR_OK)
        rotateEllipse(fish.body, rotate);

    if (rc == ERR_OK)
        rotateEllipse(fish.eye, rotate);

    return rc;
}

myerror_t scaleFish(Fish &fish, const Scale &scale)
{
    myerror_t rc = ERR_OK;

    rc = scaleFigure(fish.head, scale);

    if (rc == ERR_OK)
        rc = scaleFigure(fish.fins, scale);

    if (rc == ERR_OK)
        rc = scaleFigure(fish.tail, scale);

    if (rc == ERR_OK)
        rc = scaleFigure(fish.arc, scale);

    if (rc == ERR_OK)
        scaleEllipse(fish.body, scale);

    if (rc == ERR_OK)
        scaleEllipse(fish.eye, scale);

    return rc;
}

myerror_t moveFish(Fish &fish, const Vect &vector)
{
    myerror_t rc = ERR_OK;

    rc = moveFigure(fish.head, vector);

    if (rc == ERR_OK)
        rc = moveFigure(fish.fins, vector);

    if (rc == ERR_OK)
        rc = moveFigure(fish.tail, vector);

    if (rc == ERR_OK)
        rc = moveFigure(fish.arc, vector);

    if (rc == ERR_OK)
        moveEllipse(fish.body, vector);

    if (rc == ERR_OK)
        moveEllipse(fish.eye, vector);

    return rc;
}

void moveEllipse(Ellipse &ellipse, const Vect &vector)
{
    movePoint(ellipse.center, vector);

    movePoints(ellipse.points, vector);
}

myerror_t moveFigure(Figure &figure, const Vect &vector)
{
    QPointF center = figure.center;

    QList<QPointF> points = figure.getPoints();

    movePoint(center, vector);

    myerror_t rc = movePoints(points, vector);

    if (rc == ERR_OK)
    {
        figure.center = center;
        figure.setPoints(points);
    }

    return rc;
}

myerror_t scaleFigure(Figure &figure, const Scale &scale)
{
    QList<QPointF> points = figure.getPoints();

    myerror_t rc = scalePoints(points, figure.center, scale);

    if (rc == ERR_OK)
        figure.setPoints(points);

    return rc;
}

myerror_t rotateFigure(Figure &figure, const Rotate &rotate)
{
    QList<QPointF> points = figure.getPoints();

    myerror_t rc = rotatePoints(points, figure.center, rotate);

    if (rc == ERR_OK)
        figure.setPoints(points);

    return rc;
}

void scaleEllipse(Ellipse &ellipse, const Scale &scale)
{
    ellipse.a *= scale.kX;
    ellipse.b *= scale.kY;

    ellipse.numPoints *= std::max(scale.kX, scale.kY);

    scalePoints(ellipse.points, ellipse.center, scale);
}

void rotateEllipse(Ellipse& ellipse, const Rotate &rotate)
{
    rotatePoints(ellipse.points, ellipse.center, rotate);
}

