#include "graph.h"

#include <stdio.h>
#include <limits.h>

void free_nodes(node_t *node)
{
    while (node)
    {
        node_t *p = node;

        node = node->next;

        free(p);
    }
}

void free_graph(graph_t **g)
{
    if ((*g))
    {
        for (size_t i = 0; i < (*g)->num_vers; i++)
            free_nodes((*g)->list[i]);

        free((*g)->list);

        free(*g);
    }

    *g = NULL;
}

int is_empty(graph_t *g)
{   
    int empty = 0;

    for (size_t i = 0; i < g->num_vers && empty == 0; i++)
        if (g->list[i] != NULL)
            empty = 1;

    return empty;
}

node_t *create_node(const int num, const int weight)
{
    node_t *p = malloc(sizeof(node_t));

    if (p)
    {
        p->ver = num;

        p->weight = weight;

        p->next = NULL;
    }

    return p;
}

graph_t *clear_graph(graph_t *g)
{
    for (size_t i = 0; i < g->num_vers; i++)
    {
        free_nodes(g->list[i]);

        g->list[i] = NULL;
    }

    return g;
}

graph_t *init_graph(graph_t *g, const size_t num_vers)
{
    for (size_t i = 0; i < num_vers; i++)
        g->list[i] = NULL;

    g->num_vers = num_vers;

    return g;
}

graph_t *create_graph(const size_t num_vers)
{
    graph_t *g =  malloc(sizeof(graph_t));

    if (g)
    {
        g->num_vers = num_vers;

        for (size_t i = 0; i < num_vers; i++)
            g->list[i] = NULL;
    }

    return g;
}

graph_t *add_to_graph(graph_t *g, const int src, const int dst, const int weight)
{
    node_t *node = create_node(dst, weight);
    // node_t *rnode = create_node(src, weight);
    if (node)
    {
        node->next = g->list[src];
        g->list[src] = node;

        // rnode->next = g->list[dst];
        // g->list[dst] = rnode;
    }

    return g;
}

void topol_sort(int v, int *visited, int *stack, int *stack_index, graph_t *g)
{
    visited[v] = 1;
    node_t *cur = g->list[v];

    while (cur != NULL)
    {
        if (!visited[cur->ver])
            topol_sort(cur->ver, visited, stack, stack_index, g);

        cur = cur->next;
    }

    stack[(*stack_index)++] = v;
}

static size_t find_max(int *arr, size_t len)
{   
    size_t i_max = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (arr[i_max] < arr[i])
            i_max = i;
    }

    return i_max;
}


void find_long_way(graph_t *g, const int ver)
{
    int distance[MAX_NUM_VER];
    int stack[MAX_NUM_VER];
    int stack_index = 0;

    int visited[MAX_NUM_VER] = { 0 };

    for (size_t i = 0; i < g->num_vers; i++)
        distance[i] = INT_MIN;

    distance[ver] = 0;

    for (size_t i = 0; i < g->num_vers; i++)
    {
        if (!visited[i])
            topol_sort(i, visited, stack, &stack_index, g);
    }

    while (stack_index > 0)
    {
        int ver = stack[--stack_index];

        node_t *cur = g->list[ver];

        while (cur != NULL)
        {
            if (distance[ver] != INT_MIN && distance[cur->ver] < distance[ver] + cur->weight)
                distance[cur->ver] = distance[ver] + cur->weight;
        
            cur = cur->next;
        }
    }

    size_t i_max = find_max(distance, MAX_NUM_VER); 

    printf("Максимальное расстояние до вершины %zu: %d\n", i_max, distance[i_max]);
}