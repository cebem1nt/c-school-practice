#include <stdio.h>
int main() 
{
    double d;
    float f;
    int i;

    d = 2.000000001;
    f = 2.0001;
    i = 2;

    d = d + f + i;
    f = f + d + i;
    i = i + d + f;

    printf("d: %f \n", d);
    printf("f: %f \n", f);
    printf("i: %i \n", i);

    return 0;
}