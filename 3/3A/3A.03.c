#include <stdint.h>
#include <stdio.h>
int main()
{
    short int c;
    int e;

    c = INT16_MAX;
    e = INT32_MAX;

    e = c;

    // E es igual a INT16_MAX (valor maximo (aproximadamente) de short int)
    printf("e: %i", e);

    return 0;
}