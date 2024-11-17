#include <stdio.h>
#include "car_t.h"
#include "car_t_array.h"
#include "car_t_arr_sort.h"

#include <time.h>

int main(void)
{
    int rc;
    char filename[MAX_LEN_STR];

    clock_t start, end;

    double time_key_sort = 0, time_key_qsort = 0, time_car_sort = 0, time_car_qsort = 0;  

    printf("Введите имя файла: \n");
    scanf("%s", filename);

    FILE *database;
    while (!(database = fopen(filename, "r")))
    {
        printf("Файл не наден, повторите ввод:\n");
        scanf("%s", filename);
    }

    car_el_t *base_st;
    car_el_t *base_en;
    
    car_el_t arr[MAX_ELEM];
    size_t len = 0;

    ckey_t *key_st;
    ckey_t *key_en;

    rc = fread_arr_car(database, &base_st, &base_en);

    if (database)
        fclose(database);
    
    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    } 

    size_t nmemb = base_en - base_st;
    size_t nmembprev = nmemb;

    rc = get_keys(&key_st, &key_en, base_st, nmemb);

    if (rc != ERR_OK)
    {
        print_err(rc);
        return rc;
    } 
    
    int move = 10;
    do 
    {
        printf("Введите номер действия :\n1.Вывести таблицу.\n2.Добавить элемент.\n3.Удалить элемент по цене.\n");
        printf("4.Вывести отсортированную таблицу ключей.\n");
        printf("5.Отсортировать обычной сортировкой массив машин по цене.\n6.Отсортировать обычной сортировкой массив машин по цене по ключам.\n");
        printf("7.Отсортировать быстрой сортировкой массив машин по цене.\n8.Отсортировать быстрой сортировкой массив машин по цене по ключам.\n");
        printf("9.Вывести измерения сортировок.\n10.Найти старые машины определенной марки с 1 владельцем в заданном диапозоне цен c тех.поддержкой.\n");
        printf("11.О программе\n0.Выход.\nОжидание ввода: \n");
        rc = scanf("%d", &move);

        if (rc != 1) 
        {
            printf("Неверный номер действия.\n");
            
            while (getchar() != '\n');

            continue;
        }

        rc = ERR_OK;
        
        if (nmembprev != nmemb)
        {
            free(key_st);

            rc = get_keys(&key_st, &key_en, base_st, nmemb);

            nmembprev = nmemb;
        } 
        
        car_el_t *base_stcp = malloc(nmemb * sizeof(car_el_t));
        if (!base_stcp)
        {   
            print_err(ERR_ALLOC);
            return ERR_ALLOC;
        }

        car_el_t *base_encp = base_stcp + nmemb;
        memcpy(base_stcp, base_st, (nmemb) * sizeof(car_el_t));

        ckey_t *key_stcp = malloc((nmemb) * sizeof(ckey_t));
        if (!key_stcp)
        {   
            print_err(ERR_ALLOC);
            return ERR_ALLOC;
        }

        ckey_t *key_encp = key_stcp + (nmemb);
        memcpy(key_stcp, key_st, (nmemb) * sizeof(ckey_t));
        
        switch(move)
        {
            case 1:
                printf("-------------------------------------------\n");
                printf("Вывод таблицы машин:\n");
                print_arr_car(base_st, nmemb);
                break;
            case 2:
                printf("-------------------------------------------\n");
                printf("Добавление элемента...\n");
                rc = add_arr_elem(&base_st, &nmemb);
                break;
            case 3:
                printf("-------------------------------------------\n");
                printf("Удаления элемента...\n");
                printf("Введите стоимость машины;\n");
                size_t price;
                if (scanf("%lu", &price) != 1)
                {    
                    rc = ERR_IO;
                    break;
                }
                rc = pop_arr_elembyprice(&base_st, &nmemb, price);
                break;
            case 4:
                printf("-------------------------------------------\n");
                printf("Отсортированная таблица ключей\n");
                qsort_arr(key_stcp, key_encp, nmemb, sizeof(ckey_t), cmp_key_price);
                print_keys(key_stcp, key_encp);
                break;
            case 5:
                printf("-------------------------------------------\n");
                printf("Обычная сортировка таблицы...\n");
                start = clock();
                sort_arr(base_stcp, base_encp, nmemb, sizeof(car_el_t), cmp_car_price);
                end = clock();
                
                time_car_sort = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                printf("Отсортированная таблица:\n");
                print_arr_car(base_stcp, nmemb);
                printf("Время выполнения сортировки: %lf\n", time_car_sort);
                break;
            case 6:
                printf("-------------------------------------------\n");
                printf("Обычная сортировка таблицы по ключам...\n");
                start = clock();
                sort_arr(key_st, key_en, nmemb, sizeof(ckey_t), cmp_key_price);
                end = clock();
                
                time_key_sort = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                print_arr_withkey(base_st, base_en, key_st, key_en);
                printf("Время выполнения сортировки в мс.: %lf\n", time_key_sort);
                break;
            case 7:
                printf("-------------------------------------------\n");
                printf("Быстрая сортировка таблицы...\n");
                start = clock();
                qsort_arr(base_stcp, base_encp, nmemb, sizeof(car_el_t), cmp_car_price);
                end = clock();
                
                time_car_qsort = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                printf("Отсортированная таблица:\n");
                print_arr_car(base_stcp, nmemb);
                printf("Время выполнения сортировки в мс.: %lf\n", time_car_qsort);
                break;
            case 8:
                printf("-------------------------------------------\n");
                printf("Быстрая сортировка таблицы по ключам...\n");
                start = clock();
                qsort_arr(key_st, key_en, nmemb, sizeof(ckey_t), cmp_key_price);
                end = clock();

                time_key_qsort = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                print_arr_withkey(base_st, base_en, key_st, key_en);
                printf("Время выполнения сортировки в мс.: %lf\n", time_key_qsort);
                break;
            case 9:
                if (!time_car_sort || !time_car_qsort || !time_key_sort || !time_key_qsort)
                {
                    printf("НЕДОСТАТОЧНО ИЗМЕРЕНИЙ !!!");
                    break;
                }
                printf("Вывод измерений...");
                printf("-------------------------------------------\n");
                printf("Обычная сортировка:\n");
                printf("Время выполнения сортировки таблицы в мс.: %lf\n", time_car_sort);
                printf("Время выполнения сортировки таблицы ключей в мс.: %lf\n", time_key_sort);
                printf("-------------------------------------------\n");
                printf("Ускоренная сортировка:\n");
                printf("Время выполнения сортировки таблицы в мс.: %lf\n", time_car_qsort);
                printf("Время выполнения сортировки таблицы ключей в мс.: %lf\n", time_key_qsort);
                printf("-------------------------------------------\n");
                printf("Занимаемая память таблицы: %lu\n", sizeof(car_el_t) * nmemb);
                printf("Занимаемая память таблицы ключей: %lu\n", sizeof(ckey_t) * nmemb);
                break;
            case 10:
                printf("-------------------------------------------\n");
                unsigned int price_l, price_r;
                int tmp;
                char mark[MAX_LEN_STR], str[MAX_LEN_STR + 1];
                while (getchar() != '\n');
                printf("Введите марку машины:\n");
                fgets(str, MAX_LEN_STR + 1, stdin);
                char *p = strrchr(str, '\n');
                if (p)
                    *p = '\0';
                else
                {
                    rc = ERR_IO;
                    break;
                }
                if (strlen(str) == MAX_LEN_STR + 1)
                {
                    rc = ERR_IO;
                    break;
                }
                strcpy(mark, str);
                printf("Введите левое значение диапозона цен машин:\n");
                if (scanf("%d", &tmp) != 1 || tmp < 0)
                {
                    rc = ERR_IO;
                    break;
                }
                price_l = tmp;
                printf("Введите правое значение диапозона цен машин:\n");
                if (scanf("%d", &price_r) != 1 || tmp < 0)
                {
                    rc = ERR_IO;
                    break;
                }
                price_r = tmp;
                rc = filter_car_param(base_st, nmemb, arr, &len, mark, price_l, price_r);

                if (rc == ERR_OK)
                    print_garanted_car(arr, len);
                break;
            case 11:
                printf("-------------------------------------------\n");
                printf("Программа совершает работу с таблицей машин. Осуществляет сортировку таблицы по ключам. Дает возможность добавлять или удалять элементы таблицы.\n");
                printf("Осуществляет подсчет измерений времени ывполнения различных способов сортировки таблицы.\n");
                printf("Программа может находить старые иномарки с тех. поддержкой с 1-им предыдущим владельцем.\n");
            default:
                break;
        }

        free(base_stcp);
        free(key_stcp);

        if (rc != ERR_OK)
        {   
            print_err(rc);
            break;
        }
    }
    while (move != 0);

    free(base_st);
    free(key_st);

    return rc;
}