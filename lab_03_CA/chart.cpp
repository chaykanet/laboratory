#include "chart.h"

#include "fstream"

chart::chart(Points &points1D, Points &points2D, int degree, int mode)
{   
    _points1D = points1D;
    _points2D = points2D;

    _degree = degree;
    _mode = mode;
}

void chart::setP()
{
    for (size_t i = 0; i < _points1D.len; ++i)
        _points1D.points[i].p = 1;

    for (size_t i = 0; i < _points2D.len; ++i)
        _points2D.points[i].p = 1;
}

void chart::funcFor1D(QLineSeries *line)
{
    vector coeffs = calcCoeffsFor1D(_points1D.points, _degree);

    double xStart = _points1D.points[0].x;
    double xEnd = _points1D.points[_points1D.len - 1].x;

    for (double x = xStart; x <= xEnd; x += 0.05)
    {
        double y = approximateFor1D(x, coeffs);
        line->append(x, y);
    }
}

void chart::funcFor2D()
{
    vector coeffs = calcCoeffsFor2D(_points2D.points, _degree);

    double xStart = _points2D.points[0].x;
    double xEnd = _points2D.points[_points2D.len - 1].x;

    double yStart = _points2D.points[0].y;
    double yEnd = _points2D.points[_points2D.len - 1].y;
    
    std::ofstream file("out.txt");
    for (double x = xStart; x <= xEnd; x += 0.10)
    {
        for (double y = yStart; y < yEnd; y += 0.10)
        {
            double z = approximateFor2D(x, y, coeffs);
        
            file << x <<  ' ' << y  << ' ' << z << ' ' << '\n';
        }
    }
    file.close();
}

void chart::eqFor2M(QLineSeries *line)
{   
    diffequal eq;

    eq.solveFor2M();

    double xStart = 0;
    double xEnd = 1;

    for (double x = xStart; x < xEnd; x += 0.10)
    {
        double y = eq.approximateEq(x);
        line->append(x, y);
    }
}

void chart::eqFor3M(QLineSeries *line)
{
    diffequal eq;
    
    eq.solveFor3M();

    double xStart = 0;
    double xEnd = 1;

    for (double x = xStart; x < xEnd; x += 0.10)
    {
        double y = eq.approximateEq(x);
        line->append(x, y);
    }
}

void chart::plotPolynomial(int argc, char *argv[])
{
    if (_mode == 1)
    {
        funcFor2D();
        return;
    }
    
    std::vector<double> coeffs;    

    QApplication app(argc, argv); // Инициализация Qt
    
    // Создание серий данных
    QLineSeries *polySeries = new QLineSeries();
    polySeries->setName("узлы со своими весами");

    QScatterSeries *dataSeries = new QScatterSeries();
    QChart *chart = new QChart();        
    if (_mode == 0)
    {
        for (auto point : _points1D.points) {
            dataSeries->append(point.x, point.y);
        }

        QLineSeries *polySeries1p = new QLineSeries();
        polySeries1p->setName("Узлы с весом 1");        

        funcFor1D(polySeries);
        setP();
        funcFor1D(polySeries1p);
        chart->addSeries(polySeries1p);
    }

    // Настройка графика
    chart->addSeries(polySeries);
    chart->addSeries(dataSeries);
    chart->createDefaultAxes();

    if (_mode == 0)
        chart->setTitle("Squares Approximation For 1D");
    else if (_mode == 1)
        chart->setTitle("Squares Approximation For 2D");    

    // Окно для отображения
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();

    app.exec(); // Запуск цикла обработки событий
}


void chart::plotDiffEqual(int argc, char *argv[])
{ 
    QApplication app(argc, argv); // Инициализация Qt
    
    // Создание серий данных
    QLineSeries *polySeries2m = new QLineSeries();
    QLineSeries *polySeries3m = new QLineSeries();
        
    polySeries2m->setName("m=2");
    polySeries3m->setName("m=3");    

    eqFor2M(polySeries2m);
    eqFor3M(polySeries3m);

    // Настройка графика
    QChart *chart = new QChart();
    chart->addSeries(polySeries2m);
        
    chart->addSeries(polySeries3m);

    chart->createDefaultAxes();

    chart->setTitle("Solution for diff eq for m=2 and m=3");    

    // Окно для отображения
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();

    app.exec(); // Запуск цикла обработки событий
}
