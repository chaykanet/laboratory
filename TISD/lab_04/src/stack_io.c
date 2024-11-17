#include "stack_io.h"

void print_stack(stack_t *stack)
{
    stack_t tmp;

    init_stack(&tmp);

    int rc = ERR_OK;
    char taken;
    
    printf ("Стек как массив: { ");

    while (rc == ERR_OK)
    {   
        rc = take_frmstack(stack, &taken);
        if (rc == ERR_OK)
        {
            printf("%c ", taken);

            add_tostack(&tmp, taken);
        }
    }

    printf ("}\n");

    rc = ERR_OK;

    rc = take_frmstack(&tmp, &taken);
    
    while (rc == ERR_OK)
    {   
        add_tostack(stack, taken);
        rc = take_frmstack(&tmp, &taken);
    }

    if (tmp.massive)
        free(tmp.massive);
}

void print_list(list_t *head)
{   
    list_t *tmp;

    init_list(&tmp);

    char taken;

    int rc = ERR_OK;

    printf ("Стек как список: { ");
    while (rc == ERR_OK)
    {   
        rc = take_frmlist(head, &taken);

        if (rc == ERR_OK)
        {   
            printf("%c ", taken);
            add_tolist(tmp, taken);
        }
    }

    printf ("}\n");

    rc = take_frmlist(tmp, &taken);

    while (rc == ERR_OK)
    {
        add_tolist(head, taken);
        rc = take_frmlist(tmp, &taken);
    }

    if (tmp)
        free_list(tmp);
}

void print_adr(char **adr, size_t const n)
{   
    printf("Освобожденная память: { ");
    for (size_t i = 0; i < n; i++)
        if (adr[i])
            printf("%p ", (void *) adr[i]);

    printf("}\n");
}