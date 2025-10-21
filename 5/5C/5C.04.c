#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define INIT_PEOPLE_SIZE 2

typedef struct person {
    unsigned int id;
    char name[MAX_NAME_SIZE];
    char surname[MAX_NAME_SIZE];
} person_t;

typedef struct people_arr {
    struct person* arr;
    size_t size;
    size_t len;
} people_arr_t;

void err_exit(const char* reason) 
{
    fprintf(stderr, "%s\n", reason);
    exit(EXIT_FAILURE);
}

void
input(char* prompt, char* type, void* dest) 
{

    while (1) {
        printf("%s: ", prompt);
        if (scanf(type, dest) != 1) {
            fprintf(stderr, "Incorrect input, try again.\n");
            while (getchar() != '\n');
            continue;
        }

        break;
    }
}

person_t*
find_person(people_arr_t* p, unsigned int id) 
{
    for (size_t i = 0; i < p->size; i++) {
        if (p->arr[i].id == id)
            return &p->arr[i];
    } 

    return NULL;
}

int
people_arr_init(people_arr_t* dest) 
{
    dest->arr = malloc(sizeof(person_t) * INIT_PEOPLE_SIZE);

    if (!dest->arr)
        return 1;

    dest->size = INIT_PEOPLE_SIZE;
    dest->len = 0;

    return 0;
}

int
people_arr_resize(people_arr_t* p) {
    size_t new_size = p->size * 2;
    person_t* new_arr = realloc(p->arr, new_size);

    if (!new_arr)
        return 1;

    p->arr = new_arr;
    p->size = new_size;

    return 0;
}

void
people_arr_append(people_arr_t* dest, person_t person)
{
    if (dest->len + 1 > dest->size) {
        if (people_arr_resize(dest))
            err_exit("Could not resize array");
    }

    dest->arr[dest->len] = person;
    dest->len++;
}

int
main() 
{
    struct people_arr arr;
    if (people_arr_init(&arr))
        err_exit("Could not allocate memory");

    while (1) {
        struct person p;

        input("Enter person ID", "%zu", &p.id);
        
        if (p.id == 0)
            break;
        
        input("Enter person name", "%49s", &p.name);
        input("Enter person surname", "%49s", &p.surname);

        people_arr_append(&arr, p);
    }

    unsigned int id_to_search;
    person_t* found; 
    
    input("Enter id to search for", "%u", &id_to_search);
    found = find_person(&arr, id_to_search);

    if (found) {
        printf("Found person: \n");
        printf("\t Name: %s\n", found->name);
        printf("\t Surname: %s\n", found->surname);
    } else {
        printf("No such person with %u\n", id_to_search);
    }

    return 0;
}