#include "stack.h"

// stack как массив.
int init_stack(stack_t *stack)
{   
    stack->massive = malloc(sizeof(char) * STAND_LEN);

    if (!stack->massive)
        return ERR_ALLOC;

    stack->phead = stack->massive - 1;
    stack->max_len = STAND_LEN;

    return ERR_OK;
}

void free_list(list_t *list)
{   
    if (list->phead == NULL)
        return;

    node_t *p = list->phead->prev;

    while (p != NULL)
    {   
        node_t *prev = p;
        p = p->prev;

        free(prev);
    }

    free(list->phead);

    free(list);

    free(p);
}

int init_list(list_t **list)
{
    node_t *head;
    
    *list = malloc(sizeof(list_t));

    head = malloc(sizeof(node_t));

    head->prev = NULL;
    head->symbol = '\0';

    (*list)->phead = head;

    return ERR_OK;
}

int add_tostack(stack_t *stack, char symbol)
{   
    if (stack->max_len > MAX_LEN)
        return ERR_OVERFLOW;

    if (stack->phead > stack->massive && stack->phead - stack->massive == (long int) stack->max_len - 1)
    {
        stack->max_len *= 2;

        if (stack->max_len > MAX_LEN)
            return ERR_OVERFLOW;
        
        stack->massive = realloc(stack->massive, stack->max_len * sizeof(char));

        if (!stack->massive)
            return ERR_ALLOC;
    }

    stack->phead++;

    *stack->phead = symbol;
    
    return ERR_OK;  
}

int pop_frmstack(stack_t *stack)
{
    if (stack->phead == stack->massive - 1)
        return ERR_EMPTY;

    stack->phead--;

    return ERR_OK;
}

int take_frmstack(stack_t *stack, char *taken)
{   
    int rc = ERR_OK;

    if (stack->phead == stack->massive - 1)
        return ERR_EMPTY;

    *taken = *stack->phead;

    rc = pop_frmstack(stack);

    return rc;
}

// stack как список.

int add_tolist(list_t *head, char const symbol)
{
    node_t *next = malloc(sizeof(node_t));

    if (!next)
        return ERR_ALLOC;

    next->prev = head->phead;
    next->symbol = symbol;

    head->phead = next;

    return ERR_OK;
}

int add_tolist_adr(list_t *head, char const symbol, void **ad)
{
    node_t *next = malloc(sizeof(node_t));

    if (!next)
        return ERR_ALLOC;
    
    *ad = (void *) next;

    next->prev = head->phead;
    next->symbol = symbol;

    head->phead = next;

    return ERR_OK;
}

int pop_frmlist(list_t *head)
{   
    if (head->phead == NULL)
    {   
        return ERR_EMPTY;
    }

    node_t *p = head->phead;

    head->phead = p->prev;
    
    if (p)
        free(p);

    return ERR_OK;
}

int pop_frmlist_adr(list_t *head, void **adr)
{   
    if (head->phead == NULL)
    {   
        return ERR_EMPTY;
    }

    node_t *p = head->phead;

    head->phead = p->prev;

    *adr = (void *) p;

    if (p)
        free(p);

    return ERR_OK;
}

int take_frmlist(list_t *head, char *taken)
{
    if (head->phead == NULL)
    {   
        return ERR_EMPTY;
    }

    *taken = head->phead->symbol;
    
    pop_frmlist(head);

    if (head->phead == NULL)
    {   
        return ERR_EMPTY;
    }

    return ERR_OK;
}
