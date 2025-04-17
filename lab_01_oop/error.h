#ifndef ERROR_H
#define ERROR_H

#include <QMessageBox>

enum errors
{
    ERR_OK,
    ERR_MEM_BUSY,
    ERR_INPUT_DATA,
    ERR_ALLOCATION,
    ERR_DRAW_SCENE,
    ERR_RANGE_INDEXES,
    ERR_NULLPTR_ARRAY,
    ERR_INITIALIZATION,
    ERR_DEFINED_COMMAND,
};

typedef enum errors myerror_t;

void error_message(myerror_t &err);

#endif // ERROR_H
