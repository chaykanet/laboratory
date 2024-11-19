#include "tree_io.h"

void fprint_node(node_t *node, FILE *f)
{
    if (node->left)
    {    
        fprintf(f, "\t\"%s [%d.%d.%d]\" -> \"%s [%d.%d.%d]\";\n", node->filename, node->data.hour, node->data.mon, node->data.year,
         node->left->filename, node->left->data.hour, node->left->data.mon, node->left->data.year);
        fprint_node(node->left, f);
    }

    if (node->right)
    {    
        fprintf(f, "\t\"%s [%d.%d.%d]\" -> \"%s [%d.%d.%d]\";\n", node->filename, node->data.hour, node->data.mon, node->data.year,
         node->right->filename, node->right->data.hour, node->right->data.mon, node->right->data.year);
        fprint_node(node->right, f);
    }
}

void fprint_tree(node_t *tree, FILE *f)
{
    fprintf(f, "digraph G {\n");
    fprintf(f, "\tnode [shape=circle];\n");

    if (tree)
    {
        fprintf(f, "\t\"%s [%d.%d.%d]\"; \n", tree->filename, tree->data.hour, tree->data.mon, tree->data.year);

        fprint_node(tree, f);
    }

    fprintf(f, "}\n");
}