#include "input.h"

#include <fstream>

#include "error.h"
#include "figure.h"

myerror_t dowlandFigure(Figure &figure, const char *filename)
{
    myerror_t rc = ERR_OK;
    std::ifstream fin(filename);

    if (!fin)
    {
        rc = ERR_INPUT_DATA;
    } else
    {
        QList<QPointF> points;
        Edges_t edges;
        int lenPoints, lenEdges;

        fin >> lenPoints;
        if (lenPoints < 0)
        {
            rc = ERR_INVALID_DATA;
            fin.close();
            return rc;
        }

        for (int i = 0; i < lenPoints; ++i)
        {
            qreal x, y;
            fin >> x >> y;
            points.append(QPointF(x, y));
        }

        if (rc == ERR_OK)
        {
            fin >> lenEdges;
            if (lenEdges < 0)
            {
                rc = ERR_INVALID_DATA;
            }
            else
            {
                for (int i = 0; i < lenEdges; ++i)
                {
                    size_t indexA, indexB;
                    fin >> indexA >> indexB;

                    edges.append(std::make_pair(indexA, indexB));
                }
            }
        }

        fin.close();

        if (rc == ERR_OK)
        {
            figure.setPoints(points);
            figure.setEdges(edges);
        }
    }

    return rc;
}

myerror_t dowlandEllipse(Ellipse &ellipse, const char *filename)
{
    myerror_t rc = ERR_OK;
    std::ifstream fin(filename);

    if (!fin)
    {
        rc = ERR_INPUT_DATA;
    }
    else
    {
        qreal x, y, a, b;

        if (!(fin >> x >> y))
        {
            rc = ERR_INPUT_DATA;
        }


        if (!(fin >> a >> b))
        {
            rc = ERR_INPUT_DATA;
        }

        fin.close();

        if (rc == ERR_OK)
        {
            QPointF center = QPointF(x, y);
            ellipse = Ellipse(center, 0, a, b);
        }
    }

    return rc;
}
