#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errcodes.h"

#define MAX_LEN 1000
#define STAND_LEN 100

typedef struct stack_massive
{
    char *massive;

    char *phead;

    size_t max_len;

} stack_t;

typedef struct node // список.
{
    struct node *prev;

    char symbol;

} node_t;

typedef struct list
{
    node_t *phead;

} list_t;

int init_stack(stack_t *stack);

int init_list(list_t **list);

void free_list(list_t *list);

int add_tostack(stack_t *stack, char symbol);

int pop_frmstack(stack_t *stack);

int take_frmstack(stack_t *stack, char *taken);

int add_tolist(list_t *head, char const symbol);

int add_tolist_adr(list_t *head, char const symbol, void **ad);

int pop_frmlist(list_t *head);

int pop_frmlist_adr(list_t *head, void **adr);

int take_frmlist(list_t *head, char *taken);

#endif
