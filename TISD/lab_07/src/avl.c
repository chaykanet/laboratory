#include "avl.h"

unsigned char height(node_t *node)
{
    return node ? node->height : 0;
}

int bfactor(node_t *p)
{
    return height(p->right) - height(p->left);
}

void fixheight(node_t *p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);

    p->height = (hl > hr ? hl : hr) + 1;
}

void free_tree(node_t *tree)
{   
    if (tree)
    {
        if (tree->left)
            free_tree(tree->left);

        if (tree->right)
            free_tree(tree->right);

        free(tree);
    }
}

void free_node(node_t *p)
{
    if (p) free(p);
}

node_t *search_tree(node_t *tree, size_t *calc, char *word)
{   
    if (tree == NULL)
        return NULL;

    node_t *p = tree;

    *calc = 0;

    if (strcmp(p->word, word) == 0)
        return p;

    while (p)
    {   
        (*calc)++;
        if (strcmp(p->word, word) > 0)
            p = p->left;
        else if (strcmp(p->word, word) < 0)
            p = p->right;
        else return p;
    }

    return p;
}

node_t *rotateright(node_t *p)
{
    node_t *q = p->left;

    p->left = q->right;

    q->right = p;

    fixheight(p);

    fixheight(q);

    return q;
}

node_t *rotateleft(node_t *q)
{
    node_t *p = q->right; 

    q->right = p->left;

    p->left = q;

    fixheight(p);

    fixheight(q);

    return p;
}

node_t *balance(node_t *p)
{
    fixheight(p);

    if (bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);

        return rotateleft(p);
    }

    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);

        return rotateright(p);
    }

    return p;
}

node_t *create_node(const char *word, const char *help)
{
    node_t *p = calloc(1, sizeof(node_t));

    if (p)
    {
        strcpy(p->word, word);
        strcpy(p->help, help);
    }
    return p;
}

node_t *insert(node_t *tree, char *word, char *help)
{
    if (tree == NULL)
        return create_node(word, help);

    if (strcmp(tree->word, word) > 0)
        tree->left = insert(tree->left, word, help);
    else if (strcmp(tree->word, word) < 0)
        tree->right = insert(tree->right, word, help);

    return balance(tree);
}

node_t *find_min(node_t *p)
{
    return p->left ? find_min(p->left) : p;
}

node_t *find_max(node_t *p)
{
    return p->right ? find_min(p->right) : p;
}

static node_t *remove_min(node_t *min)
{
    if (min->left == NULL)
        return min->right;

    min->left = remove_min(min->left); // ???

    return balance(min);
}

node_t *delete(node_t *tree, char *word)
{
    if (tree == NULL)
        return NULL;

    if (strcmp(tree->word, word) == 0)
    {   
        node_t *left = tree->left;

        if (tree->right == NULL)
        {
            free_node(tree);
            return left;
        }

        node_t *min = find_min(tree->right);

        min->right = remove_min(tree->right);

        free_node(tree);

        min->left = tree->left; // освобождение узла ???.

        return balance(min);
    }

    if (strcmp(tree->word, word) < 0)
        delete(tree->right, word);
    else if (strcmp(tree->word, word) > 0)
        delete(tree->left, word);

    return balance(tree);
}
