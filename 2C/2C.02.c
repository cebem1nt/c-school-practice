#include <stdio.h>

int main() 
{
    int small = 0;
    float percent;

    for (int i = 0 ; i < 20 ; i++) {
        int num;

        printf("Enter number %i: ", i+1);

        if (!scanf("%i", &num)) {
            return 1;
        }

        if (num < 15) {
            small++;
        }
    }

    percent = (small / 20.0) * 100;
    printf("Percentage of numbers less than 15: %.2f%%", percent);

    return 0;
}