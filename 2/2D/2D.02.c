#include <stdio.h>

int main() 
{
    int age_sum = 0;
    int age = 0;

    float age_average;

    for (int i = 0; i < 40; i++) {
        printf("Enter age (%i/40): ", i+1);

        if (!scanf("%i", &age)) {
            return 1;
        }

        age_sum += age;
    }

    age_average = age_sum / 40.0;

    printf("Average age: %.2f \n", age_average);
    return 0;
}