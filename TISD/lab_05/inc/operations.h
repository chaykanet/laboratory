#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "errcodes.h"

#define EPS 1e-7

int init_avg_queue(queue_t *queue, const size_t n, const double t1, const double t2);

int init_random_queue(queue_t *queue, const size_t n, const double t1, const double t2);

int process_modeling_list(double *complete_time, double *down_time, double *avg_time_queue, double po, double oa1t1, double oa1t2, double oa2t1, double oa2t2);

int process_modeling_queue(double *complete_time, double *down_time, double *avg_time_queue, double po, double oa1t1, double oa1t2, double oa2t1, double oa2t2);

int process_modeling_queue_avg(double *complete_time, double *down_time, double *avg_time_queue, double po, double oa1t1, double oa1t2, double oa2t1, double oa2t2);

#endif
