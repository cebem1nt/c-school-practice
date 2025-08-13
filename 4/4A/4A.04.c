#include <stdio.h>

void linea_largo_de(unsigned int length) 
{
    for (int i = 0; i < length; i++) 
    {
        printf("-");
    }

    printf("\n");
}

int main() 
{
    linea_largo_de(2);
    linea_largo_de(14);
}