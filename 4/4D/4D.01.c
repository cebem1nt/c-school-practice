#include <stdio.h>

double fabs(double num) 
{
    if (num < 0) 
    {
        return -num;
    }
    return num;
}

// Cubic root calculation using Newton Raphson method, no, i will not use math.h, i dont like math
// https://www.geeksforgeeks.org/engineering-mathematics/newton-raphson-method/

void rt3(double* x) 
{
    if (*x == 0) {
        *x = 0;
        return;
    }

    double y = *x / 3.0;
    double epsilon = 0.0000000001;

    // https://math.stackexchange.com/questions/3586214/newtons-method-for-cube-root
    while (1) {
        double next_y = (2.0 * y / 3.0) + (*x / (3.0 * y * y));

        if (fabs(next_y - y) < epsilon) 
        {
            *x = next_y;
            return;
        }

        y = next_y;
    }
}


int main() 
{
    double a = 16;
    double b = 8;

    rt3(&a);
    rt3(&b);

    printf("cubic root of 16 is %f\n", a);
    printf("cubic root of 8 is %f\n",b);
}