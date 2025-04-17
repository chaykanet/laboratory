#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "figure.h"

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
    ~MainWindow();

private slots:
    void exitApp();

    void draw();

    void step_back();

    void on_actionLoad_clicked();

    void on_rotateButton_clicked();

    void on_moveButton_clicked();

    void on_scaleButton_clicked();

    void drawAxes(QPainter &p);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
