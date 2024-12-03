#include "avl.h"
#include "avl_io.h"

#include "hash.h"
#include "data.h"
#include "hash_io.h"

#define N 40

#define STAND_SIZE 100
#define STAND_PRIME 0
#define STAND_CALLI 4

char c_words[N][MAX_LEN_WORD] = {
    "int",
    "float", 
    "double",
    "char", 
    "bool",  
    "if", 
    "for", 
    "while", 
    "return", 
    "void", 
    "class", 
    "public", 
    "private", 
    "protected", 
    "namespace", 
    "template", 
    "new", 
    "delete", 
    "static", 
    "inline",
};

char c_help[N][MAX_LEN_HELP] = {
    "Тип данных для целых чисел.",
    "Тип данных для чисел с плавающей запятой.",
    "Тип данных для двойной точности чисел с плавающей запятой.",
    "Тип данных для символов.",
    "Тип данных для логических значений (true/false).",
    "Условный оператор.",
    "Цикл с известным количеством итераций.",
    "Цикл с неизвестным количеством итераций.",
    "Возврат значения из функции.",
    "Функция, не возвращающая значение.",
    "Определение класса.",
    "Уровень доступа - публичный.",
    "Уровень доступа - приватный.",
    "Уровень доступа - защищённый.",
    "Область видимости для идентификаторов.",
    "Шаблоны для создания общих функций.",
    "Оператор для динамического выделения памяти.",
    "Оператор для освобождения динамически выделенной памяти.",
    "Хранение переменной между вызовами функции.",
    "Оптимизация функций на этапе компиляции.",
};

size_t len = 20;

int main(void)
{   
    int rc = ERR_OK;
    int move = 100;
 
    node_t *tree = NULL;

    open_hash_table_t *ht_open = NULL;
    close_hash_table_t *ht_close = NULL;

    ht_open = create_open_hash(STAND_PRIME, STAND_CALLI);
    ht_close = create_close_hash(STAND_PRIME, STAND_CALLI);

    do
    {   
        move = 100;
        printf("Меню:\n");
        printf("1.Записать avl дерево в файл avl.dot.\n");
        printf("2.Совершить обход дерева.\n");
        printf("3.Добавть ключевое слово в avl дерево\n");
        printf("4.Инициализировать дерево и хэш таблицы готовым списком\n");
        printf("5.Добавть ключевое слово в хэш таблицу с открытым хэшированием\n");
        printf("6.Добавть ключевое слово в хэш таблицу с закрытым хэшированием\n");
        printf("7.Вывести хэш таблицу с открытой адресацией\n");
        printf("8.Вывести хэш таблицу с закрытой адресацией\n");
        printf("9.Вывести HELP для введенного слова по дереву avl\n");
        printf("10.Вывести HELP для введенного слова по хэш таблице с открытым хэшированием\n");
        printf("11.Вывести HELP для введенного слова по хэш таблице с закрытым хэшированием\n");
        printf("12.Провести замеры для n элементов\n");
        printf("13.Провести реструкуризацию хэш таблицы с открытым хэшированием\n");
        printf("14.Провести реструкуризацию хэш таблицы с открытым хэшированием\n");
        printf("0.Выход.\n");
        printf("Ожидание ввода.\n");

        scanf("%d", &move);

        while (getchar() != '\n');

        switch (move)
        {
            case 1:
            {   
                tree = balance(tree);

                printf("======================================\n");
                FILE *f = fopen("./avl.dot", "w");
                if (f)
                {
                    fprint_tree(tree, f);
                    fclose(f);
                }
                else
                    printf("Ошибка открытия файла.\n");
                break;
            }
            case 2:
            {   
                printf("======================================\n");

                printf("Дерево: { ");
                print_inorder(tree);
                printf("}\n");
                break;
            }
            case 3:
            {
                printf("======================================\n");
                char *word = NULL;
                char *help = NULL;
                
                rc = myscan(&word, &help);

                if (rc == ERR_OK)
                    tree = insert(tree, word, help);
                else printf("Ошибка: некорректный ввод\n");

                free(word);
                free(help);
                break;
            }
            case 4: // добавление в отрытую хэш таблицу
            {   
                printf("======================================\n");
                free_tree(tree);
                tree = NULL;
                free_open_hash_table(ht_open);
                ht_open = NULL;
                free_close_hash_table(ht_close);
                ht_close = NULL;

                ht_open = create_open_hash(STAND_PRIME, STAND_CALLI);
                ht_close = create_close_hash(STAND_PRIME, STAND_CALLI);
            
                for (size_t i = 0; i < len; i++)
                    ht_open = insert_open_hash(ht_open, c_words[i], c_help[i]);
                for (size_t i = 0; i < len; i++)
                    ht_close = insert_close_hash(ht_close, c_words[i], c_help[i]);
                for (size_t i = 0; i < len; i++)
                    tree = insert(tree, c_words[i], c_help[i]);

                FILE *f = fopen("./data.txt", "w");
                for (size_t i = 0; i < len; i++)
                {
                    fprintf(f, "%s\n%s\n", c_words[i], c_help[i]);
                }
                fclose(f);

                printf("Инициализация произошла\n");
                break;
            }
            case 5:
            {   
                printf("======================================\n");
                char *word = NULL;
                char *help = NULL;
            
                rc = myscan(&word, &help);
                
                if (rc == ERR_OK)
                    ht_open = insert_open_hash(ht_open, word, help);
                else printf("Ошибка: некорректный ввод\n");
                
                free(word);
                free(help);
                break;
            }
            case 6:
            {
                printf("======================================\n");
                char *word = NULL;
                char *help = NULL;
            
                rc = myscan(&word, &help);
                
                if (rc == ERR_OK)
                    ht_close = insert_close_hash(ht_close, word, help);
                else printf("Ошибка: некорректный ввод\n");

                free(word);
                free(help);
                break;
            }
            case 7:
            {
                printf("======================================\n");
                print_open_hash(ht_open);
                break;
            }
            case 8:
            {   
                printf("======================================\n");
                print_close_hash(ht_close);
                break;
            }
            case 9:
            {   
                printf("======================================\n");
                node_t *find = NULL;
                char *word = NULL;
                size_t calc = 0;
                size_t n = 0;
                ssize_t read = 0;
                printf("Введите ключевое слово:\n");

                read = getline(&word, &n, stdin);

                if (read > 0)
                {   
                    char *p = strchr(word, '\n');
                    if (p) *p = '\0';

                    find = search_tree(tree, &calc, word);
                }
                if (find)
                {
                    printf("HELP: %s\n", find->help);
                    printf("Кол-во сравнений: %zu\n", calc);
                }
                else 
                {
                    printf("Ключевое слово не найдено\n");
                    printf("Кол-во сравнений: %zu\n", calc);
                }

                free(word);
            
                break;
            }
            case 10:
            {   
                printf("======================================\n");
                list_t *find = NULL;
                char *word = NULL;
                size_t calc = 0;
                size_t n = 0;
                ssize_t read = 0;
                printf("Введите ключевое слово:\n");

                read = getline(&word, &n, stdin);

                if (read > 0)
                {   
                    char *p = strchr(word, '\n');
                    if (p) *p = '\0';
                    find = search_open_hash(ht_open, &calc, word);
                }
                if (find)
                {
                    printf("HELP: %s\n", find->help);
                    printf("Кол-во сравнений: %zu\n", calc);
                }
                else 
                {
                    printf("Ключевое слово не найдено\n");
                    printf("Кол-во сравнений: %zu\n", calc);
                }

                free(word);
            
                break;
            }
            case 11:
            {   
                printf("======================================\n");
                list_t *find = NULL;
                char *word = NULL;
                size_t calc = 0;
                size_t n = 0;
                ssize_t read = 0;
                printf("Введите ключевое слово:\n");
                read = getline(&word, &n, stdin);

                if (read > 0)
                {   
                    char *p = strchr(word, '\n');
                    if (p) *p = '\0';
                    find = search_close_hash(ht_close, &calc, word);
                }
                if (find)
                {
                    printf("HELP: %s\n", find->help);
                    printf("Кол-во сравнений: %zu\n", calc);
                }
                else 
                {
                    printf("Ключевое слово не найдено\n");
                    printf("Кол-во сравнений: %zu\n", calc);
                }

                free(word);
            
                break;
            }
            case 12:
            {   
                printf("======================================\n");
                rc = make_searches();
                break;
            }
            case 13:
            {   
                printf("======================================\n");
                printf("Простые числа: 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151 }\n");
                printf("Введите номер простого числа 0 <= i <= 18\n");
                int p = 0;
                int max_call = 0;
                if (scanf("%d", &p) != 1 || p < 0 || p > 18)
                {
                    rc = ERR_IO;
                    break;
                }
                printf("Введите кол-во макс. каллизий  от >= 2\n");
                if (scanf("%d", &max_call) != 1 || max_call <= 1)
                {
                    rc = ERR_IO;
                    break;
                }

                ht_open = recreate_open_hash(ht_open, p, max_call);

                break;
            }
            case 14:
            {   
                printf("======================================\n");
                printf("Простые числа: 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151 }\n");
                printf("Введите номер простого числа 0 <= i <= 18\n");
                int p = 0;
                int max_call = 0;
                if (scanf("%d", &p) != 1 || p < 0 || p > 18)
                {
                    rc = ERR_IO;
                    break;
                }
                printf("Введите кол-во макс. каллизий  от >= 2\n");
                if (scanf("%d", &max_call) != 1 || max_call <= 1)
                {
                    rc = ERR_IO;
                    break;
                }

                ht_close = recreate_close_hash(ht_close, p, max_call);

                break;
            }
            default:
                break;
        }

        if (rc != ERR_OK)
        {
            printf("Код ошибки: %d\n", rc);
        }
    }
    while (move != 0);

    free_open_hash_table(ht_open);
    
    free_close_hash_table(ht_close);

    free_tree(tree);
    
    return 0;
}