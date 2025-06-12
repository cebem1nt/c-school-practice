#include <stdio.h>

int main() 
{
    int bigger = 0;
    
    for (int i = 0 ; i < 10 ; i++) {
        int num;

        printf("Enter number %i: ", i+1);

        if (!scanf("%i", &num)) {
            return 1;
        }

        if (num > 4) {
            bigger++;
        }
    }

    printf("\n%d of inserted numbers are bigger than 4", bigger);

    return 0;
}