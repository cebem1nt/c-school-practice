#include <stdio.h>

void calcSalary(float workedHours, float hourlyPay) 
{
    float pay = workedHours * hourlyPay;
    float percentage = pay / 100;

    float retPercent = percentage * 11; 
    float socPercent = percentage * 3 ;
    float uniPercent = percentage * 2;

    float salary = pay - retPercent - socPercent - uniPercent ;

    printf("Retirenment dues: %f \n", retPercent);
    printf("Social dues: %f \n", socPercent);
    printf("Union dues: %f \n", uniPercent);

    printf("Final salary: %f \n", salary);
}

void manualTest() 
{
    int workedHours ;
    int hourlyPay ;

    printf("Enter worked hours: ");
    if (scanf("%d", &workedHours) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    printf("Enter hourly pay: ");
    if (scanf("%d", &hourlyPay) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    calcSalary(workedHours, hourlyPay);
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
        int workedHours = cases[i][0];
        int hourlyPay = cases[i][1];

        printf("Test case: %i %i", workedHours, hourlyPay);
        calcSalary(workedHours, hourlyPay);
        printf("\n");
    }

    return 0;
}