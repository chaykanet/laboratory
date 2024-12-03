#include "list.h"

void free_list(list_t *list)
{
    while (list)
    {   
        list_t *p = list;
        
        list = list->next;

        free(p);
    }

    free(list);
}

size_t len_list(list_t *list)
{       
    size_t calc = 0;
    while (list)
    {       
        calc++;
        list = list->next;
    }

    return calc;
}

list_t *create_el(char *word, char *help)
{
    list_t *p = malloc(sizeof(list_t));

    if (p)
    {
        strcpy(p->word, word);
        strcpy(p->help, help);
        p->next = NULL;
    }

    return p;
}

list_t *take_frm_list(list_t *list, char *taken_word, char *taken_help)
{
    if (list == NULL)
        return NULL;
    
    list_t *p = list->next;

    strcpy(taken_word, list->word);

    strcpy(taken_help, list->help);

    free(list);

    return p;
}

list_t *add_to_list(list_t *list, char *word, char *help)
{
    if (list == NULL)
    {
        list_t *p = malloc(sizeof(list_t));
        p = create_el(word, help);
        return p;
    }

    if (strcmp(list->word, word) == 0)
        return list;

    list_t *p = list;

    while (p->next)
    {   
        if (strcmp(p->next->word, word) == 0)
            return list;

        p = p->next;
    }

    p->next = create_el(word, help);

    return list;
}

list_t *find_el(list_t *list, size_t *calc, char *word)
{   
    if (list == NULL)
        return NULL;

    *calc = 1;

    while (list)
    {   
        if (strcmp(list->word, word) == 0)
            return list;

        (*calc)++;

        list = list->next;
    }

    return list;
}

// list_t *pop_list(list_t *list, char *word)
// {   
//     if (list == NULL)
//         return NULL;

//     list_t *p = list->next;

//     if (strcmp(list->word, word) == 0)
//     {   
//         free(list);
//         return p;
//     }
//     list_t *prev = list;

//     while (p)
//     {
//         if (strcmp(p->word, word) == 0)
//         {   
//             prev->next = p->next;
//             free(p);
//             return list;
//         }
//         prev = prev->next;
//         p = p->next;
//     }

//     return list;
// }
