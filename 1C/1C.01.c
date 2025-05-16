#include <stdio.h>

void calcFourth(int num)
{
    float fourthPart = num / 4.0; 
    
    printf("Fourth part of %i is %f \n", num, fourthPart);
}

void manualTest()
{
    int inputNumber;

    printf("Enter number: ");
    
    if (scanf("%d", &inputNumber) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    calcFourth(inputNumber);
}

int main()
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");

    int cases[] = { 4, 8, 2, 10, 14, 1, 213, 14, 245, 10 };
    int i ;

    for (i = 0 ; i < 10 ; i++ ) {
        int num = cases[i];
        
        calcFourth(num);
    }

    return 0; 
}
