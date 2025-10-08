#include <stdio.h>
#include <string.h>

#define PERSONS 6
#define MAX_PERSON_NAME 256

void 
sort_max(
    char names[PERSONS][MAX_PERSON_NAME], float* salaries) 
{
    for (int i = 0; i < PERSONS; i++) {
        for (int j = i+1; j < PERSONS; j++) {
            if (salaries[i] < salaries[j]) 
            {
                float tmp_sal = salaries[i];
                salaries[i] = salaries[j];
                salaries[j] = tmp_sal;

                char tmp_name[MAX_PERSON_NAME];
                strcpy(tmp_name, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], tmp_name);
            }
        }
    }
}

int 
main() 
{
    char  names[PERSONS][MAX_PERSON_NAME] = {0};
    float salaries[PERSONS] = {0};
  
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
