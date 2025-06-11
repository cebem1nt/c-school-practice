#include <stdio.h>
#include "../lib/et21conio.h"

int main ()
{
    int num;
    printf("Enter number: ");
    
    if (!scanf("%i", &num)) {
        return 1;
    } 

    if (num < 0) {
        textcolor(GREEN);
        printf("%i", num*2);
    }

    else {
        textcolor(RED);
        printf("%i", num*2);
    }   

    return 0;
}