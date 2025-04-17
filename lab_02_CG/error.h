#ifndef ERROR_H
#define ERROR_H

#include <QMessageBox>

enum errors
{
    ERR_OK,
    ERR_INPUT_DATA,
    ERR_ALLOCATION,
    ERR_DRAW_SCENE,
    ERR_INVALID_DATA,
    ERR_EMPTY_FIGURE,
    ERR_RANGE_INDEXES,
    ERR_INITIALIZATION,
    ERR_DEFINED_COMMAND,
    ERR_DEGENERATE_FIGURE
};

typedef enum errors myerror_t;

void error_message(myerror_t &err);

#endif // ERROR_H
