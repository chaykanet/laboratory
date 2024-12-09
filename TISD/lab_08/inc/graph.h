#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <stdlib.h>

#define MAX_NUM_VER 100

typedef struct node
{   
    int ver;

    int weight;

    struct node *next;
} node_t;

typedef struct graph
{
    node_t *list[MAX_NUM_VER];

    size_t num_vers;
} graph_t;

int is_empty(graph_t *g);

void free_graph(graph_t **g);

void free_nodes(node_t *node);

graph_t *clear_graph(graph_t *g);

graph_t *create_graph(const size_t num_vers);

void find_long_way(graph_t *g, const int ver);

graph_t *init_graph(graph_t *g, const size_t num_vers);

node_t *create_node(const int num, const int weight);

graph_t *add_to_graph(graph_t *g, const int src, const int dst, const int weight);

#endif
