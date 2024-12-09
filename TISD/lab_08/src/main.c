#include <stddef.h>
#include <string.h>

#include "graph.h"
#include "errcodes.h"
#include "graph_io.h"

int main(void)
{
    int rc = ERR_OK;
    int move = 100;
 
    graph_t *g = NULL;

    g = create_graph(100);

    do
    {   
        move = 100;
        rc = ERR_OK;
        printf("Меню:\n");
        printf("1.Записать полученные граф в файл graph.dot.\n");
        printf("2.Прочитать граф из файла\n");
        printf("3.Добавить узел в граф\n");
        printf("4.Поиск максимального простого пути для узла.\n");
        printf("0.Выход\n");

        scanf("%d", &move);

        while (getchar() != '\n');

        switch (move)
        {   
            case 1:
            {   
                printf("===================================================\n");
                if (g)
                {
                    print_graph(g);

                    printf("Граф был записан в файл.\n");
                }
                else
                    printf("Ошибка, граф - пуст.\n");
                
                break;
            }
            case 2:
            {   
                printf("===================================================\n");
                
                printf("Введите имя файла для чтения графа:\n");

                ssize_t read = 0;
                size_t n = 0;
                char *str = NULL;

                read = getline(&str, &n, stdin);

                if (read > 0)
                {   
                    char *p = strchr(str, '\n');

                    if (p) *p = '\0';

                    if (g)
                        clear_graph(g);

                    rc = fread_graph(str, g);

                    if (rc != ERR_OK)
                        printf("Ошибка чтения.\n");
                }
                
                if (read <= 0)
                {
                    printf("Ошибка, некорректный ввод.\n");
                    rc = ERR_IO;
                }
                break;
            }
            case 3:
            {   
                printf("===================================================\n");
                printf("Введите номера узлов src, dst и вес дуги\n");
                int src = 0, dst = 0, weight = 0; 
                if (scanf("%d %d %d", &src, &dst, &weight) != 3 || src < 0 || dst < 0 || weight < 0)
                    rc = ERR_IO;

                while (getchar() != '\n');
                
                if (src == dst)
                    rc = ERR_IO;

                if (rc == ERR_OK)
                    g = add_to_graph(g, src, dst, weight);

                if (rc != ERR_OK)
                    printf("Ошибка, некорректный ввод\n");
                break;
            }
            case 4:
            {
                printf("===================================================\n");

                int ver = 0;
                printf("Введите узел для которого будут находится пути.\n");

                if (scanf("%d", &ver) != 1 || ver < 0)
                    rc = ERR_IO;
                
                while (getchar() != '\n');

                if (is_empty(g))
                    find_long_way(g, ver);
                else
                    printf("Ошибка, граф - пуст.\n");

                break;
            }
        }
    }
    while (move != 0);

    return ERR_OK;
}