#include "colors.h"

Colors::Colors(int clr)
{
    switch (clr)
    {
    case 7:
        r = 255;
        g = 0;
        b = 0;
        qclr = Qt::GlobalColor::red;
        break;
    case 8:
    {
        r = 0;
        g = 255;
        b = 0;
        qclr = Qt::GlobalColor::green;
        break;
    }
    case 9:
    {
        r = 0;
        g = 0;
        b = 255;
        qclr = Qt::GlobalColor::blue;
        break;
    }
    case 2:
    {
        r = 0;
        g = 0;
        b = 0;
        qclr = Qt::GlobalColor::black;
        break;
    }
    case 3:
    {
        r = 255;
        g = 255;
        b = 255;
        qclr = Qt::GlobalColor::white;
        break;
    }
    }
}
