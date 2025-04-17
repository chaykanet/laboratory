#include "figure.h"

void freeFigure(figure_t &figure)
{
    freeEdges(figure.edges);
    freePoints(figure.points);
}

void defaultFigure(figure_t &figure)
{
    defaultPoint(figure.center);
    defaultPoints(figure.points);
    defaultEdges(figure.edges);
}

figure_t &initFigure()
{
    static figure_t figure;
    defaultFigure(figure);
    return figure;
}

myerror_t downloadFigure(figure_t &figure, const char *filename)
{
    myerror_t rc = ERR_OK;
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        rc = ERR_INPUT_DATA;
    }
    else
    {
        rc = freadFigure(figure, file);
        fclose(file);
    }

    return rc;
}

static myerror_t tryFreadFigure(figure_t &figure, FILE *file)
{
    myerror_t rc = freadPoints(figure.points, file);

    if (rc == ERR_OK)
    {
        rc = freadEdges(figure.edges, file);
    }
    else
    {
        freePoints(figure.points);
    }

    return rc;
}

myerror_t freadFigure(figure_t &figure, FILE *file)
{
    myerror_t rc = ERR_OK;

    if (!file)
    {
        rc = ERR_INPUT_DATA;
    }
    else
    {
        figure_t temp;
        rc = tryFreadFigure(temp, file);

        if (rc == ERR_OK)
        {
            freeFigure(figure);
            figure = temp;
        }
    }

    return rc;
}

myerror_t moveFigure(figure_t &figure, const vec_t &vector)
{
    movePoint(figure.center, vector);

    return movePoints(figure.points, vector);
}

myerror_t scaleFigure(figure_t &figure, const scale_t &scale)
{
    return scalePoints(figure.points, figure.center, scale);
}

myerror_t rotateFigure(figure_t &figure, const rotate_t &rotate)
{
    return rotatePoints(figure.points, figure.center, rotate);
}
