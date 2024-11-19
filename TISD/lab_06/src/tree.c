#include <stdio.h>
#include "tree.h"

int compare_data(data_t *l, data_t *r)
{   
    if (l->year - r->year == 0)
    {
        if (l->mon - r->mon == 0)
        {
            return l->hour - r->hour;
        }

        return l->mon - r->mon;
    }

    return l->year - r->year;
}

void free_node(node_t *node)
{   
    if (node)
    {   
        free(node->filename);

        free(node);
    }
}

void free_tree(node_t *tree)
{
    if (tree)
    {
        if (tree->left)
            free_tree(tree->left);

        if (tree->right)
            free_tree(tree->right);

        if (tree)
            free_node(tree);
    }
}

node_t *init_node(char *filename, data_t data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node)
    {   
        node->data = data;

        node->parent = NULL;

        node->left = NULL;

        node->right = NULL;

        node->filename = filename;
    }

    return node;
}

node_t *min_elem_tree(node_t *tree)
{
    node_t *p = tree;

    while (p && p->left != NULL)
    {
        p = p->left;
    }

    return p;
}

node_t *add_to_tree_byname(node_t *tree, node_t *node)
{
    if (tree == NULL)
        return node;
    
    node_t *p = tree;
    node_t *parent = NULL;

    while (p != NULL)
    {   
        parent = p;

        if (strcmp(p->filename, node->filename) > 0)
            p = p->left;
        else if (strcmp(p->filename, node->filename) < 0)
            p = p->right;
        else
            return tree;
    }
    
    if (strcmp(parent->filename, node->filename) > 0)
        parent->left = node;
    else
        parent->right = node;

    return tree;
}

node_t *add_to_tree_bydata(node_t *tree, node_t *node)
{   
    if (tree == NULL)
        return node;

    node_t *p = tree;
    node_t *parent = NULL;

    while (p != NULL)
    {   
        parent = p;

        if (compare_data(&p->data, &node->data) < 0)
            p = p->left;
        else if (compare_data(&p->data, &node->data) > 0)
            p = p->right;
        else
            return tree;
    }
    
    if (compare_data(&parent->data, &node->data) < 0)
        parent->left = node;
    else
        parent->right = node;

    return tree;
}

node_t *delete_node_byname(node_t *tree, char *name, int *rc)
{   
    node_t *p = tree;
    node_t *parent = NULL;

    while (p != NULL && strcmp(name, p->filename) != 0)
    {
        parent = p;
        
        if (strcmp(name, p->filename) < 0)
            p = p->left;
        else
            p = p->right;
    }

    if (p == NULL)
    {   
        *rc = ERR_DELETE;
        return tree;
    }

    if (p->left == NULL && p->right == NULL)
    {
        
        if (p == tree)
        {
            free(p);
            return NULL;
        }
        else if (parent->left == p)
        {
            parent->left = NULL;
        }
        else if (parent->right == p)
        {
            parent->right = NULL;
        }

        free(p);
        *rc = ERR_OK;
        return tree;
    }
    else if (p->left == NULL || p->right == NULL)
    {   
        node_t *child;

        if (p->left)
            child = p->left;
        else
            child = p->right;


        if (p == tree)
        {
            free(p);
            *rc = ERR_OK;
            return child;
        }

        if (parent->left == p)
            parent->left = child;
        else
            parent->right = child;

        free(p);
        *rc = ERR_OK;
        return tree;
    }
    else if (p->left && p->right)
    {
        node_t *child = min_elem_tree(p->right);

        char *filename = child->filename;
        data_t data = child->data;

        tree = delete_node_byname(tree, filename, rc);

        p->filename = filename;
        p->data = data;
    }
    *rc = ERR_OK;
    return tree;
}

node_t *delete_node_bydata(node_t *tree, data_t data, int *rc)
{   
    node_t *p = tree;
    node_t *parent = NULL;

    while (p != NULL && compare_data(&p->data, &data) >= 0)
    {
        parent = p;

        if (compare_data(&p->data, &data) < 0)
            p = p->right;
        else
            p = p->left;
    }

    if (p == NULL)
    {   
        *rc = ERR_DELETE;
        return tree;
    }

    if (p->left == NULL && p->right == NULL)
    {
        
        if (p == tree)
        {
            free(p);
            *rc = ERR_OK;
            return NULL;
        }
        else if (parent->left == p)
        {
            parent->left = NULL;
        }
        else if (parent->right == p)
        {
            parent->right = NULL;
        }

        free(p);
        *rc = ERR_OK;

        return tree;
    }
    else if (p->left == NULL || p->right == NULL)
    {   
        node_t *child;

        if (p->left)
            child = p->left;
        else
            child = p->right;


        if (p == tree)
        {
            free(p);

            return child;
        }

        if (parent->left == p)
            parent->left = child;
        else
            parent->right = child;

        free(p);
        *rc = ERR_OK;
        return tree;
    }
    else if (p->left && p->right)
    {
        node_t *child = min_elem_tree(p->right);

        char *filename = child->filename;
        data_t data = child->data;

        tree = delete_node_bydata(tree, data, rc);

        p->filename = filename;
        p->data = data;
    }
    *rc = ERR_OK;
    return tree;
}

node_t *delete_less_data(node_t *tree, data_t data)
{   
    if (tree == NULL)
        return NULL;

    tree->left = delete_less_data(tree->left, data);

    tree->right = delete_less_data(tree->right, data);

    if (compare_data(&tree->data, &data) <= 0)
    {
        node_t *temp;

        if (tree->right != NULL)
        {    
            temp = tree->right;
            free_node(tree);
            return temp;
        }

        temp = tree->left;    
            
        free_node(tree);
        return temp;
    }

    return tree;
}
