#include <stdio.h>

void calcTaxes(float income, float fixedBills)
{
    float percentage = income / 100.0;

    float natTaxes = percentage * 5;
    float colTaxes = percentage * 2;
    float munTaxes = percentage * 0.3;

    float expencese = natTaxes + colTaxes + munTaxes + fixedBills;
    float profit = income - expencese;

    printf("National taxes: %.2f \n", natTaxes);
    printf("College taxes: %.2f \n", colTaxes);
    printf("Municipal taxes: %.2f \n", munTaxes);
    printf("Profit: %f \n", profit );
}

void manualTest() 
{
    int income ;
    int fixedBills ;

    printf("Enter income: ");
    if (scanf("%d", &income) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    printf("Enter fixed bills: ");
    if (scanf("%d", &fixedBills) != 1) {
        fixedBills = 0;
    }

    calcTaxes(income, fixedBills);
}


int main()
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");

    int cases[][2] = { 
        {43, 2}, {8, 15}, 
        {22, 0}, {1, 10}, 
        {14, 2}, {1, 12}, 
        {21, 1}, {0, 32}, 
        {69, 3}, {3, 13} 
    };
    
    int i ;

    for (i = 0 ; i < 10 ; i++ ) {
        int income = cases[i][0];
        int fixedBills = cases[i][1];

        printf("Test case: %i %i \n", income, fixedBills);
        calcTaxes(income, fixedBills);
        printf("\n");
    }

    return 0; 
}
