#include <stdio.h>
#include <string.h>

#define PERSONS 6
#define MAX_PERSON_NAME 256

typedef char name_t[MAX_PERSON_NAME];

void
swap2(float* f_p1, float* f_p2, char* s_p1, char* s_p2)
{
    float f_tmp = *f_p1;
    *f_p1 = *f_p2;
    *f_p2 = f_tmp;

    char s_tmp[MAX_PERSON_NAME];
    strcpy(s_tmp, s_p1);
    strcpy(s_p1,  s_p2);
    strcpy(s_p2, s_tmp);
}

void 
sort_max(
    name_t names[PERSONS], float* salaries) 
{
    for (int i = 0; i < PERSONS - 1; i++) {
        int is_swapped = 0;

        for (int j = 0; j < PERSONS - 1 - i; j++) {
            if (salaries[j] < salaries[j+1]) 
            {
                swap2(&salaries[j], &salaries[j+1], 
                      names[j], names[j+1]);

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
