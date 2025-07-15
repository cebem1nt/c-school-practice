#include <stdio.h>
#include <string.h>

int main() 
{
    char name1[100],
         name2[100];

    int age1, age2;
    int i = 1;

    while (i <= 2) {
        char* name = i == 1 ? name1 : name2;
        int* age = i == 1 ? &age1 : &age2;

        printf("Enter name %i: ", i);
        fgets(name, sizeof(name1), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter age: ");
        if (!scanf("%i", age)) {
            return 1;
        }        

        getchar();
        i++;
    }

    if (age1 > age2) {
        printf("%s is older than %s\n", name1, name2);
    }
    else if (age1 == age2) {
        printf("%s have same age %s\n", name1, name2);
    }
    else {
        printf("%s is older than %s\n", name2, name1);
    }

    return 0;
}
