#include "stack_postfix.h"

static int priority(char const c)
{   
    if (strchr("^", c))
        return 3;
    
    if (strchr("*/", c))
        return 2;

    if (strchr("+-", c))
        return 1;

    if (strchr("()", c))
        return 0;

    return 0;
}

int check_expression(char *expression)
{   

    char *point = strchr(expression, '.');

    if (point == expression)
        return ERR_IO;

    while (point)
    {   
        point = strchr(point, '.');

        if (!point || !strchr(NUMS, *(point - 1)) || !strchr(NUMS, *(point + 1)))
            return ERR_IO;
    }

    char *oper_l = strpbrk(expression, OPERATORS);

    while (oper_l)
    {   

        if (!strchr(")", *(oper_l - 1)) || !strchr("(", *(oper_l + 1)))
            if (!strchr(NUMS, *(oper_l - 1)) || !strchr(NUMS, *(oper_l + 1)))
                return ERR_IO;

        oper_l = strpbrk(oper_l + 1, OPERATORS);
    }

    bool left = false, right = false;
    for (char *p = expression; *p != '\0'; p++)
    {
        if (!strchr(OPERATORS, *p) && !strchr(NUMS, *p) && *p != '.' && !strchr("()", *p))
            return ERR_IO;

        if (*p == '(')
            left = true;
        if (*p == ')')
            right = true;
        
        if (!left && right)
            return ERR_IO;

        if (left && right)
        {
            left = false;
            right = false;
        }
    }

    if (left && !right)
        return ERR_IO;
    
    return ERR_OK;
}

int convert_topostfix_stack(char *postfix, char *expression, stack_t *stack_store)
{   
    int rc = ERR_OK;

    bool left = false;
    bool right = false;

    char symbol;
    char *pres = postfix;

    int pr = 0, prprev = 0;

    stack_t stack;

    init_stack(&stack); 

    for (char *p = expression; *p != '\0' && rc == ERR_OK; p++)
    {   
        if (strchr(OPERATORSBRACKETS, *p))
        {   
            if (*p == '(')
                left = true;

            if (*p == ')')
                right = true;
             
            pr = priority(*p);
            
            if (pr <= prprev && pr != 0)
            {   
                symbol = '\0';

                while (symbol != '(' && rc == ERR_OK)
                {
                    rc = take_frmstack(&stack, &symbol);
                
                    if (rc == ERR_OK && symbol != '(')
                    {
                        *pres = symbol;
                        pres++;
                    }
                }
            }
            else
                prprev = pr;
        
            if (right && left)
            {   
                symbol = '\0';

                while (symbol != '(' && rc == ERR_OK)
                {
                    rc = take_frmstack(&stack, &symbol);
                    
                    if (rc == ERR_OK && symbol != '(')
                    {
                        *pres = symbol;
                        pres++;
                    }
                }
                
                left = false;
                right = false;
            }
            else
            {
                rc = add_tostack(&stack, *p);
                add_tostack(stack_store, *p);
            }
            
        }
        else
        {
            *pres = *p;
            pres++;
        }
    }

    rc = ERR_OK;

    while (rc == ERR_OK)
    {
        rc = take_frmstack(&stack, &symbol);
        if (rc == ERR_OK)
        {
            *pres = symbol;
            pres++;
        }
    }   

    free(stack.massive);
    stack.phead = NULL;

    return ERR_OK;
}

int convert_topostfix_list(char *postfix, char *expression, list_t *list_store)
{   
    int rc = ERR_OK;

    bool left = false;
    bool right = false;

    char symbol;
    char *pres = postfix;

    int pr = 0, prprev = 0;

    list_t *stack;

    init_list(&stack); 

    for (char *p = expression; *p != '\0' && rc == ERR_OK; p++)
    {   
        if (strchr(OPERATORSBRACKETS, *p))
        {   
            if (*p == '(')
                left = true;

            if (*p == ')')
                right = true;
             
            pr = priority(*p);
            
            if (pr <= prprev && pr != 0)
            {   
                symbol = '\0';
                int rc = ERR_OK;
                while (symbol != '(' && rc == ERR_OK)
                {
                    rc = take_frmlist(stack, &symbol);
                    
                    if (symbol != '\0' && symbol != '(')
                    {
                        *pres = symbol;
                        pres++;
                    }
                }
            }
            else
                prprev = pr;
        
            if (right && left)
            {   
                symbol = '\0';

                while (symbol != '(' && rc == ERR_OK)
                {
                    rc = take_frmlist(stack, &symbol);

                    if (rc == ERR_OK && symbol != '(')
                    {
                        *pres = symbol;
                        pres++;
                    }
                }
                
                left = false;
                right = false;
            }
            else
            {
                rc = add_tolist(stack, *p);
                add_tolist(list_store, *p);
            }
            
        }
        else
        {
            *pres = *p;
            pres++;
        }
    }

    rc = ERR_OK;

    while (rc == ERR_OK)
    {
        rc = take_frmlist(stack, &symbol);
        if (symbol)
        {
            *pres = symbol;
            pres++;
        }
    }

    if (stack)
        free_list(stack);

    return ERR_OK;
}
