#include <stdio.h>

int main() {
    int ages[80];
    float salaries[80];

    int count_under_20 = 0, 
        count_over_50 = 0, 
        count_between_500_and_1000 = 0, 
        count_over_40_under_600 = 0;

    for (int i = 0; i < 80; i++) {
        printf("Enter age of person %d: ", i + 1);
        scanf("%d", &ages[i]);
        
        printf("Enter salary of person %d: ", i + 1);
        scanf("%f", &salaries[i]);

        if (ages[i] < 20) {
            count_under_20++;
        }

        if (ages[i] > 50) {
            count_over_50++;
        }

        if (salaries[i] >= 500 && salaries[i] <= 1000) {
            count_between_500_and_1000++;
        }

        if (ages[i] > 40 && salaries[i] < 600) {
            count_over_40_under_600++;
        }
    }

    float percentage_over_50 = ((float) count_over_50 / 80) * 100;

    printf("\nResults:\n");
    printf("Number of people under 20 years: %d\n", count_under_20);
    printf("Percentage of people over 50 years: %.2f%%\n", percentage_over_50);
    printf("Number of people earning between $500 and $1000: %d\n", count_between_500_and_1000);
    printf("Number of people over 40 years earning less than $600: %d\n", count_over_40_under_600);

    return 0;
}
