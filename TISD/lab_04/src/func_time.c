#include "stack.h"
#include "func_time.h"

int add_n_chars_stack(stack_t *stack, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = add_tostack(stack, '1');

    return rc;
}

int pop_n_chars_stack(stack_t *stack, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = pop_frmstack(stack);

    return rc;
}

int add_n_chars_list(list_t *list, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = add_tolist(list, '1');

    return rc;
}

int pop_n_chars_list(list_t *list, size_t const n)
{   
    int rc = ERR_OK;
    for (size_t i = 0; i < n && rc == ERR_OK; i++)
        rc = pop_frmlist(list);

    return rc;
}
