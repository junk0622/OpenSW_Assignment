#include <stdio.h>
double calculate(char* op, double a, double b){
printf("Calculating.....\n");
return 0.0;
}

int main(void){
 double a, b;
char op[3];
printf("~~~ Welcome to my calculator ~~~\n\n");
printf("Enter expression (e.g. 1 + 2): ");
scanf("%lf %s %lf", &a, op, &b);
printf("Result = %.2lf\n", calculate(op, a, b));
return 0;
}
