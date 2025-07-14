//FLAGS: -lm
#include <stdio.h>
#include <math.h>

// Yes I will implement my own sqrt function but will use pow()
// from math.h to verify is it real sqrt, that's my life position.
// Questions?

double sqrt(double n) {
    if (n < 0) {
        return -1; // Not real sqrt, no need to calculate imgainary numbers
    }

    double x = n;
    double y = (x + 1) / 2;

    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }

    return x;
}

int main() {
    double num,
           root;

    printf("Enter number: ");

    if (!scanf("%lf", &num)) {
        printf("\nIncorrect value");
        return 1;
    }

    printf("\n");
    root = sqrt(num);

    if (pow(root, 2) == num) {
        printf("Real square root of %.0lf is %.0lf\n", num, root);
        return 0;
    }

    printf("Can not calculate real sqrt of %lf\n", num);
    return 1;
}
