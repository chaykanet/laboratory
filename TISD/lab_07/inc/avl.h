#ifndef __AVL_H_
#define __AVL_H_

#include <stdlib.h>
#include <string.h>

#define MAX_LEN_WORD 20

#define MAX_LEN_HELP 256

typedef struct node
{   
    char word[MAX_LEN_WORD];

    char help[MAX_LEN_HELP];

    unsigned char height;

    struct node *left;

    struct node *right;

} node_t;

unsigned char height(node_t *node);

int bfactor(node_t *p);

void fixheight(node_t *p);

void free_tree(node_t *tree);

node_t *balance(node_t *p);

node_t *find_min(node_t *p);

node_t *delete(node_t *tree, char *word);

node_t *insert(node_t *tree, char *word, char *help);

node_t *create_node(const char *word, const char *help);

node_t *search_tree(node_t *tree, size_t *calc, char *word);

#endif