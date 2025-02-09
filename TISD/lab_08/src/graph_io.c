#include "graph_io.h"

void print_graph(const graph_t *g)
{
    FILE *f = fopen("./graph.dot", "w");

    fprintf(f, "digraph G {\n");
    fprintf(f, "trankdir=LR;\n");
    for (size_t i = 0; i < g->num_vers; i++)
    {       
        node_t *cur = g->list[i];
        while (cur != NULL)
        {   
            if (i < (size_t) cur->ver)
                fprintf(f, "    %zu -> %d [label=\"%d\"];\n", i, cur->ver, cur->weight);

            cur = cur->next;
        }
    }

    fprintf(f, "}\n");

    fclose(f);
}

int fread_graph(char *filename, graph_t *g)
{   
    int rc = ERR_OK;

    FILE *f = fopen(filename, "r");

    if (f)
    {   
        int num_vers = 0;
        
        if (fscanf(f, "%d\n", &num_vers) != 1 || num_vers <= 0)
            rc = ERR_IO;

        for (int i = 0; i < num_vers - 1 && rc == ERR_OK; i++)
        {   
            int src = 0, dst = 0, weight = 0;

            if (fscanf(f, "%d %d %d\n", &src, &dst, &weight) == 3 && src >=0 && dst >= 0 && weight >= 0)
                g = add_to_graph(g, src, dst, weight);
            
            if (rc == EOF)
                rc = ERR_OK;
        }
    }
    else
        rc = ERR_IO;

    return rc;
}