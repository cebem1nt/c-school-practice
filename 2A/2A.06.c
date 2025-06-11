#include <stdio.h>

int main() 
{
    int income;
    float taxes;

    printf("Enter income: ");
    if (!scanf("%i", &income)) {
        return 1;
    }

    taxes = (income / 100.0) * 3; 

    if (income > 200000) {
        taxes += ((income - 200000) / 100.0 ) * 0.2;
    }

    printf("Taxes: $%.02f \n", taxes);

    return 0;
}