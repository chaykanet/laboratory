#include "rendering.h"

#include <chrono>

#include <QPainter>

Rendering::Rendering(QImage &_image, int _clr, int _fon)
{
    image = _image;
    clr = Colors(_clr);
    fon = Colors(_fon);
    image.fill(fon.qclr);
}

timesList Rendering::calcTimesForN(size_t n)
{
    timesList list;

    QPainter p(&image);

    Colors clr(2);

    auto start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
        Bresenham(0, 0, 707, 707);
    auto end_time = std::chrono::steady_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    list.push_back(time.count() / n);

    start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
        BresenhamDouble(0, 0, 707, 707);
    end_time = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    list.push_back(time.count() / n);

    start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
        BresenhamUnStep(0, 0, 707, 707);
    end_time = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);;

    list.push_back(time.count() / n);

    start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
        DDA(0, 0, 707, 707);
    end_time = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    list.push_back(time.count() / n);

    start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
        Wu(0, 0, 707, 707);
    end_time = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    list.push_back(time.count() / n);

    start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
        p.drawLine(0, 0, 707, 707);
    end_time = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    list.push_back(time.count() / n / 2);

    return list;
}

graphList Rendering::calcStepAlgos()
{
    graphList list = {};
    
    int lenLine = 10;
    
    pointsList points = {};
    for (double angle = 0; angle <= 180.0; angle += 10.0)
    {   
        double angle_deg = angle;
        double angle_rad = qDegreesToRadians(angle_deg);
        
        int xEnd = static_cast<int>(lenLine * qCos(angle_rad));
        int yEnd = static_cast<int>(lenLine * qSin(angle_rad));
        
        size_t n = calcStepBresenham(0, 0, xEnd, yEnd);

        points.push_back(std::make_pair(n, angle));
    }
    list.push_back(points);

    points = {};
    for (double angle = 0; angle <= 180.0; angle += 10.0)
    {   
        double angle_deg = angle;
        double angle_rad = qDegreesToRadians(angle_deg);
        
        int xEnd = static_cast<int>(lenLine * qCos(angle_rad));
        int yEnd = static_cast<int>(lenLine * qSin(angle_rad));
        
        size_t n = calcStepBresenhamDouble(0, 0, xEnd, yEnd);

        points.push_back(std::make_pair(n, angle));
    }
    list.push_back(points);
    
    points = {};
    for (double angle = 0; angle <= 180.0; angle += 10.0)
    {   
        double angle_deg = angle;
        double angle_rad = qDegreesToRadians(angle_deg);
        
        int xEnd = static_cast<int>(lenLine * qCos(angle_rad));
        int yEnd = static_cast<int>(lenLine * qSin(angle_rad));
        
        size_t n = calcStepBresenhamUnStep(0, 0, xEnd, yEnd);

        points.push_back(std::make_pair(n, angle));
    }
    list.push_back(points);
    
    points = {};
    for (double angle = 0; angle <= 180.0; angle += 10.0)
    {   
        double angle_deg = angle;
        double angle_rad = qDegreesToRadians(angle_deg);
        
        int xEnd = static_cast<int>(lenLine * qCos(angle_rad));
        int yEnd = static_cast<int>(lenLine * qSin(angle_rad));
        
        size_t n = calcStepWu(0, 0, xEnd, yEnd);

        points.push_back(std::make_pair(n, angle));
    }
    list.push_back(points);
    
    points = {};
    for (double angle = 0; angle <= 180.0; angle += 10.0)
    {   
        double angle_deg = angle;
        double angle_rad = qDegreesToRadians(angle_deg);
        
        int xEnd = static_cast<int>(lenLine * qCos(angle_rad));
        int yEnd = static_cast<int>(lenLine * qSin(angle_rad));
        
        size_t n = calcStepDDA(0, 0, xEnd, yEnd);

        points.push_back(std::make_pair(n, angle));
    }
    list.push_back(points);

    return list;
}


void Rendering::drawBrunch(alg algos, QPainter &p, double angle, double lenLine)
{
    size_t n = 360.0 / angle;

    int xCenter = image.width() / 2;
    int yCenter = image.height() / 2;

    for (size_t i = 0; i < n; ++i)
    {
        double angle_deg = angle * i;
        double angle_rad = qDegreesToRadians(angle_deg);

        int xEnd = xCenter + static_cast<int>(lenLine * qCos(angle_rad));
        int yEnd = yCenter + static_cast<int>(lenLine * qSin(angle_rad));

        rendering(algos, p, xCenter, yCenter, xEnd, yEnd);
    }
}

void Rendering::rendering(alg algos, QPainter &p, int x1, int y1, int x2, int y2)
{
    // p.fillRect(image.rect(), fon.qclr);

    Algorithms::rendering(algos, p, clr, x1, y1, x2, y2);
}

void Rendering::renderingDDA(QPainter &p, int x1, int y1, int x2, int y2)
{
    // p.fillRect(image.rect(), fon.qclr);
    Algorithms::renderingDDA(p, clr, x1, y1, x2, y2);
}

void Rendering::renderingBresenham(QPainter &p, int x1, int y1, int x2, int y2)
{
    // p.fillRect(image.rect(), fon.qclr);
    Algorithms::renderingBresenham(p, clr, x1, y1, x2, y2);
}

void Rendering::renderingWu(QPainter &p, int x1, int y1, int x2, int y2)
{
    // p.fillRect(image.rect(), fon.qclr);
    Algorithms::renderingWu(p, clr, x1, y1, x2, y2);
}

void Rendering::renderingBresenhamUnStep(QPainter &p, int x1, int y1, int x2, int y2)
{
    // p.fillRect(image.rect(), fon.qclr);
    Algorithms::renderingBresenhamUnStep(p, clr, x1, y1, x2, y2);
}

void Rendering::renderingBresenhamDouble(QPainter &p, double x1, double y1, double x2, double y2)
{
    // p.fillRect(image.rect(), fon.qclr);
    Algorithms::renderingBresenhamDouble(p, clr, x1, y1, x2, y2);
}
