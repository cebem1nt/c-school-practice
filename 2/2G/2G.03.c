#include <limits.h>
#include <stdio.h>

int main() 
{
    int num;
    int small = INT_MAX; 

    for (int i = 0; i < 25; i++) {
        printf("Enter number (%i/25): ", i+1);
        
        if (!scanf("%i", &num)) {
            return 1;
        }

        if (!small || num < small) {
            small = num;
        }
    }

    printf("Smallest: %i", small);
    return 0;
}