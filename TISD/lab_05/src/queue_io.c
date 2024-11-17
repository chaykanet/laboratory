#include "queue_io.h"

void print_queue(queue_t *queue)
{
    printf("Очередь массив: { ");

    if (queue->pin == -1 && queue->pout == -1)
    {
        printf("}\n");
        return;
    }

    queue_t tmp;

    init_queue(&tmp);

    double taken;

    while (take_frm_queue(queue, &taken) == ERR_OK)
    {   
        add_to_queue(&tmp, taken);
        printf("%lf ", taken);
    }

    while (take_frm_queue(&tmp, &taken) == ERR_OK)
    {   
        add_to_queue(queue, taken);
    }

    printf("}\n");
}

void print_list(list_t *list)
{
    printf("Очередь список: { ");

    node_t *p = list->pout;

    while (p)
    {
        printf("%lf : %p, ", p->value, (void *) p);
        p = p->prev;
    }

    printf("}\n");
}
