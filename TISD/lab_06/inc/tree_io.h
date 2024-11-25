#ifndef __TREE_IO_H__
#define __TREE_IO_H__

#include <stdio.h>
#include "tree.h"

void print_inorder(node_t *tree);

int fread_tree(FILE *f, node_t **list);

void fprint_tree(node_t *tree, FILE *f);

int fnread_tree(FILE *f, const size_t n, node_t **list);

#endif
