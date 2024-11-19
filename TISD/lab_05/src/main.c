#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "queue.h"
#include "queue_io.h"
#include "errcodes.h"
#include "queue_time.h"
#include "operations.h"

int main(void)
{   
    srand(123);

    int rc = ERR_OK;

    list_t list = { 0 };
    list_t list_time = { 0 };

    queue_t queue = { 0 };
    queue_t queue_time = { 0 };

    init_queue(&queue);

    init_list(&list);

    char *adresses[MAX_QUEUE_LEN] = { NULL };

    void *p;
    size_t calc_p = 0;

    double complete_time_avg = 0, down_time_avg = 0, avg_time_queue_avg = 0;

    double complete_queue = 0, downtime_queue = 0, avg_time_queue = 0;
    double complete_list = 0, downtime_list = 0, avg_time_list = 0;

    int move = 100;

    int n, tmp;

    double time_add_queue = 0, time_pop_queue = 0, time_add_list = 0, time_pop_list = 0;

    double avg_len_OA1 = 0, avg_len_OA2 = 0;

    double probability, oa1t1, oa1t2, oa2t1, oa2t2;

    do
    {   
        move = 100;
        printf("Меню:\n");
        printf("1.Вывести очереди.\n");
        printf("2.Запуск процесса моделирования для очереди.\n");
        printf("3.Запуск процесса моделирования для списка.\n");
        printf("4.Измерить время добавления/удаления n элементов для двух способов.\n");
        printf("5.Добавить число в очередь массив.\n");
        printf("6.Добавить число в очередь список.\n");
        printf("7.Удалить элемент из очереди массива.\n");
        printf("8.Удалить элемент из очереди списока.\n");
        printf("9.Вывести освобожденные адресса\n");
        printf("0.Выход.\n");
        printf("Ожидание ввода.\n");

        scanf("%d", &move);

        while (getchar() != '\n');

        switch (move)
        {
        case 1:
            print_queue(&queue);
            print_list(&list);
            break;
        case 2:
        {
            printf("--------------------------\n");

            printf("Введите вероятность успешности 0 < p <= 1 для OA1: \n");
            
            if (scanf("%lf", &probability) != 1 || 0 >= probability || probability > 1)
            {   
                printf("Ошибка: некорректный ввод.\n");
                while (getchar() != '\n');
                break;
            }

            printf("Введите интервал времени в (ед.в) 0 <= t1 < t2 <= 10 для OA1: \n");
            
            if (scanf("%lf %lf", &oa1t1, &oa1t2) != 2 || 0 > oa1t1 || 0 >= oa1t2 || oa1t1 >= oa1t2)
            {   
                printf("Ошибка: некорректный ввод.\n");
                while (getchar() != '\n');
                break;
            }

            printf("Введите интервал времени в (ед.в) 1 <= t1 < t2 <= 10 для OA2: \n");
            
            if (scanf("%lf %lf", &oa2t1, &oa2t2) != 2 || 1 > oa2t1 || 0 >= oa2t2 || oa2t1 >= oa2t2)
            {   
                printf("Ошибка: некорректный ввод.\n");
                while (getchar() != '\n');
                break;
            }

            process_modeling_queue(&complete_queue, &downtime_queue, &avg_time_queue, probability, oa1t1, oa1t2, oa2t1, oa2t2, &avg_len_OA1,&avg_len_OA2);
            printf("--------------------------\n");
            process_modeling_queue_avg(&complete_time_avg, &down_time_avg, &avg_time_queue_avg, probability, oa1t1, oa1t2, oa2t1, oa2t2, &avg_len_OA1,&avg_len_OA2);

            double precent = 0;
            
            precent = fabs(complete_queue / complete_time_avg - 1) * 100;
        
            printf("--------------------------\n");
            printf("Время выполнения операции: %lf (ед.в)\n", complete_queue);
            printf("Время простоя ОА2: %lf (ед.в)\n", downtime_queue);
            printf("Средняя длина очереди OA1: %lf\n", avg_len_OA1);
            printf("Средняя длина очереди OA2: %lf\n", avg_len_OA2);
            printf("Теоритическое время: %lf (ед.в)\n", complete_time_avg);
            printf("Отклонение от ожидаемого: %.2lf%%\n", precent);
            printf("Среднее время нахождения заявки в очереди: %lf (ед.в)\n", avg_time_queue);

            break;
        }
        case 3:
        {
            printf("--------------------------\n");

            printf("Введите вероятность успешности 0 < p <= 1 для OA1: \n");
            
            if (scanf("%lf", &probability) != 1 || 0 >= probability || probability > 1)
            {   
                printf("Ошибка: некорректный ввод.\n");
                while (getchar() != '\n');
                break;
            }

            printf("Введите интервал времени в (ед.в) 0 <= t1 < t2 <= 10 для OA1: \n");
            
            if (scanf("%lf %lf", &oa1t1, &oa1t2) != 2 || 0 > oa1t1 || 0 >= oa1t2 || oa1t1 >= oa1t2)
            {   
                printf("Ошибка: некорректный ввод.\n");
                while (getchar() != '\n');
                break;
            }

            printf("Введите интервал времени в (ед.в) 1 <= t1 < t2 <= 10 для OA2: \n");
            
            if (scanf("%lf %lf", &oa2t1, &oa2t2) != 2 || 1 > oa2t1 || 0 >= oa2t2 || oa2t1 >= oa2t2)
            {   
                printf("Ошибка: некорректный ввод.\n");
                while (getchar() != '\n');
                break;
            }

            // process_modeling_queue(&complete_list, &downtime_list, &avg_time_list, probability, oa1t1, oa1t2, oa2t1, oa2t2, &avg_len_OA1,&avg_len_OA2);
            process_modeling_list(&complete_list, &downtime_list, &avg_time_list, probability, oa1t1, oa1t2, oa2t1, oa2t2, &avg_len_OA1,&avg_len_OA2);
            printf("--------------------------\n");
            process_modeling_queue_avg(&complete_time_avg, &down_time_avg, &avg_time_queue_avg, probability, oa1t1, oa1t2, oa2t1, oa2t2, &avg_len_OA1,&avg_len_OA2);

            double precent = 0;
            
            precent = fabs(complete_list / complete_time_avg - 1) * 100;
        
            printf("--------------------------\n");
            printf("Время выполнения операции: %lf (ед.в)\n", complete_list);
            printf("Время простоя ОА2: %lf (ед.в)\n", downtime_list);
            printf("Теоритическое время: %lf (ед.в)\n", complete_time_avg);
            printf("Средняя длина очереди OA1: %lf\n", avg_len_OA1);
            printf("Средняя длина очереди OA2: %lf\n", avg_len_OA2);
            printf("Отклонение от ожидаемого: %.2lf%%\n", precent);
            printf("Среднее время нахождения заявки в очереди: %lf (ед.в)\n", avg_time_list);
            break;
        }
        case 4:
            printf("--------------------------\n");
            printf("Ввеидте кол-во итераций: \n");

            if (scanf("%d", &n) != 1)
            {   
                while (getchar() != '\n');
                printf("Некорректный ввод.\n");
                rc = ERR_IO;
                break;
            }
            while (getchar() != '\n');

            init_queue(&queue_time);
            init_list(&list_time);
     
            rc = make_n_avg_time(&list_time, &queue_time, &time_add_list, &time_pop_list, &time_add_queue, &time_pop_queue, n);

            if (rc == ERR_OK)
            {
                printf("--------------------------\n");
                printf("Время добавления %d элементов для очереди массива, мс:%lf \n", n, time_add_queue);
                printf("Время удаления %d элементов для очереди массива, мс: %lf \n\n", n, time_pop_queue);

                printf("Время добавления %d элементов для очереди списка, мс: %lf \n", n, time_add_list);
                printf("Время удаления %d элементов для очереди списка, мс: %lf \n\n", n, time_pop_list);
            }
            break;
        case 5:
            printf("Введите значение элемента типа int: \n");
            if (scanf("%d", &tmp) != 1)
            {
                printf("Некорректный ввод.\n");
                break;
            }
            while (getchar() != '\n');

            rc = add_to_queue(&queue, tmp);

            if (rc == ERR_OVERFLOW)
            {
                printf("Ошибка: очередь переполнена\n");
            }
            break;
        case 6:
            printf("Введите значение элемента типа int: \n");
            if (scanf("%d", &tmp) != 1)
            {
                printf("Некорректный ввод.\n");
                break;
            }
            while (getchar() != '\n');

            node_t *node = create_node(tmp);

            rc = add_to_list(&list, node);

            for (size_t i = 0; i < calc_p; i++)
                if ((void *) node == (void *) adresses[i])
                    adresses[i] = NULL;
            break;
        case 7:
            rc = pop_frm_queue(&queue);

            if (rc != ERR_OK)
            {
                printf("Ошибка: очередь пуста.\n");
            }

            break;
        case 8:

            rc = pop_frm_list_adress(&list, &p);
            if (rc != ERR_OK)
            {
                printf("Ошибка: очередь пуста.\n");
            }
        
            adresses[calc_p++] = p;
            break;
        case 9:
            printf("Свободные адреса: { ");
            for (size_t i = 0; i < MAX_QUEUE_LEN; i++)
                if (adresses[i])
                    printf("%p ", (void *) adresses[i]);
            printf("}\n");
            break;
        default:
            break;
        }

        if (rc != ERR_OK)
        {
            printf("Код ошибки %d\n", rc);
        }

        rc = ERR_OK;
    } while (move != 0);

    free_list(&list_time);

    free_list(&list);
    
    return rc;
}
