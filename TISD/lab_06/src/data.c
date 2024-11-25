#include <stdio.h>
#include <time.h>

#include "data.h"

int check_data(int const day, int const mon)
{   
    switch (mon)
    {
    case 1:  
    case 3:  
    case 5: 
    case 7: 
    case 8:  
    case 10:
    case 12: 
        if (day > 31)
            return ERR_DATA;
        break;
    case 4:  
    case 6:  
    case 9:  
    case 11: 
        if (day > 30)
            return ERR_DATA;
        break;
    case 2:  
        if (day > 28)
            return ERR_DATA;
        break;
    default:
        return ERR_DATA;
        break;
    }

    return ERR_OK;
}

int make_n_times(FILE *data, const size_t n)
{   
    data_t m = { 31, 12, 9999 };
    
    double sum_name_pop = 0;
    double sum_data_pop = 0;
    double sum_data_build = 0;
    double t1 = 0, t2 = 0;

    printf("DEBUG: %lu\n", n);

    for (size_t i = 0; i < 1; i++)
    {   
        node_t *tree_name_pop = NULL;
        node_t *tree_name = NULL;
        node_t *tree_data_pop = NULL;

        rewind(data);
        
        fnread_tree(data, n, &tree_name_pop);

        t1 = clock();
        tree_name_pop = delete_less_data(tree_name_pop, m);
        t2 = clock();
        
        sum_name_pop += (double) (t2 - t1) / CLOCKS_PER_SEC * 1000;
      
        rewind(data);
        fnread_tree(data, n, &tree_name);
    
        t1 = clock();
        tree_data_pop = rebuild_tree_data(tree_name);
        t2 = clock();

        sum_data_build += (double) (t2 - t1) / CLOCKS_PER_SEC * 1000;

        t1 = clock();
        tree_data_pop = delete_less_data(tree_data_pop, m);
        t2 = clock();

        sum_data_pop += (double) (t2 - t1) / CLOCKS_PER_SEC * 1000;
    }

    printf("Среднее время удаление элементов из дерева по алфавиту для %lu элементов: %lf\n", n, sum_name_pop / 100);
    printf("Среднее время удаление элементов из дерева по дате для %lu элементов: %lf\n\n", n, sum_data_pop / 100);

    printf("Среднее время перестроения дерева по дате для %lu элементов: %lf\n", n, sum_data_build / 100);

    printf("======================================\n");

    return ERR_OK;
}