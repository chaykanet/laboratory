#ifndef __QUEUE_TIME_H__
#define __QUEUE_TIME_H__

#include <time.h>
#include "queue.h"
#include "errcodes.h"

int add_n_int_queue(queue_t *queue, size_t const n);

int pop_n_int_queue(queue_t *queue, size_t const n);

int add_n_int_list(list_t *list, size_t const n);

int pop_n_int_list(list_t *list, size_t const n);

int make_n_time(list_t *list, queue_t *queue, double *add_list, double *pop_list, double *add_queue, double *pop_queue, const size_t n);

#endif