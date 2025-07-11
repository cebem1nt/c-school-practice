#include <stdint.h>
#include <stdio.h>
int main()
{
    short int c;
    int e;

    c = INT16_MAX;
    e = INT32_MAX;

    c = e;

    // Overflow - c no se convierte en un int, sino en -1
    printf("c: %i\n", c);

    return 0;
}