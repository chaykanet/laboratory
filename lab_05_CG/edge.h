#ifndef EDGE_H
#define EDGE_H

#include <QPointF>

class Edge
{
    QPointF _A;
    QPointF _B;

public:
    explicit Edge(){};
    explicit Edge(const QPointF &A, const QPointF &B);

    QPointF A() const;
    QPointF B() const;
};

using listEdges = QList<Edge>;

#endif // EDGE_H
