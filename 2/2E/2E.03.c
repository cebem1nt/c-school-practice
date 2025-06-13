#include <stdio.h>

int main() 
{
    int num;

    while (1) {
        printf("Enter number: ");
        
        if (!scanf("%i", &num)) {
            return 1;
        } 

        if (num > 0) {
            printf("Number is positive \n");
        } 
        else if (num < 0) {
            printf("Number is negative \n");
        } 
        else {
            break;
        }

    }
}