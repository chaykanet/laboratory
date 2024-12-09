#include "data.h"
#include "hash_io.h"

size_t calc_mem_open_hash(open_hash_table_t *ht)
{
    size_t v = sizeof(open_hash_table_t);

    v += ht->size * sizeof(list_t *);

    for (size_t i = 0; i < ht->size; i++)
        v += len_list(ht->table[i]) * sizeof(list_t);
    
    return v;
}

size_t calc_mem_close_hash(close_hash_table_t *ht)
{
    size_t v = sizeof(close_hash_table_t);
  
    v += sizeof(list_t) * ht->size;

    return v;
}

int make_searches(void)
{
    int rc = ERR_OK;
    int tmp = 0;
    double st = 0;
    double en = 0;
    double t_close = 0, t_open = 0, t_tree = 0;

    double ins_avl = 0;
    double ins_open_hash = 0;
    double ins_close_hash = 0;

    list_t *list = NULL;
    node_t *node = NULL;
    size_t calc_tree = 0;
    size_t calc_open = 0;
    size_t calc_close = 0;

    char *word = NULL;
    char *help = NULL;

    char w[MAX_LEN_WORD] = { 0 };

    printf("Введите кол-во элементов 0 < n <= 60\n");
    if (scanf("%d", &tmp) != 1 || tmp < 0 || tmp > 60)
        return ERR_IO;

    size_t n = (size_t) tmp;
    size_t c = 0;

    node_t *tree = NULL;
    open_hash_table_t *ht_open = NULL;
    close_hash_table_t *ht_close = NULL;

    ht_open = create_open_hash(0, 10);
    ht_close = create_close_hash(0, 10);

    FILE *f = fopen("data.txt", "r");
    char *p = NULL;
    
    st = clock();
    for (size_t i = 0; i < n; i++)
    {
        getline(&word, &c, f);
        getline(&help, &c, f);
        p = strchr(word, '\n');
        if (p) *p = '\0';
        p = strchr(help, '\n');
        if (p) *p = '\0';
        ht_open = insert_open_hash(ht_open, word, help);
    }
    en = clock();
    ins_open_hash = (double) (en - st) / CLOCKS_PER_SEC * 1000;
    rewind(f);
    st = clock();
    for (size_t i = 0; i < n; i++)
    {
        getline(&word, &c, f);
        getline(&help, &c, f);
        p = strchr(word, '\n');
        if (p) *p = '\0';
        p = strchr(help, '\n');
        if (p) *p = '\0';
        ht_close = insert_close_hash(ht_close, word, help);
    }
    en = clock();

    ins_close_hash = (double) (en - st) / CLOCKS_PER_SEC * 1000;
    rewind(f);
    
    st = clock();
    for (size_t i = 0; i < n; i++)
    {
        getline(&word, &c, f);
        getline(&help, &c, f);
    
        p = strchr(word, '\n');
        if (p) *p = '\0';
        p = strchr(help, '\n');
        if (p) *p = '\0';
        tree = insert(tree, word, help);
    }
    en = clock();

    ins_avl = (double) (en - st) / CLOCKS_PER_SEC * 1000;
    fclose(f);

    free(word);
    free(help);

    node_t *min = find_min(tree);

    if (min)
        strcpy(w, min->word);

    st = clock();
    node = search_tree(tree, &calc_tree, w);
    en = clock();
    t_tree = (double) (en - st) / CLOCKS_PER_SEC * 1000;
    st = clock();
    list = search_open_hash(ht_open, &calc_open, w);
    en = clock();
    t_open = (double) (en - st) / CLOCKS_PER_SEC * 1000;
    st = clock();
    list = search_close_hash(ht_close, &calc_close, w);
    en = clock();
    t_close = (double) (en - st) / CLOCKS_PER_SEC * 1000;

    printf("Поиск минимального элемента:\n");

    printf("Tree: %s\n", node->word);
    printf("Hash: %s\n", list->word);

    printf("Время выполнения поиска для дерева avl: %lf (мс.)\n", t_tree);
    printf("Кол-во сравнений: %zu\n", calc_tree);
    printf("Объем занимаемой памяти: %lu\n\n", sizeof(node_t) * n);

    printf("Время выполнения поиска для открытой хэш таблицы: %lf (мс.)\n", t_open);
    printf("Кол-во сравнений: %zu\n", calc_open);
    printf("Объем занимаемой памяти: %lu\n\n", calc_mem_open_hash(ht_open));

    printf("Время выполнения поиска для закрытой хэш таблицы: %lf (мс.)\n", t_close);
    printf("Кол-во сравнений: %zu\n", calc_close);
    printf("Объем занимаемой памяти: %lu\n\n", calc_mem_close_hash(ht_close));

    printf("Ср. время добавление элементов для дерева: %lf\n", ins_avl / n);
    printf("Ср. время добавление элементов для открытой хэш таблицы: %lf\n", ins_open_hash / n);
    printf("Ср. время добавление элементов для закрытой хэш таблицы: %lf\n\n", ins_close_hash / n);

    free_tree(tree);
    free_open_hash_table(ht_open);
    free_close_hash_table(ht_close);

    return rc;
}