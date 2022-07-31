#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int x);

int main(int argc, char *argv[])
{
    unsigned int x = 5;
    if (argc > 1)
        x = atoi(argv[1]);
    if (x > 19)
    {
        printf("Max Input:\t`19`\n");
        return 0;
    }
    printf("Factorial of:\t%d! = %d\n", x, factorial(x));
    return 0;
}

unsigned int factorial(unsigned int x)
{
    if (x < 2)
        return 1;
    unsigned int factor = 1;
    for (int i = 1; i < x; i++)
        factor *= i;
    return factor * x;
}