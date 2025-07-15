#include <stdio.h>
#include <string.h>

int main() 
{
    char name[100];
    int salary;

    printf("Enter name: ");
    // scanf does not seem to hande strings with spaces correctly
    
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character

    printf("\nEnter salary: ");
    if (!scanf("%i", &salary)) {
        return 1;
    }

    printf("\n");    
    printf("%s earns %i \n", name, salary);

    return 0;
}