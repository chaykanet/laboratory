#ifndef HANDLER_H
#define HANDLER_H

#include "error.h"

#include "actions.h"
#include "drawFigure.h"

enum action_t
{
    ACTION_LOAD_FIGURE,
    ACTION_DRAW_FIGURE,
    ACTION_MOVE_FIGURE,
    ACTION_SCALE_FIGURE,
    ACTION_ROTATE_FIGURE,
    QUIT
};

typedef enum action_t action_t;

typedef struct userRequest_t userRequest_t;

struct userRequest_t
{
    action_t action;

    char *filename;
    vec_t vector;
    scale_t scale;
    rotate_t rotate;
    figureScene_t scene;
};

myerror_t handler(userRequest_t &request);

#endif // HANDLER_H
