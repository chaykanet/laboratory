#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCharts>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
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

private slots:
    void showGraphWindow();

    void setView(QImage &image, QGraphicsView *view);

    QChartView* createSeries(size_t n);

    QChartView* createGraphs();

    void on_drawHistogram_clicked();

    void on_pushButtonBunch_clicked();

    void on_pushButtonClr_clicked();

    void on_pushButtonClr_2_clicked();

    void on_pushButtonLine_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
