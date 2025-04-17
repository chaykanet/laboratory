#include "edge.h"

Edge::Edge(const QPointF &A, const QPointF &B)
{
    _A = A;
    _B = B;
}

QPointF Edge::A() const { return _A; }
QPointF Edge::B() const { return _B; }
