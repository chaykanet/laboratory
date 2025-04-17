#include "message.h"

void callInfoTriangle(MainWindow* ui, Triangle& triangle, QString& str)
{
    QString xA = QString::number(triangle.A.x());
    QString yA = QString::number(triangle.A.y());
    QString xB = QString::number(triangle.B.x());
    QString yB = QString::number(triangle.B.y());
    QString xC = QString::number(triangle.C.x());
    QString yC = QString::number(triangle.C.y());

    QString xH = QString::number(triangle.height.second.x());
    QString yH = QString::number(triangle.height.second.y());
    QString xM = QString::number(triangle.median.second.x());
    QString yM = QString::number(triangle.median.second.y());

    QString angel = QString::number(triangle.angel);

    QString Answer = QString("Треугольник успешно построен.\n A(%1, %2);\n B(%3, %4);\n C(%5, %6);\n Координаты вершины высоты H(%7, %8);\n Координаты вершины медианы M(%9, %10);\n Угол меджду медианой и высотой (рад.): %11").arg(xA).arg(yA).arg(xB).arg(yB).arg(xC).arg(yC).arg(xH).arg(yH).arg(xM).arg(yM).arg(angel);
    str = Answer;
    QMessageBox::information(ui, "Ответ", Answer);
}


void callErrorValue(MainWindow* ui)
{
    QMessageBox::critical(ui, "Ошибка", "Недопустимый ввод значений.");
}

void callErrorRange(MainWindow* ui)
{
    QMessageBox::critical(ui, "Ошибка", "Недостаточно точек для построения треугольника.");
}

void callErrorDerenerate(MainWindow* ui)
{
    QMessageBox::critical(ui, "Ошибка", "Все треугольники вырождены.");
}
