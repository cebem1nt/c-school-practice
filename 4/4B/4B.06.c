//FLAGS: -lm
#include <math.h>
#include <stdio.h>

float vol_esfera(float radio) 
{
    return (4.0 / 3.0) * M_PI * radio * radio * radio;
}

int main() 
{
    float v = vol_esfera(24);

    printf("El volume de esfera de radio de 24cm es %.2fcm3\n", v);

    return 0;
}
