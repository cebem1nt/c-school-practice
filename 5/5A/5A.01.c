#include <stdio.h>
#include <stdlib.h>

const int persons = 5;

void 
get_surname(char surnames[persons][256], int index) 
{
    printf("Enter surname: ");
    if (scanf("%255s", surnames[index]) != 1) {
        exit(1);
    }
}

void 
get_salary(float salaries_arr[persons], int index)
{
    printf("Enter salary: ");
    if (scanf("%f", &salaries_arr[index]) != 1) {
        exit(1);
    }
}

float 
get_average_salary(float salaries_arr[persons]) {
    float sum = 0;

    for (int i = 0; i < persons; i++) {
        sum += salaries_arr[i];
    }

    return sum / persons;
}

int main() 
{
    char  surnames[persons][256];
    float salaries[persons];

    for (int i = 0; i < persons; i++) 
    {
        get_surname(surnames, i);
        get_salary(salaries, i);
    }

    float avg = get_average_salary(salaries);

    printf("\n");
    for (int i = 0; i < persons; i++) 
    {
        printf("%s : %f\n", surnames[i], salaries[i]);
    }

    printf("\nAverage salary: %f\n", avg);
    return 0;
}