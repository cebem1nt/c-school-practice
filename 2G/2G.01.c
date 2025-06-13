#include <limits.h>
#include <stdio.h>

int main() 
{
    int num;
    int big = INT_MIN; 

    for (int i = 0; i < 20; i++) {
        printf("Enter number (%i/20): ", i+1);
        
        if (!scanf("%i", &num)) {
            return 1;
        }

        if (!big || num > big) {
            big = num;
        }
    }

    printf("Biggest: %i", big);
    return 0;
}