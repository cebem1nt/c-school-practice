#include <stdio.h>

int main() 
{
    int num1 = 123;
    int num2 = 200;

    printf("Binary representation of %i: ", num1);
    for (int i = 7; i >= 0; i--) {
        (num1 & (1 << i)) ? printf("1") : printf("0");
    }
    printf("\n");

    printf("Binary representation of %i: ", num2);
    for (int i = 7; i >= 0; i--) {
        (num2 & (1 << i)) ? printf("1") : printf("0");
    }
    printf("\n");
 
    printf("Bitwise AND:                  ");
    for (int i = 7; i >= 0; i--) {
        ((num1 & (1 << i)) && (num2 & (1 << i))) ? printf("1") : printf("0");
    }
    printf("\n");

    printf("Result: %i\n", num1 & num2);

    return 0;
}