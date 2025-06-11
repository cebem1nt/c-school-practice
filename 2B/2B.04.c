#include <stdio.h>

int main () 
{
    int num;
    printf("Enter number: ");

    if (!scanf("%i", &num)) {
        return 1;
    }

    for (int i = 1; i <= 9; i++) {
        printf("%i * %i = %i \n", num, i, num*i);
    }

    return 0;
}