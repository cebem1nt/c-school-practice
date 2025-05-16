#include <stdio.h>

void calcTaxes(float income)
{
    float percentage = income / 100.0;

    // Calculating taxes
    float natTaxes = percentage * 5;
    float colTaxes = percentage * 2;
    float munTaxes = percentage * 0.3;
    
    printf("National taxes: %.2f \n", natTaxes);
    printf("College taxes: %.2f \n", colTaxes);
    printf("Municipal taxes: %.2f \n", munTaxes);
}

void manualTest() 
{
    int income ;

    // Getting income
    printf("Enter income: ");
    if (scanf("%d", &income) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    calcTaxes(income);
}


int main()
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");

    // Test cases
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