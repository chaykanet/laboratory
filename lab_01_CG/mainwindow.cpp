#include <Qt>
#include <QFileDialog>
#include <QPainter>
#include <QVector3D>
#include <QMessageBox>
#include <QTableView>
#include <QTableWidget>
#include <QDebug>

#include <ctime>
#include <stdlib.h>

#include <iostream>

#include "func_triangle.h"
#include "message.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


double RATE_FIELD = 1;

long int PIXEL_X = 350;
long int PIXEL_Y = 370;
long int SPACE_PIXEL = 80;

QGraphicsScene *scene;

qreal scale = 1;

qreal stepX = 10;
qreal stepY = 10;

static QRectF boundingRect(const QPointF& p1, const QPointF& p2, const QPointF& p3);

static QPointF scalePoint(const QPointF& point, const QRectF& rect, qreal scale, int imageWidth, int imageHeight);

Triangle triangle = Triangle(QPointF(0, 0), QPointF(0, 0), QPointF(0, 0));

MainWindow::MainWindow(QWidget *parent) // konstructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene();
}

MainWindow::~MainWindow() // destructor
{
    delete scene;
    delete ui;
}

void MainWindow::drawPoints(QPainter& p, QList<QPointF>& points)
{
    for (auto point : points)
    {
        qreal x = point.x();
        qreal y = point.y();

        p.drawEllipse(x - 2, y - 2, 4, 4);
    }
}

void MainWindow::drawAxes(QPainter& p, QRectF& rect, int imageWidth, int imageHeight)
{
    QPointF rectCenter = QPointF(rect.left() + rect.width() / 2, rect.top() + rect.height() / 2);

    qreal dx = 0 - rectCenter.x();
    qreal dy = 0 - rectCenter.y();

    dx *= scale;
    dy *= scale;

    qreal offsetX = dx + imageWidth / 2;
    qreal offsetY = -dy + imageHeight / 2;

    // оси
    p.drawLine(0, offsetY, imageWidth + SPACE_PIXEL, offsetY);
    p.drawLine(offsetX, 0, offsetX, imageHeight + SPACE_PIXEL);

    // штрихи для оси оx
    for (qreal x = offsetX; x <= imageWidth + SPACE_PIXEL; x += stepX *scale) {
        p.drawLine(x, offsetY - 4, x, offsetY + 4);
    }
    for (qreal x = offsetX; x >= 0; x -= stepX * scale) {
        p.drawLine(x, offsetY - 4, x, offsetY + 4);
    }
    // штрихи для оси оy
    for (qreal y = offsetY; y <= imageHeight + SPACE_PIXEL; y += stepY * scale) {
        p.drawLine(offsetX - 4, y, offsetX + 4, y);
    }
    for (qreal y = offsetY; y >= 0; y -= stepY * scale) {
        p.drawLine(offsetX - 4, y, offsetX + 4, y);
    }

    // направление осей
    p.drawLine(imageWidth + SPACE_PIXEL, offsetY, imageWidth + SPACE_PIXEL - 10, offsetY - 5);
    p.drawLine(imageWidth + SPACE_PIXEL, offsetY, imageWidth + SPACE_PIXEL - 10, offsetY + 5);

    p.drawLine(offsetX, 0, offsetX - 5, 10);
    p.drawLine(offsetX, 0, offsetX + 5, 10);

    // подписи осей
    p.drawText(imageWidth + SPACE_PIXEL - 20, offsetY - 10, "X");
    p.drawText(offsetX + 10, 20, "Y");
}

void MainWindow::on_drawPointsAndAxes_clicked()
{
    scene->clear();

    QImage image = QImage(PIXEL_X + SPACE_PIXEL, PIXEL_Y + SPACE_PIXEL, QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter p(&image);

    bool isCorrect = checkPointsFromTable(ui->tableWidget);
    QList<QPointF> points = {};

    if (isCorrect)
        points = getPointsFromTable(ui->tableWidget);
    else
    {
        callErrorValue(this);
        return;
    }

    if (points.size() >= 3 && isCorrect)
    {
        QList<Triangle> triangles = formTriangles(points);

        if (triangles.size())
        {
            QRectF rect;
            triangle = findTriangleMin(triangles);
            centerGraphicView(points, triangle, rect);

            p.setPen(Qt::black);
            p.setBrush(Qt::red);

            drawAxes(p, rect, PIXEL_X, PIXEL_Y);
            drawPoints(p, points);

            p.setPen(Qt::red);
            drawTriangle(p, triangle, rect);
            QString answer;
            callInfoTriangle(this, triangle, answer);
            ui->textEdit->setText(answer);
        }
        else
            callErrorDerenerate(this);
        triangles.clear();
    }
    else
        callErrorRange(this);
    points.clear();

    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_about_app_clicked()
{
    QMessageBox::about(this, "О программе", "На плоскости дано множество точек. Найти такой треугольник с вершинами этих точках, у которого угол, образованный высотой и медианой, исходящими из одной вершины, минимален");
}

void MainWindow::on_addPoint_clicked()
{
    QTableWidget *table = ui->tableWidget;
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(""));
    table->setItem(row, 1, new QTableWidgetItem(""));
    table->setCurrentCell(row, 0);
}

void MainWindow::drawTriangle(QPainter& p, Triangle& triangle, QRectF& rect)
{
    QPointF A = scalePoint(triangle.A, rect, scale, PIXEL_X, PIXEL_Y);
    QPointF B = scalePoint(triangle.B, rect, scale, PIXEL_X, PIXEL_Y);
    QPointF C = scalePoint(triangle.C, rect, scale, PIXEL_X, PIXEL_Y);
    p.drawLine(A, B);
    p.drawLine(A, C);
    p.drawLine(B, C);

    p.setPen(Qt::blue);
    p.setBrush(Qt::blue);

    QString xA = QString::number(triangle.A.x());
    QString yA = QString::number(triangle.A.y());
    QString xB = QString::number(triangle.B.x());
    QString yB = QString::number(triangle.B.y());
    QString xC = QString::number(triangle.C.x());
    QString yC = QString::number(triangle.C.y());

    QString xH = QString::number(triangle.height.second.x());
    QString yH = QString::number(triangle.height.second.y());

    QString xM = QString::number(triangle.median.second.x());
    QString yM = QString::number(triangle.median.second.y());

    QPointF N = scalePoint(triangle.median.first, rect, scale, PIXEL_X, PIXEL_Y);
    QPointF M = scalePoint(triangle.median.second, rect, scale, PIXEL_X, PIXEL_Y);

    QPointF L = scalePoint(triangle.height.first, rect, scale, PIXEL_X, PIXEL_Y);
    QPointF H = scalePoint(triangle.height.second, rect, scale, PIXEL_X, PIXEL_Y);

    p.setPen(Qt::black);
    p.drawText(A.x() + 10, A.y() + 10, QString("A(%1, %2)").arg(xA).arg(yA));
    p.drawText(B.x() + 10, B.y() + 10, QString("B(%1, %2)").arg(xB).arg(yB));
    p.drawText(C.x() + 10, C.y() + 10, QString("C(%1, %2)").arg(xC).arg(yC));

    p.drawText(H.x() + 10, H.y() + 10, QString("H(%1, %2)").arg(xH).arg(yH));
    p.drawText(M.x() + 10, M.y() + 10, QString("M(%1, %2)").arg(xM).arg(yM));

    p.setPen(Qt::blue);
    p.setBrush(Qt::blue);
    p.drawLine(N, M);
    p.drawLine(L, H);
}

void MainWindow::on_pushButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();

    if (currentRow >= 0)
        ui->tableWidget->removeRow(currentRow);
    else
        QMessageBox::information(this, "Внимание", "Выберите в таблице точку для удаления.");
}

void MainWindow::centerGraphicView(QList<QPointF>& points, Triangle& triangle, QRectF& rect)
{
    rect = boundingRect(triangle.A, triangle.B, triangle.C);

    QList<QPointF> shiftPoints = points;

    scale = std::min(PIXEL_X / rect.width(), PIXEL_Y / rect.height());

    for (int i = 0; i < shiftPoints.size(); ++i)
        shiftPoints[i] = scalePoint(shiftPoints[i], rect, scale, PIXEL_X, PIXEL_Y);

    points = shiftPoints;
}

QPointF scalePoint(const QPointF& point, const QRectF& rect, qreal scale, int imageWidth, int imageHeight) {

    QPointF rectCenter = QPointF(rect.left() + rect.width() / 2, rect.top() + rect.height() / 2);

    qreal dx = point.x() - rectCenter.x();
    qreal dy = point.y() - rectCenter.y();

    dx *= scale;
    dy *= scale;

    qreal x = dx + imageWidth / 2;
    qreal y = -dy + (imageHeight) / 2;

    return QPointF(x, y);
}

QRectF boundingRect(const QPointF& p1, const QPointF& p2, const QPointF& p3) {
    qreal minX = std::min({p1.x(), p2.x(), p3.x()});
    qreal minY = std::min({p1.y(), p2.y(), p3.y()});
    qreal maxX = std::max({p1.x(), p2.x(), p3.x()});
    qreal maxY = std::max({p1.y(), p2.y(), p3.y()});
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

void MainWindow::on_clear_clicked()
{
    scene->clear();
}

