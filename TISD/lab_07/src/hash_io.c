#include "hash_io.h"

static int primes[] = { 7, 11, 13, 19, 29, 31, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 0 };

void print_list(list_t *list)
{   
    printf("{ ");
    while (list)
    {
        printf("\"%s\" ", list->word);
        list = list->next;
    }

    printf("}\n");
}

void print_open_hash(open_hash_table_t *ht)
{   
    printf("Хэш таблица c открытым хэшированием: \n");
    for (size_t i = 0; i < ht->size; i++)
    {   
        if (ht->table[i])
        {   
            printf("i %zu ", i);
            print_list(ht->table[i]);
        }
    }
    printf("Размер: %zu\n", ht->size);
    printf("Простое число: %d\n", primes[ht->prime]);
    printf("Максимальное кол-во коллизий: %ld\n", ht->max_callisia);
}

void print_close_hash(close_hash_table_t *ht)
{
    printf("Хэш таблица c закрытым хэшированием: \n");

    for (size_t i = 0; i < ht->size; i++)
    {   
        if (*ht->table[i].word != '\0')
        {   
            printf("i %zu ", i);
            print_list(&ht->table[i]);
        }
    }
    printf("Размер: %zu\n", ht->size);
    printf("Простое число: %d\n", primes[ht->prime]);
    printf("Максимальное кол-во коллизий: %ld\n", ht->max_callisia);
}
