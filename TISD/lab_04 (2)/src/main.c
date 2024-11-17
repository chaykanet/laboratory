#include "stack.h"
#include "errcodes.h"
#include "stack_io.h"
#include "func_time.h"
#include "stack_postfix.h"
#include <time.h>

#define MAX_LEN_STR 256
#define MAX_LEN_BUFFER 2000

int main(void)
{
    int rc = ERR_OK, err = ERR_OK;
    char symbol;

    int move = 100;

    stack_t stack;
    stack_t stack_store;
    stack_t stack_time;

    rc = init_stack(&stack);
    rc = init_stack(&stack_store);
    rc = init_stack(&stack_time);

    list_t *list = NULL;
    list_t *list_store = NULL;
    list_t *list_time = NULL;

    rc = init_list(&list);
    rc = init_list(&list_store);
    rc = init_list(&list_time);

    char *expression = NULL;
    size_t expression_len = 0;

    double start, end;
    double time_stack = 0, time_list = 0;

    char *adr[MAX_LEN_BUFFER];

    void *pa;

    size_t clc_p = 0;

    ssize_t read = 0;
    
    char *postfix = NULL;
    do
    {
        printf("Меню: \n");
        printf("1. Вывести стек массива.\n");
        printf("2. Вывести стек списка.\n");
        printf("3. Добавить элемент в стек массива.\n");
        printf("4. Добавить элемент в стек списка.\n");
        printf("5. Получить обратную польскую запись со стеком массива.\n");
        printf("6. Получить обратную польскую запись со стеком списка.\n");
        printf("7. Получить историю стека для польской записи со стеком массива.\n");
        printf("8. Получить историю стека для польской записи со стеком списка.\n");
        printf("9. Удалить элемент из стека массива.\n");
        printf("10. Удалить элемент из стека списка.\n");
        printf("11. Замерить время добавления и удаления 1000 элементов для массива.\n");
        printf("12. Вывести результаты времени выполнения обратной польской записи.\n");
        printf("13. Вывести освобожденные адреса.\n");
        printf("0. Выход.\n");
        printf("Ожидание ввода: \n");

        rc = scanf("%d", &move);

        if (rc != 1) 
        {
            printf("Неверный номер действия.\n");
            
            while (getchar() != '\n');

            continue;
        }

        switch (move)
        {
            case 1:
                printf("--------------------------\n");
                print_stack(&stack);
            break;
            case 2:
                printf("--------------------------\n");
                print_list(list);
            break;
            case 3:
                printf("--------------------------\n");
                printf("Введите символ: \n");

                scanf(" %c", &symbol);
                while (getchar() != '\n');
                err = add_tostack(&stack, symbol);

                if (err == ERR_OVERFLOW)
                    printf("Стека переполнен.\n");
            break;
            case 4:
                printf("--------------------------\n");
                printf("Введите символ: \n");
                scanf(" %c", &symbol);
                while (getchar() != '\n');

                err = add_tolist_adr(list, symbol, &pa);

                for (size_t i = 0; i < clc_p; i++)
                    if ((char *) adr == adr[i])
                        adr[i] = NULL;

            break;
            case 5:
                printf("--------------------------\n");
                printf("Введите арифметическое выражение:\n");
                while (getchar() != '\n');
                read = getline(&expression, &expression_len, stdin);
        
                if (read == -1)
                {   
                    err = ERR_IO;
                    free(expression);
                    break;
                }

                if (expression[read - 1] == '\n')
                    expression[read - 1] = '\0';
                
                err = check_expression(expression);
                
                if (err != ERR_OK)
                {   
                    printf("Ошибка: неверная арифметическая запись.\n");
                    break;
                }

                postfix = realloc(postfix, strlen(expression) + 2);

                if (!postfix)
                {
                    err = ERR_ALLOC;
                    break;
                }

                if (stack_store.massive)
                {
                    free(stack_store.massive);
                    stack_store.massive = NULL;
                    init_stack(&stack_store);
                }
                
                postfix[strlen(expression) + 1] = '\0';

                start = clock();
                err = convert_topostfix_stack(postfix, expression, &stack_store);
                end = clock();

                time_stack = (double) (end - start) / CLOCKS_PER_SEC * 1000;

                if (err == ERR_OK)
                    printf("Обратная запись: %s\n", postfix);

                free(expression);
                expression = NULL;
            break;
            case 6:
                printf("--------------------------\n");
                printf("Введите арифметическое выражение:\n");
                while (getchar() != '\n');
                read = getline(&expression, &expression_len, stdin);
        
                if (read == -1)
                {   
                    err = ERR_IO;
                    free(expression);
                    break;
                }

                if (expression[read - 1] == '\n')
                    expression[read - 1] = '\0';
                
                err = check_expression(expression);
                
                if (err != ERR_OK)
                {   
                    printf("Ошибка: неверная арифметическая запись.\n");
                    break;
                }
                postfix = realloc(postfix, strlen(expression) + 2);

                if (!postfix)
                {
                    err = ERR_ALLOC;
                    break;
                }

                postfix[strlen(expression) + 1] = '\0';

                if (list_store)
                {
                    free_list(list_store);
                    list_store = NULL;
                }

                init_list(&list_store);
                
                start = clock();
                err = convert_topostfix_list(postfix, expression, list_store);
                end = clock();
                
                time_list = (double) (end - start) / CLOCKS_PER_SEC * 1000;
                
                if (err == ERR_OK)
                    printf("Обратная запись: %s\n", postfix);

                free(expression);
                expression = NULL;
                break;
            case 7:
                printf("--------------------------\n");
                printf("История выполнения массива:\n");
                print_stack(&stack_store);
            break;void *pa;
            case 9:
                printf("--------------------------\n");
                printf("Удаление символа из массива: \n");

                rc = pop_frmstack(&stack);
                if (rc == ERR_EMPTY)
                    printf("Стек пуст.\n");
            break;
            case 10:
                printf("--------------------------\n");
                printf("Удаление символа из списка: \n");

                rc = pop_frmlist_adr(list, &pa);
                
                if (rc == ERR_EMPTY)
                    printf("Стек пуст.\n");
                
                adr[clc_p++] = pa;

            break;
            case 11:
                printf("--------------------------\n");


                printf("Введите n число замеров: \n");
                
                int n;
                
                err = scanf("%d", &n);

                while (getchar() != '\n');
                
                if (err != 1 || n <= 0)
                {
                    printf("Неверно введенное n.\n");
                    printf("%d", n);
                    break;
                }

                if (n > MAX_LEN)
                {
                    printf("Введено число, превышающее максимальный размер стека.\n");
                    break;
                }

                printf("Проведение замеров для массива: \n\n");

                double time_add, time_pop;
                start = clock();
                rc = add_n_chars_stack(&stack_time, n);
                end = clock();

                time_add = (double) (end - start) / CLOCKS_PER_SEC * 1000;

                start = clock();
                rc = pop_n_chars_stack(&stack, n);
                end = clock();

                time_pop = (double) (end - start) / CLOCKS_PER_SEC * 1000;

                printf("Время добаления %d элементов в массив: %lf\n", n, time_add);
                printf("Время удаления %d элементов из массива: %lf\n", n, time_pop);

                printf("Проведение замеров для списка: \n\n");
                
                start = clock();
                rc = add_n_chars_list(list_time, n);
                end = clock();
                
                time_add = (double) (end - start) / CLOCKS_PER_SEC * 1000;

                start = clock();
                rc = pop_n_chars_list(list_time, n);
                end = clock();

                time_pop = (double) (end - start) / CLOCKS_PER_SEC * 1000;

                printf("Время добаления %d элементов в список: %lf\n", n, time_add);
                printf("Время удаления %d элементов из списка: %lf\n\n", n, time_pop);
                printf("--------------------------\n");
            break;
            case 12:

                if (!time_list || !time_stack)
                {
                    printf("Недостаточно замеров. Проведите операции для постфиксной записи.\n");
                    break;
                }
                
                printf("--------------------------\n\n");
                printf("Время выполнения обратной записи для массива, мс: %lf\n\n", time_stack);

                printf("Время выполнения обратной записи для списка, мс: %lf\n\n", time_list);

                printf("--------------------------\n");
            break;
            case 13:
                print_adr(adr, clc_p);
                break;
            default:
            break;
        }
    } while (move != 0);
    
    if (list)
        free_list(list);
    
    if (list_store)
        free_list(list_store);

    if (list_time)
        free_list(list_time);

    if (stack_time.massive)
        free(stack_time.massive);
    
    if (stack.massive)
        free(stack.massive);

    if (stack_store.massive)
        free(stack_store.massive);
    
    if (postfix)
        free(postfix);

    return rc;
}