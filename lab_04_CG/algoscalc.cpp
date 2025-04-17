#include "algoscalc.h"

#include <chrono>

#include <QPainter>

#define CALC_TIMES 1000

algoscalc::algoscalc(){}


algosTimes algoscalc::calcForRCircle(double R)
{
    times vecTimes = {};
    algosTimes vecAlgTimes = {};
    
    double step = R / 100;
    for (size_t i = 0; i * step <= R; ++i)
    {
        long elapsed = 0;
        double _r = i * step;
        
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            CanonicalСircle(0, 0, _r);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    for (size_t i = 0; i * step <= R; ++i)
    {
    
        long elapsed = 0;
        double _r = i * step;
        
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            ParametricСircle(0, 0, _r);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    for (size_t i = 0; i * step <= R; ++i)
    {
    
        long elapsed = 0;
        double _r = i * step;
        
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            BresenhamСircle(0, 0, _r);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    for (size_t i = 0; i * step <= R; ++i)
    {
    
        long elapsed = 0;
        double _r = i * step;
        
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            MidpointСircle(0, 0, _r);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    QImage image = QImage(500, 500, QImage::Format_ARGB32);
    QPainter p(&image);
    for (size_t i = 0; i * step <= R; ++i)
    {
        long elapsed = 0;
        double _r = i * step;
        
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            p.drawEllipse(0, 0, _r, _r);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();
    return vecAlgTimes;
}

algosTimes algoscalc::calcForabEllipse(double a, double b)
{
    times vecTimes = {};
    algosTimes vecAlgTimes = {};
    
    double stepA = a / 100;
    double stepB = b / 100;

    for (size_t i = 0; i * stepA <= a; ++i)
    {
    
        long elapsed = 0;
        double _a = i * stepA;
        double _b = i * stepB;
    
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            CanonicalEllipse(0, 0, _a, _b);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    for (size_t i = 0; i * stepA <= a; ++i)
    {
    
        long elapsed = 0;
        double _a = i * stepA;
        double _b = i * stepB;
    
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            ParametricEllipse(0, 0, _a, _b);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    for (size_t i = 0; i * stepA <= a; ++i)
    {
    
        long elapsed = 0;
        double _a = i * stepA;
        double _b = i * stepB;
    
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            BresenhamEllipse(0, 0, _a, _b);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    for (size_t i = 0; i * stepA <= a; ++i)
    {
        long elapsed = 0;
        double _a = i * stepA;
        double _b = i * stepB;
    
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            MidpointEllipse(0, 0, _a, _b);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();
    
    QImage image = QImage(500, 500, QImage::Format_ARGB32);
    QPainter p(&image);
    for (size_t i = 0; i * stepA <= a; ++i)
    {
        long elapsed = 0;
        double _a = i * stepA;
        double _b = i * stepB;
    
        for (size_t j = 0; j < CALC_TIMES; ++j)
        {
            auto start_time = std::chrono::steady_clock::now();
            p.drawEllipse(0, 0, _a, _b);
            auto end_time = std::chrono::steady_clock::now();
            elapsed += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
        
        vecTimes.push_back(elapsed / CALC_TIMES);    
    }
    vecAlgTimes.push_back(vecTimes);
    vecTimes.clear();

    return vecAlgTimes;
}
