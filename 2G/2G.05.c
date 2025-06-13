#include <limits.h>
#include <stdio.h>

int main() 
{
    int salary, id;

    int big = INT_MIN; 
    int big_id;

    for (int i = 0; i < 60; i++) {
        printf("Enter id (%i/60): ", i+1);
        
        if (!scanf("%i", &id)) {
            return 1;
        }

        printf("Enter salary (%i/60): ", i+1);
        
        if (!scanf("%i", &salary)) {
            return 1;
        }

        if (!big || salary > big) {
            big = salary;
            big_id = id;
        }
    }

    printf("Id with the biggest salary: %i", big_id);
    return 0;
}