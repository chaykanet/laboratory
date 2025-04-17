#include "func_triangle.h"

#include <Qt>
#include <QFileDialog>
#include <QPainter>
#include <QVector3D>
#include <QMessageBox>
#include <QTableView>
#include <QTableWidget>
#include "mainwindow.h"

#include <QPointF>
#include <utility>
#include <limits>
#include <cmath>

static std::pair<double, double> lineEquation(const QPointF& p1, const QPointF& p2) {
    if (p1.x() == p2.x()) {
        // Вертикальная прямая
        return {std::numeric_limits<double>::infinity(), p1.x()};
    }
    double slope = (p2.y() - p1.y()) / (p2.x() - p1.x());
    double intercept = p1.y() - slope * p1.x();
    return {slope, intercept};
}

static std::pair<double, double> perpendicularLine(const std::pair<double, double>& line, const QPointF& point) {
    double slope = line.first;
    if (std::isinf(slope)) {
        // Если исходная прямая вертикальна, перпендикуляр горизонтален
        return {0, point.y()};
    }
    if (slope == 0) {
        // Если исходная прямая горизонтальна, перпендикуляр вертикален
        return {std::numeric_limits<double>::infinity(), point.x()};
    }
    double perpendicularSlope = -1 / slope;
    double intercept = point.y() - perpendicularSlope * point.x();
    return {perpendicularSlope, intercept};
}

static QPointF intersectionPoint(const std::pair<double, double>& line1, const std::pair<double, double>& line2) {
    double slope1 = line1.first;
    double intercept1 = line1.second;
    double slope2 = line2.first;
    double intercept2 = line2.second;

    if (std::isinf(slope1)) {
        // Первая прямая вертикальна
        double x = intercept1;
        double y = slope2 * x + intercept2;
        return QPointF(x, y);
    }

    if (std::isinf(slope2)) {
        // Вторая прямая вертикальна
        double x = intercept2;
        double y = slope1 * x + intercept1;
        return QPointF(x, y);
    }

    // Находим точку пересечения
    double x = (intercept2 - intercept1) / (slope1 - slope2);
    double y = slope1 * x + intercept1;
    return QPointF(x, y);
}

// Функция для нахождения основания высоты
static QPointF findFootOfAltitude(const QPointF& p1, const QPointF& p2, const QPointF& p3) {
    auto sideP2P3 = lineEquation(p2, p3);
    auto altitudeP1 = perpendicularLine(sideP2P3, p1);
    return intersectionPoint(sideP2P3, altitudeP1);
}

Triangle::Triangle(QPointF a, QPointF b, QPointF c) {
    A = a;
    B = b;
    C = c;
    AB = std::sqrt(std::pow((A.x() - B.x()), 2) + std::pow((A.y() - B.y()), 2));
    AC = std::sqrt(std::pow((A.x() - C.x()), 2) + std::pow((A.y() - C.y()), 2));
    BC = std::sqrt(std::pow((B.x() - C.x()), 2) + std::pow((B.y() - C.y()), 2));

    Square = 0.5 * std::abs(
                     A.x() * (B.y() - C.y()) +
                     B.x() * (C.y() - A.y()) +
                     C.x() * (A.y() - B.y()));
    // qreal P = AB + AC + BC;
    // Square = std::sqrt(P / 2 * (P / 2 - AB) * (P / 2 - AC) * (P / 2 - BC));

    if (AB != 0 && AC != 0 && BC != 0)
    {

    double ma, mb, mc;
    double ha, hb, hc;

    ma = 0.5 * sqrt(2 * AB * AB + 2 * AC * AC - BC * BC);
    mb = 0.5 * sqrt(2 * AB * AB + 2 * BC * BC - AC * AC);
    mc = 0.5 * sqrt(2 * AC * AC + 2 * BC * BC - AB * AB);

    ha = 2 * Square / BC;
    hb = 2 * Square / AC;
    hc = 2 * Square / AB;

    double cosA = ha / ma;
    double cosB = hb / mb;
    double cosC = hc / mc;

    if (cosA >= cosB && cosA >= cosC)
    {
        angel = acos(cosA);
        QPointF M = QPointF((B.x() + C.x()) / 2, (B.y() + C.y()) / 2);
        QPointF H = findFootOfAltitude(A, B, C);
        height.first = A;
        height.second = H;
        median.first = A;
        median.second = M;
    }
    else if (cosB >= cosA && cosB >= cosC)
    {
        angel = acos(cosB);
        QPointF M = QPointF((A.x() + C.x()) / 2, (A.y() + C.y()) / 2);
        QPointF H = findFootOfAltitude(B, A, C);
        height.first = B;
        height.second = H;
        median.first = B;
        median.second = M;
    }
    else
    {
        angel = acos(cosC);
        QPointF M = QPointF((A.x() + B.x()) / 2, (A.y() + B.y()) / 2);
        QPointF H = findFootOfAltitude(C, A, B);
        height.first = C;
        height.second = H;
        median.first = C;
        median.second = M;
    }
    }
}

bool checkPointsFromTable(QTableWidget* table)
{
    for (int row = 0; row < table->rowCount(); ++row)
    {
        QTableWidgetItem *xItem = table->item(row, 0);
        QTableWidgetItem *yItem = table->item(row, 1);

        if (!xItem || !yItem)
            return false;

        QString x = xItem->text();
        QString y = yItem->text();
        bool xisNumber, yisNumber;

        x.toDouble(&xisNumber);
        y.toDouble(&yisNumber);

        if (!xisNumber || !yisNumber)
            return false;
    }

    return true;
}

QList<QPointF>getPointsFromTable(QTableWidget* table)
{
    QList<QPointF> points = {};

    for (int row = 0; row < table->rowCount(); ++row)
    {
        QTableWidgetItem *xItem = table->item(row, 0);
        QTableWidgetItem *yItem = table->item(row, 1);
        if (xItem && yItem)
        {
            qreal x = xItem->text().toDouble();
            qreal y = yItem->text().toDouble();
            points.append(QPointF(x, y));
        }
    }
    return points;
}

QList<Triangle> formTriangles(const QList<QPointF>& points)
{
    QList<Triangle> triangles = {};

    if (points.size() < 3)
        return triangles;

    for (int i = 0; i < points.size() - 2; ++i) {
        for (int j = i + 1; j < points.size() - 1; ++j) {
            for (int k = j + 1; k < points.size(); ++k) {
                const QPointF& A = points[i];
                const QPointF& B = points[j];
                const QPointF& C = points[k];

                qreal area = 0.5 * std::abs(
                                 A.x() * (B.y() - C.y()) +
                                 B.x() * (C.y() - A.y()) +
                                 C.x() * (A.y() - B.y())
                                 );
                if (area != 0)
                    triangles.append(Triangle(A, B, C));
            }
        }
    }
    return triangles;
}

Triangle findTriangleMin(QList<Triangle>& triangles)
{
    qreal minAngel = 180;
    Triangle minTriangle = Triangle(QPointF(0, 0), QPointF(0, 0), QPointF(0, 0));
    for (auto triangle : triangles)
    {
        if (minAngel > triangle.angel)
        {
            minTriangle = triangle;
            minAngel = triangle.angel;
        }
    }
    return minTriangle;
}


