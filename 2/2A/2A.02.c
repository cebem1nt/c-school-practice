#include <stdio.h>

int main()
{
    int num;

    printf("Entre un numero mayor que 17: ");

    if (!scanf("%i", &num)) {
        return 1;
    } 
    

    // WARNING !!! UGLY CODE!!! 
    // (Exercise wants me to do it, i did not want it, really)
    if (num > 17) {}

    else {
        printf("Flaco, te dije, un numero MAYOR que 17. \n");
        return 1;
    }

    return 0;
}