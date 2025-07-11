#include <stdint.h>
#include <stdio.h>

int main() 
{
    unsigned short int a;
    unsigned long int b;
    
    long int c;
    short int d;

    a = INT16_MAX * 2.5;
    d = INT16_MAX;

    b = INT64_MAX * 1.5;
    c = INT64_MAX;

    printf("b's maximum is: %lu\n", b);
    printf("c's maximum is: %li\n", c);
    printf("a's maximum is: %i\n", a);
    printf("d's maximum is: %i\n", d);

    return 0;
}