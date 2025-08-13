#include <stdio.h>

void linea_fila_desde_hasta(
    unsigned int fila, unsigned int col_inicio, unsigned int col_fin) 
{
    for (int i = 0; i < fila; i++) 
    {
        printf("\n");
    }

    // Printing spaces until the starting column
    for (int j = 0; j < col_inicio; j++) {
        printf(" ");
    }

    for (int k = col_inicio; k <= col_fin; k++) {
        printf("*");
    }

    printf("\n");
}

int main() {
    linea_fila_desde_hasta(3, 5, 10);
    linea_fila_desde_hasta(12, 51, 60);
    
    // WARNING! Will cause something like a kaboom
    // unsigned int will be converted to UINT32_MAX - 1 :)
    // linea_fila_desde_hasta(-1, -1, -1); 

    return 0;
}
