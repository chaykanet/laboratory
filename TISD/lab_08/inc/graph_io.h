#ifndef __GRAPH_IO_H_
#define __GRAPH_IO_H_

#include <stdio.h>

#include "errcodes.h"
#include "graph.h"

void print_graph(const graph_t *g);

int fread_graph(char *filename, graph_t *g);

#endif
