#ifndef MESSAGE_H
#define MESSAGE_H

#include "mainwindow.h"
#include "func_triangle.h"

void callInfoTriangle(MainWindow* ui, Triangle& triangle, QString& str);

void callErrorValue(MainWindow* ui);

void callErrorRange(MainWindow* ui);

void callErrorDerenerate(MainWindow* ui);

#endif // MESSAGE_H
