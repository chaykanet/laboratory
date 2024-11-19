#include "math.h"

#include "operations.h"
#include "queue_io.h"

int init_random_queue(queue_t *queue, const size_t n, const double t1, const double t2)
{   
    srand(123);
    int rc = ERR_OK;

    rc = init_queue(queue);

    for (size_t i = 0; i < n && rc == ERR_OK; i++)
    {
        double rand_time = ((double)rand() / RAND_MAX) * (t2 - t1) + t1;

        // rand_time = (6.0 - 0.0) * rand_time + 0.0;
        rc = add_to_queue(queue, rand_time);
    }

    return rc;
}

int init_avg_queue(queue_t *queue, const size_t n, const double t1, const double t2)
{   
    srand(123);
    int rc = ERR_OK;

    rc = init_queue(queue);

    for (size_t i = 0; i < n && rc == ERR_OK; i++)
    {
        double rand_time = (t2 +t1) / 2;

        rc = add_to_queue(queue, rand_time);
    }

    return rc;
}

int init_avg_list(list_t *list, const size_t n, const double t1, const double t2)
{   
    int rc = ERR_OK;

    rc = init_list(list);

    for (size_t i = 0; i < n && rc == ERR_OK; i++)
    {
        double rand_time = (t1 + t2) / 2;

        node_t *node = create_node(rand_time);

        // rand_time = (6.0 - 0.0) * rand_time + 0.0;
        rc = add_to_list(list, node);
    }

    return rc;
}

int init_random_list(list_t *list, const size_t n, const double t1, const double t2)
{
    int rc = ERR_OK;

    rc = init_list(list);

    for (size_t i = 0; i < n && rc == ERR_OK; i++)
    {
         double rand_time = ((double)rand() / RAND_MAX) * (t2 - t1) + t1;

        node_t *node = create_node(rand_time);

        rc = add_to_list(list, node);
    }

    return rc;
}

// int calc_avg_list(queue_t *list, double *time_avg)
// {
//     double sum = 0;

//     int clc = 0;

//     node_t *pcur = list->pout;

//     while (pcur && pcur != list->pin)
//     {
//         sum += pcur->value;
//         clc++;
//         pcur = pcur->prev;
//     }
    
//     if (pcur)
//     {
//         sum += pcur->value;
//         clc++;
//     }

//     if (clc)
//         *time_avg = sum / clc;
//     else
//         *time_avg = 0;

//     return ERR_OK;
// }

size_t calc_len(list_t *list)
{
    size_t c = 0;

    node_t *p = list->pout;

    if (!p)
        return 0;

    while (p)
    {
        p = p->prev;
        c++;
    }

    return ++c;
}

int process_modeling_queue(double *complete_time, double *down_time, double *avg_time_queue, double po, double oa1t1, double oa1t2, double oa2t1, double oa2t2, double *avg_len_OA1, double *avg_len_OA2)
{   
    int rc_1 = ERR_OK;
    int rc_2 = ERR_OK;

    queue_t OA1;
    queue_t OA2;

    size_t calc_OA1 = 0;
    size_t calc_OA2 = 0;

    size_t calc_OA = 0;

    rc_1 = init_random_queue(&OA1, 100, oa1t1, oa1t2);

    if (rc_1 != ERR_OK)
        return rc_1;

    rc_2 = init_queue(&OA2);


    if (rc_2 != ERR_OK)
        return rc_1;
    
    rc_2 = ERR_EMPTY;

    double time_OA1 = 0;
    double time_OA2 = 0;

    double down = 0;

    double t1 = 0;
    double t2 = 0;

    double p = 0;

    double time1 = 0;
    double time2 = 0; 
    int taken = 0;

    size_t prev = 1000;

    size_t sum_len_OA1 = 0;
    size_t sum_len_OA2 = 0;

    size_t max_len_1 = 0;
    size_t max_len_2 = 0;

    size_t min_len_1 = 10000;
    size_t min_len_2 = 10000;

    while (calc_OA2 < 1000)
    {   
        sum_len_OA1 = (size_t) abs(OA1.pin - OA1.pout) + 1;
        sum_len_OA2 = (size_t) abs(OA2.pin - OA2.pout) + 1;
        max_len_1 = max_len_1 < sum_len_OA1 ? sum_len_OA1 : max_len_1;
        max_len_2 = max_len_2 < sum_len_OA1 ? sum_len_OA1 : max_len_2;
        
        min_len_1 = min_len_1 > sum_len_OA1 ? sum_len_OA1 : min_len_1;
        min_len_2 = min_len_2 > sum_len_OA2 ? sum_len_OA2 : min_len_2;

        if (rc_2 == ERR_OK)
        {   
            t1 = ((double)rand() / RAND_MAX) * (oa1t2 - oa1t1) + oa1t1; 
            calc_OA2++;
            rc_1 = add_to_queue(&OA1, t1); // ???
        }

        if (calc_OA2 && calc_OA2 % 100 == 0 && calc_OA2 != prev)
        {   
            prev = calc_OA2;
            // printf("AO1: %lu\n", calc_OA1);
            // printf("AO2: %lu\n", calc_OA2);
            // printf("\n");
            sum_len_OA1 += abs(OA1.pin - OA1.pout) + 1;
            sum_len_OA2 += abs(OA2.pin - OA2.pout) + 1;

            printf("%lu:\n", calc_OA2);
            printf("Длина OA1: %d\n", abs(OA1.pin - OA1.pout) + 1);
            printf("Длина OA2: %d\n", abs(OA2.pin - OA2.pout) + 1);  
        }
        
        if (calc_OA2 == 1000)
            break;

        while (time1 <= time2  && rc_1 == ERR_OK)
        {   
            rc_1 = take_frm_queue(&OA1, &t1);

            if (rc_1 == ERR_OK)
            {
                time1 += t1;

                time_OA1 += t1;

                calc_OA++;

                //p = ((double)rand() / RAND_MAX) * 1.0;
                taken++;
            }
        }
        // printf("DEBUG:%lu \n", calc_OA);
        
        if (fabs(time2) < EPS)
        {   
            down += time1;
            
            time1 = 0;
        }
        else if (time1 >= time2)
        {
            time1 -= time2;
            
            if (OA2.pin == -1 && OA2.pout == -1)
                down += time1;
        }

        time_OA2 += time2;

        rc_2 = take_frm_queue(&OA2, &time2); // сделать счетчик тайкен ++ в иф до n - 1. ну пон.

        for (int i = taken; i > 0; i--)
        {   
            p = ((double)rand() / RAND_MAX) * 1.0;
            
            if (taken && p <= po)
            {   
                calc_OA1++;

                t2 = ((double)rand() / RAND_MAX) * (oa2t2 - oa2t1) + oa2t1;

                add_to_queue(&OA2, t2);

                taken--;
            }
            else if (taken)
            {   
                t1 = ((double)rand() / RAND_MAX) * (oa1t2 - oa1t1) + oa1t1;

                rc_1 = add_to_queue(&OA1, t1);

                taken--;
            }
        }

        if (rc_2 == ERR_EMPTY)
            time2 = 0;
    }
    
    if (calc_OA2 == 1000)
    {   
        *avg_len_OA1 = (max_len_1 + min_len_1) / 2;
        *avg_len_OA2 = (max_len_2 + max_len_2) / 2;
        *complete_time = time_OA2 + down / 2;
        *down_time = down / 2;
        *avg_time_queue = (time_OA1 / calc_OA + time_OA2 / calc_OA2) / 2;
    }

    return ERR_OK;    
}

int process_modeling_queue_avg(double *complete_time, double *down_time, double *avg_time_queue, double po, double oa1t1, double oa1t2, double oa2t1, double oa2t2, double *avg_len_OA1, double *avg_len_OA2)
{   
    int rc_1 = ERR_OK;
    int rc_2 = ERR_OK;

    queue_t OA1;
    queue_t OA2;

    size_t calc_OA1 = 0;
    size_t calc_OA2 = 0;

    size_t calc_OA = 0;

    rc_1 = init_avg_queue(&OA1, 100, oa1t1, oa1t2);

    if (rc_1 != ERR_OK)
        return rc_1;

    rc_2 = init_queue(&OA2);

    if (rc_2 != ERR_OK)
        return rc_1;
    
    rc_2 = ERR_EMPTY;

    double time_OA1 = 0;
    double time_OA2 = 0;

    double down = 0;

    double t1 = 0;
    double t2 = 0;

    double p = 0;

    double time1 = 0;
    double time2 = 0;

    int taken = 0;

    size_t prev = 1000;

    size_t sum_len_OA1 = 0;
    size_t sum_len_OA2 = 0;

    size_t max_len_1 = 0;
    size_t max_len_2 = 0;

    size_t min_len_1 = 10000;
    size_t min_len_2 = 10000;

    while (calc_OA2 < 1000)
    {   

        sum_len_OA1 = (size_t) abs(OA1.pin - OA1.pout) + 1;
        sum_len_OA2 = (size_t) abs(OA2.pin - OA2.pout) + 1;
        max_len_1 = max_len_1 < sum_len_OA1 ? sum_len_OA1 : max_len_1;
        max_len_2 = max_len_2 < sum_len_OA1 ? sum_len_OA1 : max_len_2;

        min_len_1 = min_len_1 > sum_len_OA1 ? sum_len_OA1 : min_len_1;
        min_len_2 = min_len_2 > sum_len_OA2 ? sum_len_OA2 : min_len_2;
        
        if (rc_2 == ERR_OK)
        {   
            t1 = (oa1t2 + oa1t1) / 2;
            calc_OA2++;
            rc_1 = add_to_queue(&OA1, t1); // ???
        }

        if (calc_OA2 && calc_OA2 % 100 == 0 && calc_OA2 != prev)
        {   
            prev = calc_OA2;
            // printf("AO1: %lu\n", calc_OA1);
            // printf("AO2: %lu\n", calc_OA2);
            // printf("\n");
            sum_len_OA1 += abs(OA1.pin - OA1.pout) + 1;

            sum_len_OA2 += abs(OA2.pin - OA2.pout) + 1;

            printf("%lu:\n", calc_OA2);
            printf("Длина OA1: %d\n", abs(OA1.pin - OA1.pout) + 1);
            printf("Длина OA2: %d\n", abs(OA2.pin - OA2.pout) + 1);  
        }
        
        if (calc_OA2 == 1000)
            break;

        while (time1 <= time2  && rc_1 == ERR_OK)
        {   
            rc_1 = take_frm_queue(&OA1, &t1);

            if (rc_1 == ERR_OK)
            {
                time1 += t1;

                time_OA1 += t1;

                calc_OA++;
                
                taken++;
            }
        }
        // printf("DEBUG:%lu \n", calc_OA);
        
        if (fabs(time2) < EPS)
        {   
            down += time1;
            
            time1 = 0;
        }
        else if (time1 >= time2)
        {
            time1 -= time2;
            
            if (OA2.pin == -1 && OA2.pout == -1)
                down += time1;
        }

        time_OA2 += time2;
        
        rc_2 = take_frm_queue(&OA2, &time2);

        for (int i = taken; i > 1; i--)
        {   
            p = ((double)rand() / RAND_MAX) * 1.0;

            if (taken && p <= po)
            {   
                calc_OA1++;
                
                t2 = (oa2t2 + oa2t1) / 2;

                add_to_queue(&OA2, t2);

                taken--;            
            }
            else if (taken)
            {   
                t1 = (oa1t2 + oa1t1) / 2;

                rc_1 = add_to_queue(&OA1, t1);
                taken--;
            }
        } 

        if (rc_2 == ERR_EMPTY)
            time2 = 0;
    }
    
    if (calc_OA2 == 1000)
    {   
        // printf("DEBUG %lf\n", down / 2);
        // printf("DEBUG %lf\n", time_OA2 + down / 2);
        *avg_len_OA1 = (max_len_1 + min_len_1) / 2;
        *avg_len_OA2 = (max_len_2 + min_len_2) / 2;
        printf("DEBUG %lf \n", down / 2);
        *complete_time = time_OA2 + down / 2;
        *down_time = down / 2;
        *avg_time_queue = (time_OA1 / calc_OA + time_OA2 / calc_OA2) / 2;
    }

    return ERR_OK;    
}

int process_modeling_list(double *complete_time, double *down_time, double *avg_time_queue, double po, double oa1t1, double oa1t2, double oa2t1, double oa2t2, double *avg_len_OA1, double *avg_len_OA2)
{   
    int rc_1 = ERR_OK;
    int rc_2 = ERR_OK;

    list_t OA1;
    list_t OA2;

    size_t calc_OA1 = 0;
    size_t calc_OA2 = 0;

    size_t calc_OA = 0;

    rc_1 = init_random_list(&OA1, 100, 1 , 2);

    if (rc_1 != ERR_OK)
        return rc_1;

    rc_2 = init_list(&OA2);
    
    double time_OA1 = 0;
    double time_OA2 = 0;

    double down = 0;

    double t1 = 0;
    double t2 = 0;

    double p = 0;

    double time1 = 0;
    double time2 = 0; 

    node_t *node;

    int taken = 0;

    size_t sum_len_OA1 = 0;
    size_t sum_len_OA2 = 0;

    size_t max_len_1 = 0;
    size_t max_len_2 = 0;

    size_t min_len_1 = 0;
    size_t min_len_2 = 0;

    size_t prev = 1000;

    while (calc_OA2 < 1000)
    {   
        sum_len_OA1 = calc_len_list(&OA1) + 1;
        sum_len_OA2 = calc_len_list(&OA2) + 1;
        max_len_1 = max_len_1 < sum_len_OA1 ? sum_len_OA1 : max_len_1;
        max_len_2 = max_len_2 < sum_len_OA1 ? sum_len_OA1 : max_len_2;
        
        min_len_1 = min_len_1 > sum_len_OA1 ? sum_len_OA1 : min_len_1;
        min_len_2 = min_len_2 > sum_len_OA2 ? sum_len_OA2 : min_len_2;

        if (rc_2 == ERR_OK)
        {   
            t1 = ((double)rand() / RAND_MAX) * (oa1t2 - oa1t1) + oa1t1; 
            calc_OA2++;
            node_t *node = create_node(t1);
            rc_1 = add_to_list(&OA1, node); // ???
        }

        if (calc_OA2 && calc_OA2 % 100 == 0 && calc_OA2 != prev)
        {   
            prev = calc_OA2;
            // printf("AO1: %lu\n", calc_OA1);
            // printf("AO2: %lu\n", calc_OA2);
            // printf("\n");
            sum_len_OA1 += abs(OA1.pin - OA1.pout) + 1;
            sum_len_OA2 += abs(OA2.pin - OA2.pout) + 1;

            printf("%lu:\n", calc_OA2);
            printf("Длина OA1: %d\n", calc_len_list(&OA1) - 2);
            printf("Длина OA2: %d\n", 100 - calc_len_list(&OA1) + 2);  
        }
        
        if (calc_OA2 == 1000)
            break;

        while (time1 <= time2  && rc_1 == ERR_OK)
        {   
            rc_1 = take_frm_list(&OA1, &t1);

            if (rc_1 == ERR_OK)
            {
                time1 += t1;

                time_OA1 += t1;

                calc_OA++;

                //p = ((double)rand() / RAND_MAX) * 1.0;
                taken++;
            }
        }
        // printf("DEBUG:%lu \n", calc_OA);
        
        if (fabs(time2) < EPS)
        {   
            down += time1;
            
            time1 = 0;
        }
        else if (time1 >= time2)
        {
            time1 -= time2;
            
            if (OA2.pin == NULL && OA2.pout == NULL)
                down += time1;
        }

        time_OA2 += time2;

        rc_2 = take_frm_list(&OA2, &time2);

        for (int i = taken; i > 0; i--)
        {   
            p = ((double)rand() / RAND_MAX) * 1.0;
            
            if (taken && p <= po)
            {   
                calc_OA1++;

                t2 = ((double)rand() / RAND_MAX) * (oa2t2 - oa2t1) + oa2t1;

                node_t *node = create_node(t2);

                add_to_list(&OA2, node);

                taken--;
            }
            else if (taken)
            {   
                t1 = ((double)rand() / RAND_MAX) * (oa1t2 - oa1t1) + oa1t1;

                node_t *node = create_node(t1);

                rc_1 = add_to_list(&OA1, node);

                taken--;
            }
        }

        if (rc_2 == ERR_EMPTY)
            time2 = 0;
    }
    
    if (calc_OA2 == 1000)
    {   
        *avg_len_OA1 = (max_len_1 + min_len_1) / 2;
        *avg_len_OA2 = (max_len_2 + max_len_2) / 2;
        *complete_time = time_OA2 + down / 2;
        *down_time = down / 2;
        *avg_time_queue = (time_OA1 / calc_OA + time_OA2 / calc_OA2) / 2;
    }

    free_list(&OA1);
    free_list(&OA2);

    return ERR_OK;    
}
