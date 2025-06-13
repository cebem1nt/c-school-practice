#include <stdio.h>

int main() 
{
    int count = 0;
    int salary = 0;
    int salaries_sum = 0;

    float average;

    while (1) {
        printf("Enter salary: ");
        
        if (!scanf("%i", &salary)) {
            return 1;
        } 

        if (salary == 0) {
            break;
        }

        salaries_sum += salary;
        count++;
    }

    average = (salaries_sum * 1.0) / count;

    printf("Average: %.2f \n", average);
}