#ifndef EDGE_H
#define EDGE_H

#include <stddef.h>
#include <stdio.h>

#include "error.h"

typedef struct edge_t edge_t;

struct edge_t
{
    size_t indexA;

    size_t indexB;
};

void freeEdge(edge_t &edge);

void defaultEdge(edge_t &edge);

myerror_t allocEdge(edge_t &edge);

myerror_t readEdge(edge_t &edge, FILE *file);

myerror_t initEdge(edge_t *edge, size_t indexA, size_t indexB);

void indexesEdge(size_t &indexA, size_t &indexB, const edge_t &edge);

#endif
