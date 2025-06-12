#include <stdio.h>

int main() 
{
    int bigger = 0;
    
    int ltfive, between, more;
    
    for (int i = 0 ; i < 100 ; i++) {
        int salary;

        printf("Enter salary (%i/100): ", i+1);

        if (!scanf("%i", &salary)) {
            return 1;
        }

        if (salary < 500) {
            ltfive++;
        } else if (salary < 1000) {
            between++;
        } else {
            more++;
        }
    }

    printf("Less than $500: %i \n", ltfive);
    printf("Between $500 and $1000: %i \n", between);
    printf("More than $1000: %i \n", more);

    return 0;
}