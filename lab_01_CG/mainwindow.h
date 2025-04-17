#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "func_triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent *);
    ~MainWindow();

private slots:
    void centerGraphicView(QList<QPointF>& points, Triangle& triangle, QRectF& rect);

    void drawTriangle(QPainter& p, Triangle& triangle, QRectF& rect);

    void drawAxes(QPainter& p, QRectF& rect, int imageWidth, int imageHeight);

    void drawPoints(QPainter& p, QList<QPointF>& points);

    void on_drawPointsAndAxes_clicked();

    void on_about_app_clicked();

    void on_addPoint_clicked();

    void on_pushButton_clicked();

    void on_clear_clicked();
private:
    Ui::MainWindow *ui;

    QList<QPointF> points_ = {
        QPointF(10, 10),
        QPointF(0, 10),
        QPointF(10, 0)
    };
};
#endif // MAINWINDOW_H
