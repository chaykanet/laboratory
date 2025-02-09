#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define SEC_IN_MIN 60
#define MIN_IN_HOUR 60


int main(void)
{
    int sec;
    int hours, minutes;

    printf("Enter your time in seconds:\n");
    scanf("%d", &sec);
    
    minutes = sec / SEC_IN_MIN;
    sec = sec - minutes * SEC_IN_MIN;

    hours = minutes / MIN_IN_HOUR;
    minutes = minutes - hours * MIN_IN_HOUR;
    
    printf("Your hours: %d\n", hours);
    printf("Your minutes: %d\n", minutes);
    printf("Your seconds: %d\n", sec);

    return ERR_OK;
}
