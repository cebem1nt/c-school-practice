//FLAGS: -lm
#include <math.h>
#include <stdio.h>

float calc_area(float r) 
{
    return M_PI * pow(r, 2);
}

float calc_sphere_volume(float r) 
{
    return (4.0/3.0) * M_PI * pow(r, 3);
}

float calc_perimeter(float r) 
{
    return 2 * M_PI * r;
}

int main()
{
    float radius,
          perimeter,
          area,
          volume;

    printf("Enter radius of a circle: ");

    if (!scanf("%f", &radius)) {
        printf("\nIncorrect value");
        return 1;
    }

    printf("\n");

    perimeter = calc_perimeter(radius);
    area = calc_area(radius);
    volume = calc_sphere_volume(radius);

    printf("Perimeter is equal to: %.10f\n", perimeter);
    printf("Area is equal to: %.10f\n", area);
    printf("Volume of a sphere is equal to: %.10f\n", volume);

    return 0;
}