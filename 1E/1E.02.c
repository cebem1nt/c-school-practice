#include <stdio.h>
#include "../lib/et21conio.h"


int main()
{
    float val, percentage, sum;

    printf("Enter value: ");
    
    if (!scanf("%f", &val)) {
        printf("Incorrect value! \n");
        return 1;
    }

    percentage = (val / 100) * 13.2;
    sum = val + percentage;

    textbackground(LIGHTGRAY);
    printf("%.2f + %.2f = %.2f \n", val, percentage, sum);

    return 0;
}
