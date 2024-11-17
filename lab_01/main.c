#include "st_big_num.h"
#include "st_big_num_math.h"
#include "errcodes.h"

#define STR_LEN 50

int main(void)
{
    int rc = ERR_OK;
    char str_1[STR_LEN];
    char str_2[STR_LEN];

    struct big_num number_first, number_second, result;
    printf("Программа выполняет операцию деления больших действительных чисел.\n");
    printf("Ввведите делимое в формате [+-]m[.]n[e[+-]k], где (m + n) до 40 цифр, k до 5 цифр.\n");
    printf("+---------1---------2---------3---------4---------5\n");

    if (fgets(str_1, STR_LEN, stdin))
    {   
        char *p = strchr(str_1, '\n');
        *p = '\0';

        rc = take_num(str_1, &number_first);

        if (rc == ERR_OK)
        {   
            printf("Введите делитель в формате [+-]m[.]n[e[+-]k], где (m + n) до 40 цифр, k до 5 цифр.:\n");
            if (fgets(str_2, STR_LEN, stdin))
            {
                p = strchr(str_2, '\n');
                *p = '\0';

                if (rc == ERR_OK)
                    rc = take_num(str_2, &number_second);
            
                if (rc == ERR_OK)
                {    
                    printf("Промежуточные:\n");
                    print_num(number_first);
                    print_num(number_second);
                }

                if (rc == ERR_OK)
                    rc = complex_devide(&number_first, &number_second, &result);

                if (rc == ERR_OK)
                {
                    printf("Результат:\n");
                    printf("+---------1---------2---------3---------4---------5\n");
                    print_num(result);
                }
            }
            else 
                rc = ERR_IO;
        }
        else 
            rc = ERR_IO;
    }
    else
        rc = ERR_IO;

    print_err(rc);

    return rc;
}
