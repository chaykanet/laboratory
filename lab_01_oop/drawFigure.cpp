#include "drawFigure.h"

myerror_t clearScene(figureScene_t& figureScene)
{
    myerror_t rc = ERR_OK;

    QGraphicsScene *scene = figureScene.scene;

    if (!scene)
    {
        rc = ERR_DRAW_SCENE;
    }
    else
    {
        scene->clear();
    }

    return rc;
}

void centerPoint(point_t &point, const figureScene_t &figureScene)
{
    point.x += figureScene.width / 2;
    point.y += figureScene.height / 2;
}

static myerror_t checkFigure(const points_t &points, const edges_t &edges)
{
    myerror_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < edges.len; ++i)
    {
        size_t indexA, indexB;
        indexesEdge(indexA, indexB, edges.arr[i]);

        if (indexA >= points.len || indexB >= points.len)
            rc = ERR_RANGE_INDEXES;
    }

    return rc;
}

myerror_t drawFigure(figureScene_t& figureScene, const figure_t &figure)
{
    myerror_t rc = ERR_OK;

    rc = clearScene(figureScene);

    if (rc == ERR_OK)
    {
        rc = checkFigure(figure.points, figure.edges);

        if (rc == ERR_OK)
            rc = drawLines(figureScene, figure.points, figure.edges);
    }

    return rc;
}

myerror_t drawLines(figureScene_t &figureScene, const points_t& points, const edges_t& edges)
{
    myerror_t rc = ERR_OK;

    if (!points.arr || !edges.arr)
    {
        rc = ERR_ALLOCATION;
    }
    else
    {
        for (size_t i = 0; rc == ERR_OK && i < edges.len; ++i)
        {
            rc = checkLine(points.arr, points.len, edges.arr[i]);

            if (rc == ERR_OK)
            {
                line_t line = formLine(points.arr, points.len, edges.arr[i]);
                rc = drawLine(figureScene, line);
            }
        }
    }

    return rc;
}

myerror_t drawOnScene(figureScene_t &figureScene, const point_t& pointA, const point_t& pointB)
{
    myerror_t rc = ERR_OK;

    if (!figureScene.scene)
    {
        rc = ERR_DRAW_SCENE;
    }
    else
    {
        figureScene.scene->addLine(pointA.x, pointA.y, pointB.x, pointB.y);
    }

    return rc;
}

myerror_t drawLine(figureScene_t &figureScene, const line_t &line)
{
    myerror_t rc = ERR_OK;

    if (!figureScene.scene)
    {
        rc = ERR_DRAW_SCENE;
    }
    else
    {
        point_t pointA = line.pointA;
        point_t pointB = line.pointB;

        centerPoint(pointA, figureScene);
        centerPoint(pointB, figureScene);

        drawOnScene(figureScene, pointA, pointB);
    }

    return rc;
}

myerror_t checkLine(const point_t *points, const size_t len, const edge_t &edge)
{
    myerror_t rc = ERR_OK;

    if (edge.indexA >= len || edge.indexB >= len)
    {
        rc = ERR_RANGE_INDEXES;
    }
    else if (!points)
    {
        rc = ERR_NULLPTR_ARRAY;
    }

    return rc;
}

line_t formLine(const point_t *points, const size_t len, const edge_t &edge)
{
    line_t line;
    if (points && edge.indexA < len && edge.indexB < len)
    {
        line.pointA = points[edge.indexA];
        line.pointB = points[edge.indexB];
    }

    return line;
}
