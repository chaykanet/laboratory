#include "figure.h"
#include "handler.h"

myerror_t handler(userRequest_t &request)
{
    myerror_t rc = ERR_OK;

    static figure_t figure = initFigure();

    switch (request.action) {
    case ACTION_DRAW_FIGURE:
        rc = drawFigure(request.scene, figure);
        break;
    case ACTION_LOAD_FIGURE:
        rc = downloadFigure(figure, request.filename);
        break;
    case ACTION_MOVE_FIGURE:
        rc = moveFigure(figure, request.vector);
        break;
    case ACTION_SCALE_FIGURE:
        rc = scaleFigure(figure, request.scale);
        break;
    case ACTION_ROTATE_FIGURE:
        rc = rotateFigure(figure, request.rotate);
        break;
    case QUIT:
        freeFigure(figure);
        break;
    default:
        rc = ERR_DEFINED_COMMAND;
        break;
    }

    return rc;
}
