#include <stdio.h>
#include "myops.h"

double mydiv(double a, double b){
    printf("This is mydiv().\n");
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}
