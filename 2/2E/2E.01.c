#include <stdio.h>

int main() 
{
    int num = 0;

    while (num < 10) {
        printf("Enter number bigger than 10: ");
        
        if (!scanf("%i", &num)) {
            return 1;
        } 

        if (num < 10) {
            printf("Entered number is less than 10 \n");
        } else {
            printf("%i \n", num*2);
        }
    }
}