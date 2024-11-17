#ifndef STACK_IO_H
#define STACK_IO_H

#include <stdio.h>
#include "stack.h"
#include "stack_io.h"

void print_stack(stack_t *stack);

void print_list(list_t *head);

void print_adr(char **adr, size_t const n);

#endif
