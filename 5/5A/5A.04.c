#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int name_len = 256;

void 
get_name(char names[][name_len], int index)
{
    printf("Enter country name (or 'f' to finish): ");
    if (scanf("%255s", names[index]) != 1) {
        exit(1);
    }
}

void 
get_surface(float surfaces[], int index)
{
    printf("Enter surface (km2) for country %d: ", index + 1);
    if (scanf("%f", &surfaces[index]) != 1) {
        exit(1);
    }
}

void 
get_inhabitants(long inhabitants[], int index)
{
    printf("Enter inhabitants for country %d: ", index + 1);
    if (scanf("%ld", &inhabitants[index]) != 1) {
        exit(1);
    }
}

int 
main(void)
{
    char names[1000][name_len];
    float surfaces[1000];
    long inhabitants[1000];
    int count = 0;

    while (1) {
        get_name(names, count);

        if (strcmp(names[count], "f") == 0) {
            break;
        }

        get_surface(surfaces, count);
        get_inhabitants(inhabitants, count);

        count++;

        if (count >= 1000) {
            printf("Maximum number of entries reached.\n");
            break;
        }
    }

    if (count == 0) {
        printf("No countries entered.\n");
        return 0;
    }

    long sum_inhabitants = 0;
    int count_surface_condition = 0;
    int min_surface_index = 0;
    int min_inhabitants_index = 0;

    for (int i = 0; i < count; i++) {
        sum_inhabitants += inhabitants[i];
        if (surfaces[i] < surfaces[min_surface_index]) {
            min_surface_index = i;
        }
        if (inhabitants[i] < inhabitants[min_inhabitants_index]) {
            min_inhabitants_index = i;
        }
        if (surfaces[i] < 10000.0f || inhabitants[i] > 200000L) {
            count_surface_condition++;
        }
    }

    double avg_inhabitants = (double)sum_inhabitants / count;
    double percent_condition = ((double)count_surface_condition / count) * 100.0;

    printf("a) Average inhabitants: %.2f\n", avg_inhabitants);
    printf("b) Percentage of countries with surface < 10000 or inhabitants > 200000: %.2f%%\n", percent_condition);
    printf("c) Smallest surface (unique): %.2f km2\n", surfaces[min_surface_index]);
    printf("d) Name of country with smallest inhabitants (unique): %s\n", names[min_inhabitants_index]);

    printf("\n e) Countries with surface between 10000 and 50000 (inclusive):\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (surfaces[i] >= 10000.0f && surfaces[i] <= 50000.0f) {
            printf("   Name: %s ; Surface: %.2f ; Inhabitants: %ld\n", names[i], surfaces[i], inhabitants[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("   (none)\n");
    }

    printf("\nFull list of countries:\n");
    for (int i = 0; i < count; i++) {
        printf(" Country %d -> Name: %s ; Surface: %.2f ; Inhabitants: %ld\n", i + 1, names[i], surfaces[i], inhabitants[i]);
    }

    return 0;
}