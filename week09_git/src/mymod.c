#include <stdio.h>
#include <math.h>
#include "myops.h"

double mymod(double a, double b){
    printf("This is mymod().\n");
    return fmod(a, b);
}
