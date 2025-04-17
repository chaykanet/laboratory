#ifndef COLORS_H
#define COLORS_H

#include <QColor>

class Colors
{
public:
    Qt::GlobalColor qclr;
    Colors() {};
    Colors(int clr);
    int r, g, b;
    ~Colors() {};
};

#endif // COLORS_H
