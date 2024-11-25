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

int fread_tree(FILE *f, node_t **list)
{   
    int rc = ERR_OK;
    ssize_t read = 0;
    size_t n = 0;

    while (!feof(f) && rc == ERR_OK)
    {   
        char *str = NULL;

        read = getline(&str, &n, f);
        if (read > 0)
        {
            char *p = strchr(str, '\n');
            if (p)
                *p = '\0';
            
            int day, mon, year;
            rc = ERR_OK;
            if (fscanf(f, "%d %d %d", &day, &mon, &year) != 3 || day < 0 || mon < 0 || year < 0)
            {    
                printf(" Ошибка: некорректный ввод.\n");
                rc = ERR_IO;
            }

            fgetc(f);

            if (rc == ERR_OK)
            {    
                data_t data = { 24 * day, mon, year };
                node_t *node = init_node(str, data);
                *list = add_to_tree_byname(*list, node);
            }
        }
        else    
            rc = ERR_IO;

        free(str);
    }

    return rc;
}

int fnread_tree(FILE *f, const size_t n, node_t **list)
{   
    int rc = ERR_OK;
    ssize_t read = 0;
    size_t c = 0;

    size_t calc = 0;

    while (!feof(f) && rc == ERR_OK && calc < n)
    {   
        char *str = NULL;

        read = getline(&str, &c, f);
        if (read > 0)
        {
            char *p = strchr(str, '\n');
            if (p)
                *p = '\0';
            
            int day, mon, year;
            rc = ERR_OK;
            if (fscanf(f, "%d %d %d", &day, &mon, &year) != 3 || day < 0 || mon < 0 || year < 0)
            {    
                printf(" Ошибка: некорректный ввод.\n");
                rc = ERR_IO;
            }

            fgetc(f);

            if (rc == ERR_OK)
            {    
                data_t data = { 24 * day, mon, year };
                node_t *node = init_node(str, data);
                *list = add_to_tree_byname(*list, node);
            }

            calc++;
        }
        else    
            rc = ERR_IO;

        free(str);
    }

    return rc;
}

void print_inorder(node_t *tree)
{
    if (tree == NULL)
        return;

    print_inorder(tree->left);
    printf("%s [%d.%d.%d]", tree->filename, tree->data.hour, tree->data.mon, tree->data.year);
    print_inorder(tree->right);
}
