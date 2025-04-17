#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "rendering.h"

#include <cmath>
#include <QtCharts>

#define HEIGHT 6000
#define WIDTH 6000

#define PIXEL_H 500
#define PIXEL_W 400

static Qt::GlobalColor defineClr(const QString &clrStr);

static alg defineAlg(const QString &algStr);

QImage image = QImage(PIXEL_H, PIXEL_W, QImage::Format_ARGB32);

QString prevFonView_1 = {};
QString prevFonView_2 = {};

void MainWindow::setView(QImage &image, QGraphicsView *view)
{
    QPixmap pixmap = QPixmap::fromImage(image);
    QGraphicsScene *scene = view->scene();
    scene->addPixmap(pixmap);
    view->setScene(scene);
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBoxXStart->setRange(0, 5000);
    ui->doubleSpinBoxYStart->setRange(0, 5000);
    ui->doubleSpinBoxXEnd->setRange(0, 5000);
    ui->doubleSpinBoxYEnd->setRange(0, 5000);

    ui->doubleSpinBoxGrad->setRange(0, 360);
    ui->doubleSpinBoxLen->setRange(0, 1000);

    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsScene *sceneLine = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    

    ui->graphicsView_2->setScene(sceneLine);
    ui->graphicsView_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView_2->setStyleSheet("QGraphicsView {background-color: white}");
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    
    ui->lineEditAlg->setReadOnly(true);
    ui->lineEditAlg_2->setReadOnly(true);
    ui->lineEditGrad->setReadOnly(true);
    ui->lineEditLen->setReadOnly(true);
    ui->lineEditXEnd->setReadOnly(true);
    ui->lineEditXStart->setReadOnly(true);
    ui->lineEditYStart->setReadOnly(true);
    ui->lineEditYEnd->setReadOnly(true);
    ui->lineEdit_10->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->lineEdit_9->setReadOnly(true);

    connect(ui->drawHistogram, &QPushButton::clicked,
            this, &MainWindow::showGraphWindow);
}

void MainWindow::showGraphWindow()
{
    QChartView* chart, *chart_2;
    
    chart = createSeries(1000);
    chart_2 = createGraphs();

    GraphWindow* windowHistogram = new GraphWindow;
    GraphWindow* windowGraph = new GraphWindow;
    QChartView* graphs = createGraphs();
    connect(windowHistogram, &GraphWindow::firstWindow, this, &MainWindow::show);
    connect(windowGraph, &GraphWindow::firstWindow, this, &MainWindow::show);

    windowHistogram->setAttribute(Qt::WA_DeleteOnClose);
    windowHistogram->setChart(chart);
    windowHistogram->show();

    windowGraph->setAttribute(Qt::WA_DeleteOnClose);
    windowGraph->setChart(graphs);
    windowGraph->show();
}  

QChartView* MainWindow::createSeries(size_t n)
{
    QImage image = QImage(HEIGHT, WIDTH, QImage::Format_RGB16);

    Rendering histogram = Rendering(image, Qt::black, Qt::white);

    QBarSet *bresenham = new QBarSet("Бр-хем.");
    QBarSet *bresenhamDouble = new QBarSet("Бр-xeм c дейст.");
    QBarSet *bresenhamUnStep = new QBarSet("Бр-хем без ступ.");
    QBarSet *dda = new QBarSet("ЦДА.");
    QBarSet *wu = new QBarSet("Ву.");
    QBarSet *standart = new QBarSet("Станд. Qt");

    QList<qreal> categories;

    timesList times = histogram.calcTimesForN(1000);
    *bresenham << times[0];
    *bresenhamDouble << times[1];
    *bresenhamUnStep << times[2];
    *dda << times[3];
    *wu << times[4];
    *standart << times[5];
    categories << static_cast<qreal>(1000);

    QBarSeries *series = new QBarSeries();
    series->append(bresenham);
    series->append(bresenhamDouble);
    series->append(bresenhamUnStep);
    series->append(dda);
    series->append(wu);
    series->append(standart);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Сравнение алгоритмов построения линий");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    QStringList catLabels;

    for (auto val : categories) catLabels << QString::number(val);

    axisX->append(catLabels);
    axisX->setTitleText("Прямая от (0, 0) до (n, n), n");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText(QString("Время нс (Длина отрезка %1)").arg(n));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

QChartView* MainWindow::createGraphs()
{
    QImage image = QImage(HEIGHT, WIDTH, QImage::Format_RGB16);
    Rendering graphs = Rendering(image, Qt::black, Qt::white);
    graphList graphics = graphs.calcStepAlgos();

    QChart *chart = new QChart();
    chart->setTitle("Зависимость ступенчатости от угла наклона");

    QStringList algorithmNames = {
        "Брезенхем",
        "Брезенхем с действительными",
        "Брезенхем без ступенчатости",
        "Ву",
        "ЦДА"
    };

    QList<QLineSeries*> seriesList;
    for (size_t i = 0; i < graphics.size(); ++i)
    {
        QLineSeries *series = new QLineSeries();
        series->setName(algorithmNames[i]);
        
        for (const auto &point : graphics[i])
        {
            series->append(point.second, point.first);
        }
        
        seriesList.append(series);
        chart->addSeries(series);
    }

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Угол (градусы)");
    axisX->setRange(0, 180);
    axisX->setTickCount(19);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Ступенчатость");
    axisY->setMin(0);
    axisY->setMax(10);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    for (QLineSeries *series : seriesList)
    {
        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawHistogram_clicked()
{
    return;
}

void MainWindow::on_pushButtonBunch_clicked()
{
    double angle = ui->doubleSpinBoxGrad->value();
    double len = ui->doubleSpinBoxLen->value();

    QString clrStr = ui->comboBoxClr_2->currentText();
    QString fonStr = ui->comboBoxFon_2->currentText();
    QString algStr =  ui->comboBoxAlgos_2->currentText();
    
    Qt::GlobalColor clr, fon;    

    clr = defineClr(clrStr);
    fon = defineClr(fonStr);
    alg algos = defineAlg(algStr);    

    QImage image_2 = QImage(PIXEL_H, PIXEL_W, QImage::Format_ARGB32);
    QPainter p(&image_2);
    
    image_2.fill(fon);
            
    Rendering render(image_2, clr, fon);

    render.drawBrunch(algos, p, angle, len);
    setView(image_2, ui->graphicsView);
}

void MainWindow::on_pushButtonLine_clicked()
{
    double xStart = ui->doubleSpinBoxXStart->value();
    double yStart = ui->doubleSpinBoxYStart->value();
    
    double xEnd = ui->doubleSpinBoxXEnd->value();
    double yEnd = ui->doubleSpinBoxYEnd->value();
    
    QString clrStr = ui->comboBoxClr->currentText();
    QString fonStr = ui->comboBoxFon->currentText();
    QString algosStr = ui->comboBoxAlgos->currentText();
    
    Qt::GlobalColor clr = defineClr(clrStr);
    Qt::GlobalColor fon = defineClr(fonStr);
    
    if (fonStr != prevFonView_1)
    {    
        image.fill(fon);
        prevFonView_1 = fonStr;
    }
    alg algos = defineAlg(algosStr);
    
    QPainter p(&image);
    Rendering line(image, clr, fon);

    line.rendering(algos, p, xStart, yStart, xEnd, yEnd);
    setView(image, ui->graphicsView_2);
}

void MainWindow::on_pushButtonClr_clicked()
{
    image.fill(Qt::white);
    QGraphicsScene *scene = ui->graphicsView_2->scene();
    scene->clear();
    return;
}

void MainWindow::on_pushButtonClr_2_clicked()
{
    QGraphicsScene *scene = ui->graphicsView->scene();
    scene->clear();
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
    if (algStr == "Бр-хем. дейст.")
        return alg::Alg_BresD;
    else if (algStr == "Бр-хем. без ступ.")
        return alg::Alg_BresUnStep;
    else if (algStr == "Алг-м. Ву.")
        return alg::Alg_Wu;
    else if (algStr == "Алг-м. ЦДА.")
        return alg::Alg_DDA;

    return alg::Alg_Bres;
} 

// 1. Алгоритм ЦДА (Цифровой дифференциальный анализатор)

// Формула длины ступеньки:
// Максимальная длина ступеньки вдоль оси X:
// Lmax=⌈1∣m∣⌉,где m=dydx (наклон).
// Lmax​=⌈∣m∣1​⌉,где m=dxdy​ (наклон).

// Особенности:
// Для малых углов (близких к 0° или 180°) длина ступеньки стремится к бесконечности. Для углов 45°: Lmax=1Lmax​=1.

// 2. Алгоритм Брезенхема (целочисленный)

// Формула длины ступеньки:
// Для линий с ∣m∣<1∣m∣<1:
// Lmax=⌊dxdy⌋.
// Lmax​=⌊dydx​⌋.

// Для линий с ∣m∣≥1∣m∣≥1 (углы ≥ 45°):
// Lmax=⌊dydx⌋.
// Lmax​=⌊dxdy​⌋.

// Особенности:
// Длина ступеньки зависит от отношения dxdydydx​. Например, для dx=5dx=5, dy=2dy=2: Lmax=2Lmax​=2.

// 3. Алгоритм Брезенхема с устранением ступенчатости

// Формула длины ступеньки:
// Максимальная длина ступеньки уменьшается за счет сглаживания:
// Lmax=⌊1∣m∣⌋.
// Lmax​=⌊∣m∣1​⌋.

// Особенности:
// Ступеньки становятся менее заметными из-за интерполяции интенсивности между соседними пикселями.

// 4. Алгоритм Ву (Xiaolin Wu)

// Формула длины ступеньки:
// Теоретически ступеньки отсутствуют, так как алгоритм рисует два пикселя с плавным переходом интенсивности.
// Условная "длина" ступеньки:
// Lmax=1(расстояние между соседними пикселями).
// Lmax​=1(расстояние между соседними пикселями).

// Особенности:
// Антиалиасинг полностью устраняет ступенчатость, но требует расчета интенсивности для двух пикселей на каждом шаге.

// Общие зависимости от угла:

// Угол 0° или 180° (горизонтальная линия):
// Нет ступенек (Lmax→∞Lmax​→∞).

// Угол 45°:
// Lmax=1Lmax​=1 (ступеньки минимальны).

// Угол 90° (вертикальная линия):
// Нет ступенек (Lmax→∞Lmax​→∞).

// Пример расчета для dx=10dx=10, dy=3dy=3 (угол ~16.7°):

// ЦДА:
// Lmax=⌈10.3⌉=4.
// Lmax​=⌈0.31​⌉=4.

// Брезенхем (целочисленный):
// Lmax=⌊103⌋=3.
// Lmax​=⌊310​⌋=3.

// Брезенхем с устранением ступенчатости:
// Lmax=⌊10.3⌋=3.
// Lmax​=⌊0.31​⌋=3.

// Итог:
// Максимальная длина ступеньки обратно пропорциональна тангенсу угла наклона (∣m∣∣m∣). Для алгоритмов с антиалиасингом (Ву, Брезенхем с устранением ступенчатости) ступеньки визуально скрыты, но их условная длина определяется теми же принципами.

// QWidget* MainWindow::createWidgetGraphs()
// {
//     QImage image = QImage(HEIGHT, WIDTH, QImage::Format_RGB16);
//     Rendering graphs = Rendering(image, Qt::black, Qt::white);
//     graphList graphics = graphs.calcStepAlgos();

//     // Контейнер для всех графиков
//     QWidget *container = new QWidget();
//     QGridLayout *layout = new QGridLayout(container);

//     QStringList algorithmNames = {
//         "Брезенхем",
//         "Брезенхем с действительными",
//         "Брезенхем без ступенчатости",
//         "Ву",
//         "ЦДА"
//     };

//     // Создаем отдельный график для каждого алгоритма
//     for (size_t i = 0; i < graphics.size(); ++i) 
//     {
//         QChart *chart = new QChart();
//         QLineSeries *series = new QLineSeries();
//         series->setName(algorithmNames[i]);
        
//         for (const auto &point : graphics[i]) {
//             series->append(point.second, point.first);
//         }

//         chart->addSeries(series);
//         chart->setTitle(QString("Ступенчатость: %1").arg(algorithmNames[i]));

//         // Настройка осей
//         QValueAxis *axisX = new QValueAxis();
//         axisX->setTitleText("Угол (градусы)");
//         axisX->setRange(0, 180);
        
//         QValueAxis *axisY = new QValueAxis();
//         axisY->setTitleText("Ступенчатость");
//         axisY->setMin(0);

//         chart->addAxis(axisX, Qt::AlignBottom);
//         chart->addAxis(axisY, Qt::AlignLeft);
//         series->attachAxis(axisX);
//         series->attachAxis(axisY);

//         QChartView *chartView = new QChartView(chart);
//         chartView->setRenderHint(QPainter::Antialiasing);
//         layout->addWidget(chartView);
//     }

//     container->setLayout(layout);
//     return container;
// }
