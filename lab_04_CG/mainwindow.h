#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVBoxLayout>
#include <QtCharts>

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GraphWindow : public QMainWindow {
    Q_OBJECT
public:
    GraphWindow(QWidget* parent = nullptr)
        : QMainWindow(parent)
    {
        QWidget* central = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(central);
        central->setLayout(layout);
        setCentralWidget(central);
    }

    void setChart(QChartView* chart)
    {
        QLayoutItem* item;
        while ((item = centralWidget()->layout()->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
        centralWidget()->layout()->addWidget(chart);
    }
signals:
    void firstWindow();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showCharts();

    void setView(QImage &image, QGraphicsView *view);

private slots:
    
    void on_pushButtonCircle_clicked();
    
    void on_pushButtonEllipse_clicked();
    
    void on_pushButtonCircleSpec_clicked();
    
    void on_pushButtonEllipseSpec_clicked();
    
    void on_pushButtonClrear_clicked();
    
    void on_pushButtonGraphs_clicked();
    
    private:
        Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
