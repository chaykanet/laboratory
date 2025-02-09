#ifndef __TREE_H__
#define __TREE_H__

#include <stdlib.h>
#include <string.h>

#include "errcodes.h"

#define N 10000 

typedef struct data
{
    int hour;

    int mon;

    int year;
} data_t;


typedef struct node
{
    char *filename;

    data_t data;

    struct node *parent;
    
    struct node *left;

    struct node *right;

} node_t;

int compare_data(const void *l, const void *r);

void free_node(node_t *node);

void free_tree(node_t *tree);

node_t *find_byname(node_t *tree, char *name);

node_t *find_bydata(node_t *tree, data_t data);

node_t *min_elem_tree(node_t *tree);

node_t *rebuild_tree_data(node_t *tree_name);

node_t *init_node(char *filename, data_t data);

node_t *delete_less_data(node_t *tree, data_t data, size_t *calc);

node_t *delete_node_byname(node_t *tree, char *name);

node_t *add_to_tree_byname(node_t *tree, node_t *node);

node_t *add_to_tree_bydata(node_t *tree, node_t *node);

#endif
