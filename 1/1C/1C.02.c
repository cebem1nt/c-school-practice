#include <stdio.h>

void calcMinutesAndHours(int hours)
{
    int minutes, seconds;
    
    minutes = hours * 60;
    seconds = minutes * 60;

    printf("%i hours is: %i minutes or %i seconds \n", hours, minutes, seconds);

}


void manualTest()
{
    int inputHours;

    printf("Enter hours (as single number): ");
    
    if (scanf("%d", &inputHours) != 1) {
        printf("Invalid input. \n");
        return ; 
    }
    calcMinutesAndHours(inputHours);
}


int main()
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");
    
    int cases[] = { 4, 8, 2, 10, 14, 1, 213, 14, 245, 10 };
    int i ;

    for (i = 0 ; i < 10 ; i++ ) {
        int hours = cases[i];
        calcMinutesAndHours(hours);
    }

    return 0; 
}