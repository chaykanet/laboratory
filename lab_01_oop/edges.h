#ifndef EDGES_H
#define EDGES_H

#include "edge.h"

typedef struct edges_t edges_t;

struct edges_t
{
    edge_t *arr;

    size_t len;
};

void freeEdges(edges_t &edges);

void defaultEdges(edges_t &edges);

myerror_t allocEdges(edge_t **edges, size_t len);

myerror_t freadEdges(edges_t &edges, FILE *file);

#endif // EDGES_H
