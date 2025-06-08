#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() 
{
    char* hola = "HOLA";
    char* separator = malloc(20);

    strcpy(separator, "  ");

    for (int i=0 ; i < 10 ; i++ ) {
        printf("%s%s \n", separator, hola);
        strcat(separator, "  ");
    }

    free(separator);
    return 0; 
}