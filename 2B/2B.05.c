#include "../lib/et21conio.h"
#include <stdio.h>

int main() 
{
    for (int i = 0; i <= 15; i++) {
        textbackground(i);
        printf("Hola");
        textbackground(0);
        printf("\n");
    }
    
    return 0;
}