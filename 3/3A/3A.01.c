#include <stdint.h>
#include <stdio.h>

int main() 
{
    short int a;
    short int b;

    a = INT16_MAX;
    b = INT32_MAX;

    // El gcc no lo va a dejar compilar, porque 
    // Va a ocurrir un overflow.   

    // 3A/3A.01.c: In function ‘main’:
    // 3A/3A.01.c:10:9: warning: overflow in conversion from ‘int’ to ‘short int’ changes value from ‘2147483647’ to ‘-1’ [-Woverflow]
    //    10 |     b = INT32_MAX;
    //       |         ^~~~~~~~~
    // Compilation failed.

    
    printf("a is equal to its max: %i\n", a);
    printf("b is equal to its max: %i\n", b);

    return 0;
}