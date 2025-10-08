#include <stdio.h>
#include <string.h>

#define PERSONS 8
#define MAX_NAME 256

typedef char str_t[MAX_NAME];

void 
swap_int(int* a, int* b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void 
swap_s(str_t a, str_t b) 
{
    char tmp[MAX_NAME];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

// Compare by last name first, then by first name
int 
compare_names(
    char* first1, char* first2, char* last1, char* last2) 
{
    int cmp = strcmp(last1, last2);
    if (cmp != 0) return cmp;
    return strcmp(first1, first2);
}

void 
sort_abc(
    str_t last_names[PERSONS], str_t first_names[PERSONS], int ages[PERSONS]) 
{
    for (int i = 0; i < PERSONS - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < PERSONS - 1 - i; j++) {
            if (compare_names(first_names[j], first_names[j+1],
                              last_names[j],  last_names[j+1]) > 0) {
                // Swap names
                swap_s(last_names[j], last_names[j+1]);
                swap_s(first_names[j], first_names[j+1]);
                // Swap ages
                swap_int(&ages[j], &ages[j+1]);
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        };
    }
}

int main(void) {
    str_t last_names[PERSONS] = {0};
    str_t first_names[PERSONS] = {0};
    int   ages[PERSONS] = {0};

    int i = 0;
    while (i < PERSONS) {
        printf("Enter last name: ");
        if (scanf("%255s", last_names[i]) != 1) {
            printf("\nInvalid last name, try again\n");
            continue;
        }

        printf("Enter first name: ");
        if (scanf("%255s", first_names[i]) != 1) {
            printf("\nInvalid first name, try again\n");
            continue;
        }

        printf("Enter age: ");
        if (scanf("%d", &ages[i]) != 1) {
            printf("\nInvalid age, try again\n");
            continue;
        }

        putchar('\n');
        i++;
    }

    sort_abc(last_names, first_names, ages);

    printf("Sorted list (Last, First : Age):\n");
    for (int k = 0; k < PERSONS; k++) {
        printf("%s, %s : %d\n", last_names[k], first_names[k], ages[k]);
    }

    return 0;
}