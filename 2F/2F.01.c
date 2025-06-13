#include <stdio.h>

int main() 
{
    int num1, num2;
    int op;

    printf("Available operations:\n\n");
    
    printf("1: Sum two numbers \n");
    printf("2: Sub two numbers \n");
    printf("3: Multiply two numbers \n");
    printf("4: Divide two numbers \n");


    printf("Enter number 1: ");
    if (!scanf("%i", &num1)) {
        return 1;
    }

    printf("Enter number 2: ");
    if (!scanf("%i", &num2)) {
        return 1;
    }

    printf("Enter operation: ");
    if (!scanf("%i", &op)) {
        return 1;
    }

    switch (op) {
        case 1:
            printf("%i\n", num1 + num2);
            break;

        case 2:
            printf("%i\n", num1 - num2);
            break;

        case 3:
            printf("%i\n", num1 * num2);
            break;
            
        case 4:
            printf("%i\n", num1 / num2);
            break;
    }

    return 0;   
}