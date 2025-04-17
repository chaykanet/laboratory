#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "edge.h"
#include "qgraphicsitem.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using listPoints = QList<QPointF>; 

class MainWindow : public QMainWindow
{
    Q_OBJECT

    listPoints points;

    listEdges polygon;

    QList<QPointF> clickedPoints;
public:
    MainWindow(QWidget *parent = nullptr);
    
    bool eventFilter(QObject *watched, QEvent *event);

    void formEdges();

    void pixelEvent();

    void renderingEvent();
    
    ~MainWindow();

signals:
    void clicked();
    void pressed();

private slots:
void on_pushButtonClear_clicked();

void on_pushButtonPoint_clicked();

void on_pushButtonFigure_clicked();

private:
private:
    QGraphicsPixmapItem* pixmapItem = nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
