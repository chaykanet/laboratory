#include <stdio.h>
#include "string_func.h"

#define NUM_TESTS 17

int main(void)
{
    int count_failed = NUM_TESTS;
    
    if (my_strpbrk("Hello, world!", "Say Hello") == strpbrk("Hello, world!", "Say Hello"))
        count_failed--;
    if (my_strpbrk("Hello, world!", "Say world") == strpbrk("Hello, world!", "Say world"))
        count_failed--;
    if (my_strpbrk("Hello, world!", "A") == strpbrk("Hello, world!", "A"))
        count_failed--;
    if (my_strpbrk("Hello, world!", "\0") == strpbrk("Hello, world!", "\0"))
        count_failed--;

    if (my_strspn("abcdef", "abcdef") == strspn("abcdef", "abcdef"))
        count_failed--;
    if (my_strspn("abcdef", "def") == strspn("abcdef", "def"))
        count_failed--;
    if (my_strspn("abcdef", "g") == strspn("abcdef", "g"))
        count_failed--;
    if (my_strspn("abcdef", "\0") == strspn("abcdef", "\0"))
        count_failed--;

    if (my_strcspn("Hello, world!", "A") == strcspn("Hello, world!", "A"))
        count_failed--;
    if (my_strcspn("Hello, world!", "ol") == strcspn("Hello, world!", "ol"))
        count_failed--;
    if (my_strcspn("Hello, world!", "\0") == strcspn("Hello, world!", "\0"))
        count_failed--;
    
    if (my_strchr("Hello, world!", 'o') == strchr("Hello, world!", 'o'))
        count_failed--;
    if (my_strchr("Hello, world!", 'A') == strchr("Hello, world!", 'A'))
        count_failed--;
    if (my_strchr("Hello, world!", '\0') == strchr("Hello, world!", '\0'))
        count_failed--;
    
    if (my_strrchr("Hello, world!", 'o') == strrchr("Hello, world!", 'o'))
        count_failed--;
    if (my_strrchr("Hello, world!", 'A') == strrchr("Hello, world!", 'A'))
        count_failed--;
    if (my_strrchr("Hello, world!", '\0') == strrchr("Hello, world!", '\0'))
        count_failed--;
    
    printf("count_failed_tests: %d\n", count_failed);
    
    return 0;
}
