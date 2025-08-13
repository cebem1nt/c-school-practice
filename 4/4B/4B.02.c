#include <stdio.h>

float porciento(float cantidad, float total) {
    if (total == 0) return 0;

    return (cantidad / total) * 100;
}

int main() 
{
    float p = porciento(100, 1000);

    printf("porciento de %i de total de %i es %.0f%%\n", 100, 1000, p);
}