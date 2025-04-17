#ifndef FUNC_TRIANGLE_H
#define FUNC_TRIANGLE_H

#include <Qt>
#include <QFileDialog>
#include <QPainter>
#include <QVector3D>
#include <QMessageBox>
#include <QTableView>
#include <QTableWidget>

#include <math.h>

class Triangle
{
public:
    QPointF A;
    QPointF B;
    QPointF C;

    qreal Square = 0.0;

    qreal AB = 0.0;
    qreal AC = 0.0;
    qreal BC = 0.0;
    qreal angel = 0.0;

    std::pair<QPointF, QPointF> height = { QPointF(0, 0), QPointF(0, 0)};
    std::pair<QPointF, QPointF> median = { QPointF(0, 0), QPointF(0, 0)};

    Triangle(QPointF a, QPointF b, QPointF c);
};

bool checkPointsFromTable(QTableWidget* table);

Triangle findTriangleMin(QList<Triangle>& triangles);

QList<QPointF> getPointsFromTable(QTableWidget* table);

QList<Triangle> formTriangles(const QList<QPointF>& points);

#endif
