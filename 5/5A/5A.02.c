#include <stdio.h>
#include <stdlib.h>

const int total = 8;

void 
get_surname(char surnames[total][256], int index) 
{
    printf("Enter surname: ");
    if (scanf("%255s", surnames[index]) != 1) {
        exit(1);
    }
}

void 
get_age(float ages_arr[total], int index)
{
    printf("Enter age: ");
    if (scanf("%f", &ages_arr[index]) != 1) {
        exit(1);
    }
}

float 
get_adult_percent(float ages_arr[total]) {
    float adults = 0;

    for (int i = 0; i < total; i++) {
        if (ages_arr[i] < 18) {
            continue;
        }
        adults += 1;
    }

    return (adults / total) * 100;
}

int main() 
{
    char  surnames[total][256];
    float ages[total];

    for (int i = 0; i < total; i++) 
    {
        get_surname(surnames, i);
        get_age(ages, i);
    }

    float percent = get_adult_percent(ages);

    printf("\nPeople older than 18:\n");
    for (int i = 0; i < total; i++) 
    {
        if (ages[i] < 18) {
            continue;
        }

        printf("%s : %f\n", surnames[i], ages[i]);
    }

    printf("\nPercent of people older than 18 (or 18): %.03f%%\n", percent);
    return 0;
}