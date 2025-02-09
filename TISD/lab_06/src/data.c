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

node_t *delete_less_data_name(node_t *tree, data_t data, size_t *calc) 
{   
    if (tree == NULL)
        return NULL;

    if (compare_data(&tree->data, &data) <= 0) 
    {
        node_t *temp = NULL;

        (*calc)++;
        if (tree->right != NULL) 
        {    
            temp = tree->right;
        } else 
        {
            temp = tree->left;    
        }
        
        free_node(tree);  
        return delete_less_data_name(temp, data, calc); 
    }

    tree->left = delete_less_data_name(tree->left, data, calc);
    tree->right = delete_less_data_name(tree->right, data, calc);
    
    return tree;
}

int make_n_times(FILE *data, const size_t n)
{   
    data_t m = { 31, 12, 2022 };
    
    double sum_name_pop = 0;
    double sum_data_pop = 0;
    double sum_data_build = 0;
    double t1 = 0, t2 = 0;

    node_t *tree = NULL;

    fnread_tree(data, n, &tree);

    tree = rebuild_tree_data(tree);

    free_tree(tree);

    size_t calc = 0;

    for (size_t i = 0; i < 100; i++)
    {   
        node_t *tree_name_pop = NULL;

        rewind(data);
        
        fnread_tree(data, n, &tree_name_pop);

        t1 = clock();
        tree_name_pop = delete_less_data(tree_name_pop, m, &calc);
        t2 = clock();

        sum_name_pop += (double) (t2 - t1) / CLOCKS_PER_SEC * 1000;

        free_tree(tree_name_pop);
    }
    
    calc = 0;
    for (size_t i = 0; i < 100; i++)
    {
        node_t *tree_name = NULL;
        node_t *tree_data_pop = NULL;
        
        rewind(data);
        fnread_tree(data, n, &tree_name);
    
        t1 = clock();
        tree_data_pop = rebuild_tree_data(tree_name);
        t2 = clock();

        sum_data_build += (double) (t2 - t1) / CLOCKS_PER_SEC * 1000;

        t1 = clock();
        tree_data_pop = delete_less_data(tree_data_pop, m, &calc);
        t2 = clock();

        sum_data_pop += (double) (t2 - t1) / CLOCKS_PER_SEC * 1000;
    }

    printf("Среднее время удаление элементов из дерева по алфавиту для %lu элементов (мс.): %lf\n", n, sum_name_pop / 100);
    printf("Среднее время удаление элементов из дерева по дате для %lu элементов (мс.): %lf\n\n", n, sum_data_pop / 100);
    printf("Удалено узлов: %zu\n\n", calc / 100);
    printf("Среднее время перестроения дерева по дате для %lu элементов (мс.): %lf\n", n, sum_data_build / 100);

    printf("======================================\n");

    return ERR_OK;
}