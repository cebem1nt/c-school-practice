#include <stdio.h>

void calcAbsPercent(int absentee)
{
    float percent = (absentee / 70.0) * 100;

    printf("Percent of %i absent is %.2f%% \n", absentee, percent);
}

void manualTest()
{
    int absentee;

    printf("Enter amount of absentee person: ");

    if (scanf("%d", &absentee) != 1) {
        printf("Invalid input. \n");
        return ; 
    }

    calcAbsPercent(absentee);
}

int main()
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");

    int cases[] = { 4, 8, 2, 10, 14, 1, 213, 14, 69, 10 };
    int i ;

    for (i = 0 ; i < 10 ; i++ ) {
        int absentee = cases[i];
        calcAbsPercent(absentee);
    }

    return 0; 
}
