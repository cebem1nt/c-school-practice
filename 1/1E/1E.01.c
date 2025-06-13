#include "../lib/et21conio.h"
#include <stdio.h>
//
void calcTaxes(float income)
{
    float percentage = income / 100.0;

    float natTaxes = percentage * 5;
    float colTaxes = percentage * 2;
    float munTaxes = percentage * 0.3;

    textcolor(YELLOW);
    printf("National taxes: %.2f \n", natTaxes);
    textcolor(GREEN);
    printf("College taxes: %.2f \n", colTaxes);
    textcolor(CYAN);
    printf("Municipal taxes: %.2f \n", munTaxes);
}

void manualTest()
{
    int income ;

    printf("Enter income: ");
    if (scanf("%d", &income) != 1) {
        textcolor(RED);
        printf("Invalid input. \n");
        return ;
    }

    calcTaxes(income);
}


int main()
{
    manualTest();
    textbackground(GREEN);
    printf("\nAUTOMATED TESTS\n\n");

    int cases[] = { 4, 8, 2, 10, 14, 1, 213, 14, 69, 10 };
    int i ;

    for (i = 0 ; i < 10 ; i++ ) {
        int income = cases[i];

        printf("Test case: %i \n", income);
        calcTaxes(income);
        printf("\n");
    }

    return 0;
}
