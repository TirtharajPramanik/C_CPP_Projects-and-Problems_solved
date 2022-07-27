#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

int recursion(int max) {
    if(max < 0) max = -max;
    if(max == 0) return 0;
    if(max == 1) return 0;
    else if(max == 2) return 1;
    return recursion(max-1) + recursion(max-2);
}

int main(int argc, char *argv[]) {
    int num = 10;
    if(argc > 1 && isNumber(argv[1])) num = atoi(argv[1]);
    if(num > 47) {
    printf("Upto 47 is valid!\n");
    return 0;
    }
    printf("%dth Fibonacci Number:\t%d\n", num, recursion(num));
    return 0;
}