//FLAGS: -lm
#include <math.h>
#include <stdio.h>


float sup_circulo(float radio) 
{
    return M_PI * radio * radio;
}

int main() 
{
    float s = sup_circulo(24);

    printf("La superficie de circulo de radio de 24cm es %.2fcm2\n", s);

    return 0;
}