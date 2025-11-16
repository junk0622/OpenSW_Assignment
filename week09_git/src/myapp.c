#include <stdio.h>
#include <string.h>
#include "myops.h"

double calculate(char* op, double a, double b){
    printf("Calculating.....\n");

    if (strcmp(op, "+") == 0) {
        return myadd(a, b);
    } else if (strcmp(op, "-") == 0) {
        return mysub(a, b);
    } else if (strcmp(op, "*") == 0) {
        return mymul(a, b);
    } else if (strcmp(op, "/") == 0) {
        return mydiv(a, b);
    } else if (strcmp(op, "%") == 0) { // advanced 브랜치 내용
        return mymod(a, b);
    } else if (strcmp(op, "^") == 0) { // advanced 브랜치 내용
        return mypow(a, b);
    } else {
        printf("Unsupported operation: %s\n", op);
        return 0.0;
    }
}

int main(void){
    double a, b;
    char op[3];

    printf("~~~ Welcome to my calculator ~~~\n\n");
    printf("Enter expression (e.g. 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result = %.2lf\n", calculate(op, a, b));
    printf("~~~ Good bye. See you again ~~~\n\n"); // main 브랜치 내용

    return 0;
}
