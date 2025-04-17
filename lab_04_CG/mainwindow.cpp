#include <QtCharts>

#include "colors.h"
#include "algoscalc.h"
#include "algorithmsRender.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PIXEL_H 1000
#define PIXEL_W 1000

QImage image = QImage(PIXEL_H, PIXEL_W, QImage::Format_ARGB32);

void MainWindow::setView(QImage &image, QGraphicsView *view)
{
    QPixmap pixmap = QPixmap::fromImage(image);
    QGraphicsScene *scene = view->scene();
    scene->addPixmap(pixmap);
    view->setScene(scene);
}

QString _clr = {};
QString _fon = {};

static alg defineAlg(const QString &algStr);

static Qt::GlobalColor defineClr(const QString &clrStr);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBoxRStart->setRange(0, 500);
    ui->doubleSpinBoxAStart->setRange(0, 500);
    ui->doubleSpinBoxBStart->setRange(0, 500);
    
    ui->doubleSpinBoxXc->setRange(0, 1000);
    ui->doubleSpinBoxYc->setRange(0, 1000);

    ui->doubleSpinBoxR->setRange(0, 1000);
    ui->doubleSpinBoxA->setRange(0, 1000);
    ui->doubleSpinBoxB->setRange(0, 1000);
        
    
    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");
    scene->setSceneRect(0, 0, PIXEL_W, PIXEL_H);
    
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_11->setReadOnly(true);
    ui->lineEdit_10->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->lineEdit_9->setReadOnly(true);

    connect(ui->pushButtonGraphs, &QPushButton::clicked,
            this, &MainWindow::showCharts);
}

MainWindow::~MainWindow()
{
    delete ui->graphicsView->scene();
    delete ui;
}

// Создание графика для окружности
QChart* createCircleTimeChart() {
    // Получаем данные для R = 500
    const double R = 500;

    algoscalc circle;
    algosTimes data = circle.calcForRCircle(R);
    
    QChart* chart = new QChart();
    chart->setTitle("Circle Drawing Time (R=500)");
    
    // Создаем серии данных
    QLineSeries* canonical = new QLineSeries();
    canonical->setName("Canonical");
    QLineSeries* parametric = new QLineSeries();
    parametric->setName("Parametric");
    QLineSeries* bresenham = new QLineSeries();
    bresenham->setName("Bresenham");
    QLineSeries* midpoint = new QLineSeries();
    midpoint->setName("Midpoint");
    QLineSeries* std = new QLineSeries();
    std->setName("Std");

    // Заполняем данными
    double step = R / 100.0;
    for (size_t i = 0; i < data[0].size(); ++i) {
        double radius = i * step;
        canonical->append(radius, data[0][i]);
        parametric->append(radius, data[1][i]);
        bresenham->append(radius, data[2][i]);
        midpoint->append(radius, data[3][i]);
        std->append(radius, data[4][i]);
    }

    // Добавляем серии на график
    chart->addSeries(canonical);
    chart->addSeries(parametric);
    chart->addSeries(bresenham);
    chart->addSeries(midpoint);
    chart->addSeries(std);

    // Настройка осей
    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Radius");
    axisX->setLabelFormat("%d");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Time (ms)");
    chart->addAxis(axisY, Qt::AlignLeft);

    // Привязка серий к осям
    for (auto series : chart->series()) {
        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    return chart;
}

// Создание графика для эллипса
QChart* createEllipseTimeChart() {
    // Получаем данные для a=500, b=250
    const double a = 500, b = 250;

    algoscalc ellipse;
    algosTimes data = ellipse.calcForabEllipse(a, b);
    
    QChart* chart = new QChart();
    chart->setTitle("Ellipse Drawing Time (a=500, b=250)");

    // Создаем серии данных
    QLineSeries* canonical = new QLineSeries();
    canonical->setName("Canonical");
    QLineSeries* parametric = new QLineSeries();
    parametric->setName("Parametric");
    QLineSeries* bresenham = new QLineSeries();
    bresenham->setName("Bresenham");
    QLineSeries* midpoint = new QLineSeries();
    midpoint->setName("Midpoint");
    QLineSeries* std = new QLineSeries();
    std->setName("Std");

    // Заполняем данными
    double step = a / 100.0;
    for (size_t i = 0; i < data[0].size(); ++i) {
        double size = i * step;
        canonical->append(size, data[0][i]);
        parametric->append(size, data[1][i]);
        bresenham->append(size, data[2][i]);
        midpoint->append(size, data[3][i]);
        std->append(size, data[4][i]);
    }

    chart->addSeries(canonical);
    chart->addSeries(parametric);
    chart->addSeries(bresenham);
    chart->addSeries(midpoint);
    chart->addSeries(std);    

    // Настройка осей
    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Axes a and b");
    axisX->setLabelFormat("%d");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Time (ms)");
    chart->addAxis(axisY, Qt::AlignLeft);

    // Привязка серий к осям
    for (auto series : chart->series())
    {
        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    return chart;
}

// Использование в QWidget
void MainWindow::showCharts()
{
    QChart* circleChart = createCircleTimeChart();
    QChart* ellipseChart = createEllipseTimeChart();
    
    // Создаем QChartView для отображения
    QChartView* circleView = new QChartView(circleChart);
    QChartView* ellipseView = new QChartView(ellipseChart);
    
    GraphWindow* windowGraphCircle = new GraphWindow;
    GraphWindow* windowGraphEllipse = new GraphWindow;
    
    connect(windowGraphCircle, &GraphWindow::firstWindow, this, &MainWindow::show);
    connect(windowGraphEllipse, &GraphWindow::firstWindow, this, &MainWindow::show);

    windowGraphCircle->setAttribute(Qt::WA_DeleteOnClose);
    windowGraphCircle->setChart(circleView);
    windowGraphCircle->show();

    windowGraphEllipse->setAttribute(Qt::WA_DeleteOnClose);
    windowGraphEllipse->setChart(ellipseView);
    windowGraphEllipse->show();
} 
void MainWindow::on_pushButtonCircle_clicked()
{
    QString colorStr = ui->comboBoxClr->currentText();
    QString fonStr = ui->comboBoxFon->currentText();
    
    Colors color = defineClr(colorStr);
    Colors fon = defineClr(fonStr);

    if (fonStr != _fon)
    {
        _fon = fonStr;
        image.fill(fon.qclr);
    }

    double xCenter = ui->doubleSpinBoxXc->value();
    double yCenter = ui->doubleSpinBoxYc->value();
    double R = ui->doubleSpinBoxR->value();

    alg algos = defineAlg(ui->comboBoxAlgos->currentText()); 

    QPainter p(&image);
    p.setPen(color.qclr);

    AlgorithmsRender circle;
    circle.Circle(algos, p, xCenter, yCenter, R);

    setView(image, ui->graphicsView);
}

void MainWindow::on_pushButtonEllipse_clicked()
{
    QString colorStr = ui->comboBoxClr->currentText();
    QString fonStr = ui->comboBoxFon->currentText();
    
    Colors color = defineClr(colorStr);
    Colors fon = defineClr(fonStr);

    if (fonStr != _fon)
    {
        _fon = fonStr;
        image.fill(fon.qclr);
    }

    double xCenter = ui->doubleSpinBoxXc->value();
    double yCenter = ui->doubleSpinBoxYc->value();
    double a = ui->doubleSpinBoxA->value();
    double b = ui->doubleSpinBoxB->value();
    
    alg algos = defineAlg(ui->comboBoxAlgos->currentText()); 

    QPainter p(&image);
    p.setPen(color.qclr);

    AlgorithmsRender ellipse;
    ellipse.Ellipse(algos, p, xCenter, yCenter, a, b);

    setView(image, ui->graphicsView);
}

void MainWindow::on_pushButtonCircleSpec_clicked()
{
    QString colorStr = ui->comboBoxClr->currentText();
    QString fonStr = ui->comboBoxFon->currentText();
    
    Colors color = defineClr(colorStr);
    Colors fon = defineClr(fonStr);

    if (fonStr != _fon)
    {
        _fon = fonStr;
        image.fill(fon.qclr);
    }

    double xCenter = ui->doubleSpinBoxXc->value();
    double yCenter = ui->doubleSpinBoxYc->value();
    double R = ui->doubleSpinBoxRStart->value();

    int step = ui->spinBoxStepSpec->value();
    int stepNums = ui->spinBoxNumsSpec->value();
    
    alg algos = defineAlg(ui->comboBoxAlgos->currentText()); 

    QPainter p(&image);
    p.setPen(color.qclr);

    AlgorithmsRender circle;
    circle.CircleSpector(algos, p, xCenter, yCenter, R, step, stepNums);

    setView(image, ui->graphicsView);
}

void MainWindow::on_pushButtonEllipseSpec_clicked()
{
    QString colorStr = ui->comboBoxClr->currentText();
    QString fonStr = ui->comboBoxFon->currentText();
    
    Colors color = defineClr(colorStr);
    Colors fon = defineClr(fonStr);

    if (fonStr != _fon)
    {
        _fon = fonStr;
        image.fill(fon.qclr);
    }

    double xCenter = ui->doubleSpinBoxXc->value();
    double yCenter = ui->doubleSpinBoxYc->value();
    double a = ui->doubleSpinBoxAStart->value();
    double b = ui->doubleSpinBoxBStart->value();
    
    int step = ui->spinBoxStepSpec->value();
    int stepNums = ui->spinBoxNumsSpec->value();
    
    alg algos = defineAlg(ui->comboBoxAlgos->currentText()); 

    QPainter p(&image);
    p.setPen(color.qclr);

    AlgorithmsRender ellipse;
    ellipse.EllipseSpector(algos, p, xCenter, yCenter, a, b, step, stepNums);

    setView(image, ui->graphicsView);
}

void MainWindow::on_pushButtonClrear_clicked()
{
    image.fill(Qt::white);
    _fon = {};

    setView(image, ui->graphicsView);
}

void MainWindow::on_pushButtonGraphs_clicked()
{

}


Qt::GlobalColor defineClr(const QString &clrStr)
{
    if (clrStr == "Красный")
        return Qt::GlobalColor::red;
    else if (clrStr == "Зеленый")
        return Qt::GlobalColor::green;
    else if (clrStr == "Синий")
        return Qt::GlobalColor::blue;
    else if (clrStr == "Черный")
        return Qt::GlobalColor::black;
    else if (clrStr == "Белый")
        return Qt::GlobalColor::white;

    return Qt::GlobalColor::white;
}

alg defineAlg(const QString &algStr)
{
    if (algStr == "Брезенхем.")
        return alg::Alg_BRES;
    else if (algStr == "Средняя точка")
        return alg::Alg_MID;
    else if (algStr == "Парам. вид")
        return alg::Alg_PARAM;
    else if (algStr == "Канон. вид")
        return alg::Alg_CANON;
    else if (algStr == "Библ. функция")
        return alg::Alg_STD;
    
    return alg::Alg_STD;
} 
