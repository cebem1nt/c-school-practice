#include <stdio.h>
#include <string.h>

#define PERSONS 6
#define MAX_PERSON_NAME 256
#define LESS_THAN(a, b) (strcmp(a, b) < 0)  

typedef char name_t[MAX_PERSON_NAME];

void
swap_f(float* p1, float* p2)
{
    float tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void
swap_s(char* p1, char* p2) 
{
    char tmp[MAX_PERSON_NAME];
    strcpy(tmp, p1);
    strcpy(p1,  p2);
    strcpy(p2, tmp);
}

void 
sort_max(
    name_t names[PERSONS], float* salaries) 
{
    for (int i = 0; i < PERSONS - 1; i++) {
        int is_swapped = 0;

        for (int j = 0; j < PERSONS - 1 - i; j++) {
            if (LESS_THAN(names[j], names[j+1])) 
            {
                swap_f(&salaries[j], &salaries[j+1]);
                swap_s(names[j], names[j+1]);

                is_swapped = 1;
            }
        }

        if (is_swapped == 0) {
            break;
        }
    }
}

int 
main() 
{
    name_t names[PERSONS] = {0};
    float  salaries[PERSONS] = {0};
  
    int i = 0;

    while (i < PERSONS) {
        printf("Enter name: ");
        if ( scanf("%s", names[i]) != 1 ) {
            printf("\nInvalid name, try again\n");
            continue;
        }
        
        printf("Enter salary: ");
        if ( scanf("%f", &salaries[i]) != 1 ) {
            printf("\nInvalid salary, try again\n");
            continue;
        }

        putchar('\n');
        i++;
    }

    sort_max(names, salaries);

    printf("Sorted salaries & names: \n");
    for (int i = 0; i < PERSONS; i++) {
        printf("%s : %.2f \n", names[i], salaries[i]);
    }

    return 0;
}
