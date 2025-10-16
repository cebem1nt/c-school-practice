#include <stdio.h>
#include <string.h>

#define PEOPLE_SIZE 5
#define MAX_NAME_SIZE 50
#define BIGGER_THAN(s1, s2) (strcmp(s1, s2) > 0)

struct person {
    char surname[MAX_NAME_SIZE];
    char name[MAX_NAME_SIZE];
    short age;
};

typedef struct person person_t;

int
input(char* prompt, char* type, void* dest) 
{
    printf("%s ", prompt);
    if (scanf(type, dest) != 1) {
        fprintf(stderr, "Incorrect input, try again.\n");
        while (getchar() != '\n'); // Consume all the chars untill the '\n'
        return 1;
    }

    return 0;
}

void
sort_abc(struct person* arr)
{
    // A pointer to the end of array
    person_t* end = arr + PEOPLE_SIZE;

    for (person_t* i = arr; i < end; i++) {
        for (person_t* j = i+1; j < end; j++) {
            if (BIGGER_THAN(i->name, j->name)) {
                person_t tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}

int 
main() 
{
    struct person  p_arr[PEOPLE_SIZE];
    struct person* p_itr;

    p_itr = p_arr;

    int i = 0;
    while (i < PEOPLE_SIZE) {
        printf("\nFill the data of person %i\n", i+1);

        if (input("Enter name:", "%.49s", &p_itr->name))
            continue; // Trying again
        if (input("Enter surname:", "%.49s", &p_itr->surname))
            continue;
        if (input("Enter age:", "%hi", &p_itr->age))
            continue;

        i++;
        p_itr++;
    }

    sort_abc(p_arr);

    printf("\nSorted people:\n");
    for (int i = 0; i < PEOPLE_SIZE; i++) {
        printf("%s %s, ", p_arr[i].name, p_arr[i].surname);
        printf("age: %hi\n", p_arr[i].age);
    }

    return 0;
}