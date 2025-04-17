#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "error.h"

#include "handler.h"

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

private:
    myerror_t on_actionLoad_clicked();

private slots:
    myerror_t draw_on_scene();

    myerror_t on_move_clicked();

    myerror_t on_scale_clicked();

    myerror_t on_rotate_clicked();

    void error_message(myerror_t &rc);

    void exitApp();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
