#ifndef __LIST_H_
#define __LIST_H_

#include "avl.h"

typedef struct list // список;
{
    char word[MAX_LEN_WORD];

    char help[MAX_LEN_HELP];

    struct list *next;
} list_t;

void free_list(list_t *list);

size_t len_list(list_t *list);

list_t *create_el(char *word, char *help);

list_t *find_el(list_t *list, size_t *calc, char *word);

list_t *add_to_list(list_t *list, char *word, char *help);

list_t *take_frm_list(list_t *list, char *taken_word, char *taken_help);

#endif
