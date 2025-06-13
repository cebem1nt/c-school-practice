#include <stdio.h>

int main () 
{
    int age;
    printf("Entre el edad: ");
    
    if (!scanf("%i", &age)) {
        return 1;
    } 

    if (age < 20) {
        printf("Joven");
    }

    else if (age >= 20 && age <= 39) {
        printf("Mayor");
    }

    else if (age > 40) {
        printf("Tercera edad");
    }
}