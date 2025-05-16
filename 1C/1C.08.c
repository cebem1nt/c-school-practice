#include <stdio.h>

void calcSale(float saleVal, float formsVal) 
{
    float saleTaxes = (saleVal / 100) * 21;
    float realTaxes = (saleVal / 100) * 5 ;

    float taxes = saleTaxes + realTaxes + formsVal;
    float divTaxes = taxes / 2;

    printf("House sale taxes: %f \n", saleTaxes);
    printf("Real estate taxes: %f \n", realTaxes);

    printf("Taxes: %f \n", taxes);
    printf("Taxes seller and buyer pay: %f \n", divTaxes);
}

void manualTest() 
{
    int saleVal ;
    int formsVal ;

    printf("Enter sale value: ");
    if (scanf("%d", &saleVal) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    printf("Enter forms stampings' value: ");
    if (scanf("%d", &formsVal) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    calcSale(saleVal, formsVal);
}

int main () 
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");

    int cases[][2] = {
        {43, 2}, {8, 15}, 
        {22, 0}, {1, 10}, 
        {14, 2}, {1, 12}, 
        {21, 1}, {0, 32}, 
        {69, 3}, {3, 13} 
    } ;

    int i;

    for (i = 0; i < 10 ; i++) {
        int saleVal = cases[i][0];
        int formsVal = cases[i][1];

        printf("Test case: %i %i", saleVal, formsVal);
        calcSale(saleVal, formsVal);
        printf("\n");
    }

    return 0;
}