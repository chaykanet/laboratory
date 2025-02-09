#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int compare_data(const void *l, const void *r)
{   
    data_t *pl = (data_t *) l;
    data_t *pr = (data_t *) r;

    if (pl->year - pr->year == 0)
    {
        if (pl->mon - pr->mon == 0)
        {
            return pl->hour - pr->hour;
        }

        return pl->mon - pr->mon;
    }

    return pl->year - pr->year;
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

node_t *find_byname(node_t *tree, char *name)
{   
    if (tree == NULL)
        return NULL;

    if (strcmp(tree->filename, name) < 0)
        return find_byname(tree->right, name);
    else if (strcmp(tree->filename, name) > 0)
        return find_byname(tree->left, name);

    return tree;
}

node_t *find_bydata(node_t *tree, data_t data)
{   
    if (tree == NULL)
        return NULL;

    if (compare_data(&tree->data, &data) < 0)
        return find_bydata(tree->left, data);
    else if (compare_data(&tree->data, &data) > 0)
        return find_bydata(tree->right, data);

    return tree;
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

        node->filename = NULL;

        char *name = strdup(filename);

        node->filename = name;
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
    if (node == NULL)
        return tree;
    
    if (tree == NULL)
        return node;

    if (strcmp(tree->filename, node->filename) < 0)
        tree->left = add_to_tree_byname(tree->left, node);
    else if (strcmp(tree->filename, node->filename) > 0)
        tree->right = add_to_tree_bydata(tree->right, node);
    
    return tree;
}

node_t *add_to_tree_bydata(node_t *tree, node_t *node)
{   
    if (node == NULL)
        return tree;

    if (tree == NULL)
        return node;

    if (compare_data(&tree->data, &node->data) < 0)
        tree->left = add_to_tree_bydata(tree->left, node);
    else if (compare_data(&tree->data, &node->data) > 0)
        tree->right = add_to_tree_bydata(tree->right, node);
    
    return tree;
}

node_t *delete_node_byname(node_t *tree, char *name)
{   
    if (strcmp(tree->filename, name) < 0)
        tree->right = delete_node_byname(tree->right, name);
    else if (strcmp(tree->filename, name) > 0)
        tree->left = delete_node_byname(tree->left, name);
    else
    {
        if (tree->left == NULL)
        {
            free_node(tree);

            return tree->right;
        }

        if (tree->right == NULL)
        {
            free_node(tree);

            return tree->left;
        }

        node_t *min = min_elem_tree(tree->right);

        char *strname = strdup(min->filename);
        data_t data = min->data;

        if (tree->filename)
            free(tree->filename);

        tree->filename = strname;
        tree->data = data;
        tree->right = delete_node_byname(tree->right, tree->filename);
    }

    return tree;
}

node_t *delete_less_data(node_t *tree, data_t data, size_t *calc)
{   
    if (tree == NULL)
        return NULL;

    tree->left = delete_less_data(tree->left, data, calc);

    tree->right = delete_less_data(tree->right, data, calc);

    if (compare_data(&tree->data, &data) <= 0)
    {
        node_t *temp = NULL;

        if (tree->right != NULL)
        {    
            temp = tree->right;

            (*calc)++;
            
            if (tree)
                free_node(tree);
            return temp;
        }

        temp = tree->left;    
        
        if (tree)
            free_node(tree);
        
        (*calc)++;

        return temp;
    }

    return tree;
}

// node_t *delete_less_data(node_t *tree, data_t data) 
// {   
//     if (tree == NULL)
//         return NULL;

//     if (compare_data(&tree->data, &data) <= 0) 
//     {
//         node_t *temp = NULL;

       
//         if (tree->right != NULL) {    
//             temp = tree->right;
//         } else {
//             temp = tree->left;    
//         }
        
//         free_node(tree);  
//         return delete_less_data(temp, data); 
//     }

//     tree->left = delete_less_data(tree->left, data);
//     tree->right = delete_less_data(tree->right, data);
    
//     return tree;
// }

static void inorder(node_t *tree, node_t **list, size_t *index)
{
    if (tree == NULL)
        return;

    inorder(tree->left, list, index);
    list[(*index)++] = tree;
    inorder(tree->right, list, index);
}

static node_t *tree_bydata(node_t **list, const size_t len)
{           
    node_t *tree_data = NULL; 
    
    for (size_t i = 0; i < len; i++)
    {   
        list[i]->left = NULL;
        list[i]->right = NULL;
        tree_data = add_to_tree_bydata(tree_data, list[i]);
    }

    return tree_data;
}

node_t *rebuild_tree_data(node_t *tree_name)
{  
    if (tree_name == NULL)
        return NULL;

    size_t index = 0;

    node_t *list[N] = { 0 };

    inorder(tree_name, list, &index);
    
    qsort(list, index, sizeof(node_t *), compare_data);
    
    return tree_bydata(list, index);
}
