//FLAGS: -lm
#include <stdio.h>
#include <math.h> // Bueno

void rad_comp(float radio, float* perimetro, float* superficie, float* volumen) {
    *perimetro = 2 * M_PI * radio;
    *superficie = 4 * M_PI * pow(radio, 2);
    *volumen = (4.0 / 3.0) * M_PI * pow(radio, 3);
}

int main() {
    float radio = 5.0;
    float perimetro, superficie, volumen;

    rad_comp(radio, &perimetro, &superficie, &volumen);

    printf("Para un radio de %.2f:\n", radio);
    printf("Perímetro: %.2f\n", perimetro);
    printf("Superficie de la esfera: %.2f\n", superficie);
    printf("Volumen de la esfera: %.2f\n", volumen);

    return 0;
}
