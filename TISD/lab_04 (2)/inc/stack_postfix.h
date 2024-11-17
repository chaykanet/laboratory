#ifndef STACK_POSTFIX_H
#define STACK_POSTFIX_H

#include <string.h>
#include <stdbool.h>

#include "stack.h"
#include "errcodes.h"
#include "stack_io.h"

#define OPERATORS "+-*/^"
#define OPERATORSBRACKETS "()+-*/^"
#define NUMS "1234567890"

int check_expression(char *expression);

int convert_topostfix_stack(char *postfix, char *expression, stack_t *stack_store);

int convert_topostfix_list(char *postfix, char *expression, list_t *list_store);

#endif
