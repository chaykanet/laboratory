#include "calctime.h"

#include <chrono>

#include <QPainter>
#include <QMainWindow>

inline void renderingDDA(QPainter &p, int x1, int y1, int x2, int y2);

inline void renderingWu(QImage &image, int x1, int y1, int x2, int y2);

inline void renderingBresenham(QPainter &p, int x1, int y1, int x2, int y2);

inline void renderingBresenhamUnStep(QImage &image, int x1, int y1, int x2, int y2);

inline void renderingBresenhamDouble(QPainter &p, double x1, double y1, double x2, double y2);


calcTime::calcTime() {}

