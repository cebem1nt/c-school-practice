#include <stdio.h>

int main() 
{
    int sum = 0;
    int num = 0;

    for (int i = 0; i < 100; i++) {
        printf("Enter salary (%i/100): ", i+1);

        if (!scanf("%i", &num)) {
            return 1;
        }

        sum += num;
    }

    printf("Totaly to pay: $%i \n", sum);
    return 0;
}