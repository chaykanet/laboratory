#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tree.h"
#include "data.h"
#include "tree_io.h"

int main(void)
{   
    int rc = ERR_OK;
    int move = 100;
    
    node_t *tree_name = NULL;

    node_t *tree_data = NULL;

    do
    {   
        move = 100;
        printf("Меню:\n");
        printf("1.Записать дерево по имени в файл tree_name.dot.\n");
        printf("2.Записать дерево по дате в файл tree_data.dot.\n");
        printf("3.Добавить в дерево элемент по имени.\n");
        printf("4.Добавить в дерево элемент по дате.\n");
        printf("5.Удалить файл из дерева по имени.\n");
        printf("6.Удалить файлы из дерева старше введенной даты.\n");
        printf("7.Сравнить время удаления файлов из деревьев из n файлов по имени и дате.\n");
        printf("8.Прочесть из файла дерево по алфавиту\n");
        printf("9.Очистить дерево по алфавиту\n");
        printf("10.Очистить древо по дате\n");
        printf("11.Перестроить дерево по алфавиту в дерево по дате.\n");
        printf("12.Совершить обход деревьев.\n");
        printf("0.Выход.\n");
        printf("Ожидание ввода.\n");

        scanf("%d", &move);

        while (getchar() != '\n');

        switch (move)
        {
        case 1:
        {   
            printf("======================================\n");
            FILE *f = fopen("./tree_name.dot", "w");

            if (f)
            {
                fprint_tree(tree_name, f);
                fclose(f);
            }
            else
                printf("Ошибка открытия файла.\n");
            break;
        }
        case 2:
        {   
            printf("======================================\n");
            FILE *f = fopen("./tree_data.dot", "w");

            if (f)
            {
                fprint_tree(tree_data, f);
                fclose(f);
            }
            else
                printf("Ошибка открытия файла.\n");
            break;
        }
        case 3:
        {
            printf("======================================\n");

            printf("Введите имя файла: \n");

            char *filename = NULL;
            size_t n = 0;
            ssize_t read = 0;

            read = getline(&filename, &n, stdin);

            if (read > 0)
            {
                char *p = strchr(filename, '\n');
                if (p)
                    *p = '\0';

                printf("Введите день, месяц, год в формате [ДД MM ГГГГ]:\n");

                int day, mon, year;
                rc = ERR_OK;
                if (scanf("%d %d %d", &day, &mon, &year) != 3 || day < 0 || mon < 0 || year < 0)
                {    
                    printf(" Ошибка: некорректный ввод.\n");
                    rc = ERR_IO;
                }

                if (rc == ERR_OK)
                {   
                    data_t data = { 24 * day, mon, year };

                    node_t *node = init_node(filename, data);

                    tree_name = add_to_tree_byname(tree_name, node);
                }
                
                free(filename);
            }
            else
                rc = ERR_IO;
            break;
        }
        case 4:
        {
            printf("======================================\n");

            printf("Введите имя файла: \n");

            char *filename = NULL;
            size_t n = 0;
            ssize_t read = 0;

            read = getline(&filename, &n, stdin);

            if (read > 0)
            {
                char *p = strchr(filename, '\n');
                if (p)
                    *p = '\0';

                printf("Введите день, месяц, год в формате [ДД MM ГГГГ]:\n");

                int day, mon, year;
                rc = ERR_OK;
                if (scanf("%d %d %d", &day, &mon, &year) != 3 || day < 0 || mon < 0 || year < 0)
                {    
                    free(filename);
                    printf(" Ошибка: некорректный ввод.\n");
                    rc = ERR_IO;
                }

                rc = check_data(day, mon);

                if (rc == ERR_OK)
                {   
                    data_t data = { 24 * day, mon, year };

                    node_t *node = init_node(filename, data);
    
                    tree_data = add_to_tree_bydata(tree_data, node);
                }
                else
                {   
                    printf("Ошибка: некорректный ввод.\n");
                }
            }
            else
            {   
                printf("Ошибка: некорректный ввод.\n");
                rc = ERR_IO;
            }
            break;
        }
        case 5:
        {
            printf("======================================\n");
            printf("Введите имя файла: \n");

            if (tree_name == NULL)
            {
                printf("Ошибка: Дерево пустое\n");
                break;
            }

            char *filename = NULL;
            size_t n = 0;
            ssize_t read = 0;

            read = getline(&filename, &n, stdin);

            if (read > 0)
            {   
                int err = ERR_OK;
                char *p = strchr(filename, '\n');
                
                if (p)
                    *p = '\0';

                tree_name = delete_node_byname(tree_name, filename, &err);
                
                if (err != ERR_OK)
                    printf("Узел не найден\n");

                free(filename);
            }
            else
            {   
                printf("Ошибка: некорректный ввод.\n");
                rc = ERR_IO;
            }
            break;
        }
        case 6:
        {
            printf("======================================\n");
            if (tree_data)
            {   
                printf("Введите день, месяц, год в формате  [ ДД MM ГГГГ ]:\n");
                
                int day, mon, year;

                if (scanf("%d %d %d", &day, &mon, &year) != 3 || day <= 0 || mon <= 0 || year <= 0)
                {    
                    rc = ERR_IO;
                }

                if (rc == ERR_OK)
                    rc = check_data(day, mon);

                if (rc == ERR_OK)
                {   
                    data_t data = { 24 * day, mon, year };
                    tree_data = delete_less_data(tree_data, data);
                }
                else
                    printf(" Ошибка: некорректный ввод.\n");
            }
            else
            {
                printf("Ошибка: Дерево пустое\n");
            }
            break;
        }
        case 7:
        {   
            printf("======================================\n");

            int n = 0;

            printf("Введите кол-во элементов:\n");

            if (scanf("%d", &n) != 1 || n <= 0)
                rc = ERR_IO;

            if (rc == ERR_OK)
            {   
                FILE *data = fopen("data.txt", "r");

                if (data)
                {
                    rc = make_n_times(data, n);

                    fclose(data);
                }
            }
            else
                printf("Ошибка: некорректный ввод.\n");

            break;
        }
        case 8:
        {
            printf("======================================\n");

            printf("Введите имя файла: \n");

            free_tree(tree_name);
            
            tree_name = NULL;
            
            ssize_t read = 0;
            size_t n = 0;
            char *filename = NULL;

            read = getline(&filename, &n, stdin);

            if (read > 0)
            {   
                char *p = strchr(filename, '\n');
    
                if (p)
                    *p = '\0';
                
                FILE *file = fopen(filename, "r");

                if (file)
                {
                    rc = fnread_tree(file, n, &tree_name);
                    fclose(file);
                }
            }

            free(filename);
            break;
        }
        case 9:
        {
            printf("======================================\n");

            free_tree(tree_name);

            tree_name = NULL;

            printf("Дерево по алфавиту очищено\n");
            break;
        }
        case 10:
        {
            printf("======================================\n");

            free_tree(tree_data);

            tree_data = NULL;

            printf("Дерево по дате очищено\n");
            break;
        }
        case 11:
        {
            printf("======================================\n");
            
            free_tree(tree_data);
            
            tree_data = NULL;

            tree_data = rebuild_tree_data(tree_name);

            tree_name = NULL;

            printf("Дерево перестроено по дате\n");

            break;
        }
        case 12:
        {   
            printf("======================================\n");
            printf("Дерево по алфавиту: { ");
            print_inorder(tree_name);
            printf(" }\n");

            printf("Дерево по дате: { ");
            print_inorder(tree_data);
            printf("}\n");
        }
        default:
            break;
        }
        
        if (rc != ERR_OK)
        {
            printf("Код ошибки %d\n", rc);
        }
        
        rc = ERR_OK;
    } while (move != 0);

    free_tree(tree_name);

    free_tree(tree_data);

    return rc;
}
