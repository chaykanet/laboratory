#include "edges.h"

static void _freeEdges(edge_t *arr, size_t &len)
{
    free(arr);
    len = 0;
}

void defaultEdges(edges_t &edges)
{
    edges.arr = nullptr;
    edges.len = 0;
}

void freeEdges(edges_t &edges)
{
    _freeEdges(edges.arr, edges.len);
    defaultEdges(edges);
}

static myerror_t freadLenEdges(size_t &len, FILE *file)
{
    myerror_t rc = ERR_OK;

    if (file == nullptr)
    {
        rc = ERR_INPUT_DATA;
    }
    else
    {
        long int n;
        if (fscanf(file, "%ld", &n) != 1 || n <= 0)
            rc = ERR_INPUT_DATA;
        else
            len = n;
    }

    return rc;
}

static myerror_t freadToArrEdges(edge_t *edges, size_t len, FILE *file)
{
    myerror_t rc = ERR_OK;

    if (edges == nullptr)
    {
        rc = ERR_NULLPTR_ARRAY;
    }
    else
    {
        if (!len)
        {
            rc = ERR_RANGE_INDEXES;
        }
        else
        {
            for (size_t i = 0; rc == ERR_OK && i < len; ++i)
                rc = readEdge(edges[i], file);
        }
    }

    return rc;
}

myerror_t freadEdges(edges_t &edges, FILE *file)
{
    myerror_t rc = freadLenEdges(edges.len, file);

    if (rc == ERR_OK)
    {
        rc = allocEdges(&edges.arr, edges.len);

        if (rc == ERR_OK)
        {
            rc = freadToArrEdges(edges.arr, edges.len, file);

            if (rc != ERR_OK)
                _freeEdges(edges.arr, edges.len);
        }
    }

    return rc;
}

myerror_t allocEdges(edge_t **edges, size_t len)
{
    myerror_t rc = ERR_OK;

    if (!edges || !len)
    {
        rc = ERR_ALLOCATION;
    }
    else if (*edges)
    {
        rc = ERR_MEM_BUSY;
    }
    else
    {
        edge_t *ptrs = (edge_t *) malloc(sizeof(edge_t) * len);
        if (!ptrs)
            rc = ERR_ALLOCATION;
        else
            *edges = ptrs;
    }

    return rc;
}

