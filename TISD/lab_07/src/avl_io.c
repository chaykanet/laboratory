#include "avl_io.h"

void fprint_node(node_t *node, FILE *f)
{
    if (node->left)
    {    
        fprintf(f, "\t\"%s\" -> \"%s\";\n", node->word,
         node->left->word);
        fprint_node(node->left, f);
    }

    if (node->right)
    {    
        fprintf(f, "\t\"%s\" -> \"%s\";\n", node->word,
         node->right->word);
        fprint_node(node->right, f);
    }
}

void fprint_tree(node_t *tree, FILE *f)
{
    fprintf(f, "digraph G {\n");
    fprintf(f, "\tnode [shape=circle];\n");

    if (tree)
    {
        fprintf(f, "\t\"%s\"; \n", tree->word);

        fprint_node(tree, f);
    }

    fprintf(f, "}\n");
}

void print_inorder(node_t *tree)
{   
    if (tree == NULL)
        return;

    print_inorder(tree->left);
    printf("\"%s\", ", tree->word);
    print_inorder(tree->right);
}

int myscan(char **word, char **help)
{
    size_t n = 0;
    ssize_t read_1 = 0;
    ssize_t read_2 = 0;

    printf("Введите ключевое слово:\n");
    read_1 = getline(word, &n, stdin);

    printf("Введите HELP для этого слова:\n");
    read_2 = getline(help, &n, stdin);
    
    if (read_1 > 0 && read_2 > 0)
    {   
        char *p = strchr(*word, '\n');
        if (p) *p = '\0'; 
        
        p = strchr(*help, '\n');
        if (p) *p = '\0';
        
        if (strlen(*word) >= 20 || strlen(*help) >= 120)
            return ERR_OVERFLOW;

        return ERR_OK;
    }

    return ERR_IO;
}