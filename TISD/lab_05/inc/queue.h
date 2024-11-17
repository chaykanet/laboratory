#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_LEN 10000

typedef struct queue
{   
    double massive[MAX_QUEUE_LEN];

    int pout;

    int pin;

} queue_t;

typedef struct node
{
    double value;

    struct node *prev;

    struct node *pnext;
    
} node_t;

typedef struct list
{
    node_t *pin;

    node_t *pout;

} list_t;


int init_queue(queue_t *queue);

int add_to_queue(queue_t *queue, const double value);

int pop_frm_queue(queue_t *queue);

int take_frm_queue(queue_t *queue, double *taken);

// Списки.

int init_list(list_t *list);

void free_list(list_t *list);

int calc_len_list(list_t *list);

int add_to_list(list_t *list, const node_t *node);

int pop_frm_list(list_t *list);

int take_frm_list(list_t *list, double *taken);

int pop_frm_list_adress(list_t *list, void **adress);

node_t *create_node(const double value);

#endif
