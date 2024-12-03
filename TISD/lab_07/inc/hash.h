#ifndef __HASH_H_
#define __HASH_H_

#include "avl.h"
#include "list.h"

#include <stdlib.h>

typedef struct open_hash_table
{
    list_t **table;

    int prime;

    size_t max_callisia;

    size_t size;

} open_hash_table_t;

typedef struct close_hash_table
{
    list_t *table;

    int prime;

    size_t max_callisia;

    size_t size;

} close_hash_table_t;

void free_open_hash_table(open_hash_table_t *ht);

void free_close_hash_table(close_hash_table_t *ht);

unsigned int to_hash(const char *word, const int prime);


list_t *search_open_hash(open_hash_table_t *ht, size_t *calc, char *word);

list_t *search_close_hash(close_hash_table_t *ht, size_t *calc, char *word);


open_hash_table_t *create_open_hash(int prime, int max_callisia);

open_hash_table_t *insert_open_hash(open_hash_table_t *ht, char *word, char *help);

open_hash_table_t *recreate_open_hash(open_hash_table_t *ht, int prime, int max_callisia);


close_hash_table_t *create_close_hash(int prime, int max_callisia);

close_hash_table_t *insert_close_hash(close_hash_table_t *ht, char *word, char *help);

close_hash_table_t *recreate_close_hash(close_hash_table_t *ht, int prime, int max_callisia);

#endif
