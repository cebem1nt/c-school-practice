//FLAGS: -lm
#include <math.h>
#include <stdio.h>

float per_circ(float radio) 
{
    return 2 * M_PI * radio;
}

int main()
{
    float p = per_circ(320);
    
    printf("El perimetro de circulo de radio de 320cm es %.2fcm\n", p);
    return 0;
}