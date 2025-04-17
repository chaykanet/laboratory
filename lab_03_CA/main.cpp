#include <iostream>

#include "chart.h"

#include <iostream>

#include "point.h"
#include "diffequal.h"
#include "squareapprox.h"

enum actions { NULL_ACT, ONE_APPROX, TWO_APPROX, SOLVE_EQU, ONE_CHANGE_P, TWO_CHANGE_P, QUIT };

void printMenu()
{
    std::cout << "Меню" << std::endl;
    std::cout << "1. Построить полином для одномерная аппроксимации." << std::endl;
    std::cout << "2. Построить полином для двумерной аппроксимации." << std::endl;
    std::cout << "3. Найти аналитическое решение ДУ." << std::endl;
    std::cout << "4. Изменить вес точки из 1D." << std::endl;
    std::cout << "5. Изменить вес точки из 2D." << std::endl;
    std::cout << "6. Выход." << std::endl;
    std::cout << "Номер: " << std::endl;
}

void handler(int argc, char *argv[], int act, Points &points1D, Points &points2D)
{
    switch (act)
    {
    case ONE_APPROX:
    { 
        squareApprox polinom1D;
        int degree = 4;
        std::cout << "Введите степень полинома:" << std::endl;
        std::cin >> degree;
        std::cout << std::endl;

        // if (points1D.len <= degree)
        // {
        //     std::cout << "Невозможно построить полином" << std::endl;
        //     break;
        // }
        
        point c = points1D.center();

        std::cout << "Координаты центра:" << std::endl;
        std::cout << c.x << ' ' << c.y << std::endl;
        
        chart graph(points1D, points2D, degree, 0);
        graph.plotPolynomial(argc, argv);       
        break;
    }
    case TWO_APPROX:
    {
        squareApprox polinom2D;
        int degree;
        std::cout << "Введите степень полинома:" << std::endl;
        std::cin >> degree;
        std::cout << std::endl;
        
        chart graph(points1D, points2D, degree, 1);
        graph.plotPolynomial(argc, argv);     
        break;
    }
    case SOLVE_EQU:
    {
        std::cout << std::endl;

        diffequal eq2;
        diffequal eq3;
        
        eq2.solveFor2M();
        eq2.print();
        eq2.fprintFor2M();

        eq3.solveFor3M();
        eq3.print();
        eq3.fprintFor3M();
    
        chart graph(points1D, points2D, 0, 0);
        graph.plotDiffEqual(argc, argv);
        
        break;
    }
    case ONE_CHANGE_P:
    {
        size_t index;
        double p;
        std::cout << "Введите индекс точки и ее вес:" << std::endl;
        std::cin >> index >> p;
        points1D.changeWeiht(index, p);
        break;
    }
    case TWO_CHANGE_P:
    {
        size_t index;
        double p;
        std::cout << "Введите индекс точки и ее вес:" << std::endl;
        std::cin >> index >> p;
        points2D.changeWeiht(index, p);
        break;
    }
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    int action = NULL_ACT;
    
    Points points1D ("./../../data_1d", 0);
    Points points2D ("./../../test", 1);

    while (action != QUIT)
    {
        printMenu();

        std::cin >> action;        
        handler(argc, argv, action, points1D, points2D);
    }

    return 0;
}
