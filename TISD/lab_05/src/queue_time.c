#include "queue_time.h"

#include "errcodes.h"

int make_n_avg_time(list_t *list, queue_t *queue, double *add_list, double *pop_list, double *add_queue, double *pop_queue, const size_t n)
{
    double sum_time_add_q = 0, sum_time_add_l = 0, sum_time_pop_q = 0, sum_time_pop_l = 0;
            
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
    {
        rc = make_n_time(list, queue, add_list, pop_list, add_queue, pop_queue, n);
        sum_time_add_l += *add_list;
        sum_time_pop_l += *pop_list;
        sum_time_add_q += *add_queue;
        sum_time_pop_q += *pop_queue;
    }

    *add_queue = sum_time_add_q / 100;
    *pop_queue = sum_time_pop_q / 100;

    *add_list = sum_time_add_l / 100;
    *pop_list = sum_time_pop_l / 100;

    return rc;
}

int add_n_int_queue(queue_t *queue, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = add_to_queue(queue, 1);

    return rc;
}

int pop_n_int_queue(queue_t *queue, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = pop_frm_queue(queue);

    return rc;
}

int add_n_int_list(list_t *list, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = add_to_list(list, create_node(1));

    return rc;
}

int pop_n_int_list(list_t *list, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = pop_frm_list(list);

    return rc;
}

int make_n_time(list_t *list, queue_t *queue, double *add_list, double *pop_list, double *add_queue, double *pop_queue, const size_t n)
{   
    double start, end;

    start = clock();
    add_n_int_queue(queue, n);
    end = clock();

    *add_queue = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    pop_n_int_queue(queue, n);
    end = clock();

    *pop_queue = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    add_n_int_list(list, n);
    end = clock();

    *add_list = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    pop_n_int_list(list, n);
    end = clock();

    *pop_list = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    return ERR_OK;
}