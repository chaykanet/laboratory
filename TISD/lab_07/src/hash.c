#include "hash.h"

#include <stdio.h>

static int primes[] = { 7, 11, 13, 19, 29, 31, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 0 };

unsigned int to_hash(const char *word, const int prime)
{
    int ascii = 0;

    for (char *p = (char *) word; *p != '\0'; p++)
    {
        ascii += *p;
    }
    
    return ascii % primes[prime];
}

void free_open_hash_table(open_hash_table_t *ht)
{
    if (ht)
    {
        for (size_t i = 0; i < ht->size; i++)
            free_list(ht->table[i]);

        free(ht->table);

        free(ht);
    }
}

void free_close_hash_table(close_hash_table_t *ht)
{
    if (ht)
    {
        free(ht->table);

        free(ht);
    }
}

list_t *search_open_hash(open_hash_table_t *ht, size_t *calc, char *word)
{
    int index = to_hash(word, ht->prime);

    return find_el(ht->table[index], calc, word);
}

list_t *search_close_hash(close_hash_table_t *ht, size_t *calc, char *word)
{
    int index = to_hash(word, ht->prime);
   
    *calc = 0;
    while ((size_t) index < ht->size && *calc < ht->max_callisia)
    {   
        (*calc)++;
        if (strcmp(ht->table[index].word, word) == 0)
            return &ht->table[index];
        index++;
    }
    return NULL;
}

open_hash_table_t *create_open_hash(int prime, int max_call)
{
    open_hash_table_t *table = malloc(sizeof(open_hash_table_t));

    size_t size = (size_t) primes[prime];

    if (table)
    {
        table->table = calloc(size, sizeof(list_t *));

        table->prime = prime;

        table->max_callisia = max_call;

        table->size = size;
    }

    return table;
}

close_hash_table_t *create_close_hash(int prime, int max_call)
{
    close_hash_table_t *table = malloc(sizeof(close_hash_table_t));
    
    size_t size = max_call * primes[prime] + 1;

    if (table)
    {
        table->table = calloc(size, sizeof(list_t));

        table->prime = prime;

        table->max_callisia = max_call;

        table->size = size;
    }

    return table;
}

open_hash_table_t *recreate_open_hash(open_hash_table_t *ht, int prime, int max_callisia)
{
    if (primes[prime] == 0)
    {   
        printf("Реструктизация не возможна\n");
        return ht;
    }

    open_hash_table_t *new_ht = create_open_hash(prime, max_callisia);

    for (size_t i = 0; i < ht->size; i++)
    {   
        while (ht->table[i])
        {   
            char tmp_word[MAX_LEN_WORD] = { 0 };
            char tmp_help[MAX_LEN_HELP] = { 0 };

            ht->table[i] = take_frm_list(ht->table[i], tmp_word, tmp_help);

            new_ht = insert_open_hash(new_ht, tmp_word, tmp_help);
        } 
    }

    free_open_hash_table(ht);

    return new_ht;
}

close_hash_table_t *recreate_close_hash(close_hash_table_t *ht, int prime, int max_callisia)
{   
    if (primes[prime] == 0)
    {   
        printf("Реструктизация не возможна\n");
        return ht;
    }

    close_hash_table_t *new_ht = create_close_hash(prime, max_callisia);

    for (size_t i = 0; i < ht->size; i++)
    {   
        if (*ht->table[i].word != '\0')
        {   
            char tmp_word[MAX_LEN_WORD] = { 0 };
            char tmp_help[MAX_LEN_HELP] = { 0 };

            strcpy(tmp_word, ht->table[i].word);
            strcpy(tmp_help, ht->table[i].help);

            new_ht = insert_close_hash(new_ht, tmp_word, tmp_help);
        } 
    }

    free_close_hash_table(ht);

    return new_ht;
}

open_hash_table_t *insert_open_hash(open_hash_table_t *ht, char *word, char *help)
{
    int index = to_hash(word, ht->prime);

    ht->table[index] = add_to_list(ht->table[index], word, help);

    size_t call = len_list(ht->table[index]);
    
    if (call == ht->max_callisia)
        ht = recreate_open_hash(ht, ht->prime + 1, ht->max_callisia);

    return ht;
}

close_hash_table_t *insert_close_hash(close_hash_table_t *ht, char *word, char *help)
{
    int index = to_hash(word, ht->prime);
    size_t call = 0;

    while (call < ht->max_callisia && index + call < ht->size)
    {
        if (*ht->table[index + call].word == '\0' || strcmp(ht->table[index + call].word, word) == 0)
            break;
        
        call++;
    }
    
    if (call == ht->max_callisia || index + call == ht->size)
    {   
        strcpy(ht->table[ht->size - 1].word, word);
        strcpy(ht->table[ht->size - 1].help, help);
        ht = recreate_close_hash(ht, ht->prime + 1, ht->max_callisia);
    }
    else
    {
        strcpy(ht->table[index + call].word, word);
        strcpy(ht->table[index + call].help, help);
    }
    
    return ht;
}

// open_hash_table_t *delete_open_hash(open_hash_table_t *ht, char *word)
// {
//     int index = to_hash(word, ht->prime);

//     ht->table[index] = pop_list(ht->table[index], word);

//     return ht;
// }

// close_hash_table_t *delete_close_hash(close_hash_table_t *ht, char *word)
// {
//     int index = to_hash(word, ht->prime);

//     size_t i = 0;

//     while (i < ht->max_callisia)
//     {
//         if (strcmp(ht->table[index + i].word, word) == 0)
//             memset(&ht->table[index + i], 0, sizeof(list_t));
//         i++;
//     }   

//     return ht;
// }