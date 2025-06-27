#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

float add_nums(float a, float b) { return a + b; }
float sub_nums(float a, float b) { return a - b; }
float mul_nums(float a, float b) { return a * b; }
float div_nums(float a, float b) { return a / b; }

float pow_nums(float a, float b) {
    if (a < 0 || b < 0) {
        printf("Invalid input: pow() doesn't accept negative numbers\n");
        exit(EXIT_FAILURE);
    }
    printf("%.2f", a);
    for (int i = 1; i < b; i++) printf(" * %.2f", a);
    printf(" = %.2f\n", pow(a, b));
    return pow(a, b);
}

void help_info(void) {
    fprintf(stderr, "Usage: ./main <command> <num1> <num2>\n");
    fprintf(stderr, "Commands: add sub mul div pow --help\n");
}

