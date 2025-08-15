#include <stdio.h>

void porciento(float cantidad, float total, float* porcentaje) 
{
    if (total == 0) {
        return;
    }

    *porcentaje = (cantidad / total) * 100;
}

int main() {
    float porcentaje = 0; 

    porciento(25, 200, &porcentaje);

    printf("El porcentaje es: %.2f%%\n", porcentaje);
    return 0;
}
