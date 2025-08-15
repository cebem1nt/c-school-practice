#include <stdio.h>
#include <string.h>

float divide(float x, float y) 
{
    return x / y;
}

float mul(float x, float y) 
{
    return x * y;
}

float sum(float x, float y) 
{
    return x + y;
}

float rest(float x, float y) 
{
    return x - y;
}

int main() {
    float x;
    float y;
    char opt[256];

    while (1) {
        printf("Enter number 1: ");
        if (scanf("%f", &x) != 1) {
            return 1;
        }

        printf("Enter number 2: ");
        if (scanf("%f", &y) != 1) {
            return 1;
        }

        printf("Operations: \n sum - add \n rest - subtract \n mul - multiply \n div - divide\n");
        printf("Enter operation: ");
        if (scanf("%s", opt) != 1) {
            return 1;
        }

        float res;

        if (strcmp(opt, "sum") == 0) 
        {
            res = sum(x, y);
        } 
        else if (strcmp(opt, "rest") == 0) {
            res = rest(x, y);
        }
        else if (strcmp(opt, "mul") == 0) {
            res = mul(x, y);
        } 
        else if (strcmp(opt, "div") == 0) {
            res = divide(x, y);
        } 
        else {
            printf("Invalid operation.\n");
            return 1;
        }

        printf("Result: %.2f\n", res);
    }

    return 0;
}
