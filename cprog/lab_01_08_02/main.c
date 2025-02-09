#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#define ERR_OK 0
#define ERR_IO 1
#define CORRECT_IN 1

// void print_bin_num(uint32_t dec_number, size_t size_bit)
// {
//     printf("Result: ");
//     for (int i = size_bit - 1; i >= 0; i--)
//         printf("%d", (dec_number >> i) & 1);
// }

// void shift(uint32_t dec_number, int n, size_t size_bit)
// {
//     if (n > size_bit)
//         n %= size_bit;
  
//     dec_number = (dec_number << n) | (dec_number >> (size_bit - n)); 
//     print_bin_num(dec_number, size_bit);
// }


/*
    Функция принимает целочисленное безнаковое число dec_number, кол-во сдвигов, размер числа в битах.
    Циклично сдвигает число в n раз влево и возвращает его.
*/
void shift_num(uint32_t *dec_num, size_t num, size_t size_bit)
{
    if (num >= size_bit)
        num %= size_bit;

    for (size_t i = 0; i < num; i++)
        *dec_num = (*dec_num << 1) | (*dec_num >> (size_bit - 1));
}

/* Функция принимает целое безнаковое число, маску единицы, размер числа в битах
   Функция выводит это число в 2сс.*/
void print_bin_num(uint32_t dec_number, uint32_t *mask, size_t size_bit)
{
    for (size_t i = size_bit; i != 0; i--)
    {    
        if ((dec_number & *mask) != 0)
        {
            *mask >>= 1;
            printf("1");
        }
        else
        {
            *mask >>= 1;
            printf("0");
        }
    }
}

int main(void)
{
    uint32_t a;
    int rc, n;

    
    printf("Enter your number: ");
    rc = scanf("%" SCNu32, &a);

    if (rc != CORRECT_IN)
    {
        printf("Error: Incorrect input");
        return ERR_IO;
    }
    
    size_t size_bit = CHAR_BIT * sizeof(a);

    printf("Enter your n: ");
    rc = scanf("%d", &n);
    
    if (rc != CORRECT_IN || n < 0)
    {
        printf("Error: Incorrect input");
        return ERR_IO;
    }

    size_t num = (size_t) n;
    
    uint32_t dec_number = a;
    shift_num(&dec_number, num, size_bit);

    // uint32_t dec_number = (a << num) | (a >> (size_bit - num));
    uint32_t mask = 1u << (size_bit - 1);

    printf("Result: ");
    print_bin_num(dec_number, &mask, size_bit);
    
    printf("\n");
    
    return ERR_OK;
}
