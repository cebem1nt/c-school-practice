#include <stdio.h>

int main ()
{
    int num;
    printf("Enter number: ");
    
    if (!scanf("%i", &num)) {
        return 1;
    } 

    if (num > 5) {
        printf("%i\n", num*2);
    }

    else if (num < 5) {
        printf("%i\n", num*3);
    } 
    
    else {
        printf("Number is 5\n");
    }

    return 0;
}