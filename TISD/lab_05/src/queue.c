#include <stdio.h>

#include "queue.h"
#include "errcodes.h"

int init_queue(queue_t *queue)
{   
    if (queue)
    {
        queue->pin = -1;
        queue->pout = -1;
    }
    else return ERR_INIT;

    return ERR_OK;
}

int add_to_queue(queue_t *queue, const double value)
{
    if (queue->pin + 1 == queue->pout || (queue->pin == MAX_QUEUE_LEN - 1 && queue->pout == 0))
        return ERR_OVERFLOW;
    
    if (queue->pin == MAX_QUEUE_LEN - 1)
    {
        queue->pin = 0;
    }

    if (queue->pout == -1)
        queue->pout++;

    ++queue->pin;

    queue->massive[queue->pin] = value;
   
    return ERR_OK;
}

int pop_frm_queue(queue_t *queue)
{   
    if (queue->pin == -1 && queue->pout == -1)
        return ERR_EMPTY;

    if (queue->pin == queue->pout)
    {
        queue->pin = -1;
        queue->pout = -1;

        return ERR_OK;
    }

    if (queue->pout == MAX_QUEUE_LEN - 1)
    {
        queue->pout = 0;
    }
    else
        queue->pout++;

    return ERR_OK;
}

int take_frm_queue(queue_t *queue, double *taken)
{
    if (queue->pout == -1  && queue->pin == -1)
            return ERR_EMPTY;
    
    *taken = queue->massive[queue->pout];

    return pop_frm_queue(queue); 
}

// Списки.

int init_list(list_t *list)
{   
    if (!list)
        return ERR_INIT;

    list->pin = NULL;
    list->pout = NULL;

    return ERR_OK;
}

int add_to_list(list_t *list, const node_t *node)
{
    if (!list)
        return ERR_OPERATION;

    if (list->pin)
    {

        list->pin->prev = (node_t *) node;

        list->pin = (node_t *) node;
    }
    else
    {
        list->pin = (node_t *) node;
        list->pout = (node_t *) node;
    }

    return ERR_OK;
}

int pop_frm_list(list_t *list)
{
    if (!list)
        return ERR_OPERATION;

    if (list->pout && list->pout != list->pin)
    {   
        node_t *p = list->pout->prev;

        free(list->pout);

        list->pout = p; 
    }
    else if (list->pout && list->pout == list->pin)
    {   
        free(list->pout);

        list->pout = NULL;
        list->pin = NULL;
    }
    else return ERR_EMPTY;

    return ERR_OK;
}

int pop_frm_list_adress(list_t *list, void **adress)
{
    if (!list)
        return ERR_OPERATION;

    if (list->pout && list->pout != list->pin)
    {   
        node_t *p = list->pout->prev;

        *adress = (void *) list->pout;

        // memset(p, 0, sizeof(node_t));

        free(list->pout);

        list->pout = p; 
    }
    else if (list->pout && list->pout == list->pin)
    {   
        *adress = (void *) list->pout;

        // memset(list->pout, 0, sizeof(node_t));

        free(list->pout);

        list->pout = NULL;
        list->pin = NULL;
    }
    else return ERR_EMPTY;

    return ERR_OK;
}

int take_frm_list(list_t *list, double *taken)
{
    if (list->pout)
    {
        *taken = list->pout->value;

        return pop_frm_list(list);
    }
    
    return ERR_EMPTY; 
}

void free_list(list_t *list)
{
    if (list && list->pout)
    {   
        node_t *p = list->pout;

        while (p->prev != NULL)
        {
            list->pout = p->prev;

            free(p);

            p = list->pout;
        }

        free(p);
    }
}

node_t *create_node(const double value)
{   
    if (value < 0)
        return NULL;

    node_t *ptr = malloc(sizeof(node_t));

    if (ptr)
    {
        ptr->value = value;
        ptr->prev = NULL;
    }

    return ptr;
}

int calc_len_list(list_t *list)
{
    node_t *p = list->pout;

    size_t c = 0;

    while (p)
    {
        c++;
        p = p->prev;
    }

    return c;
}
