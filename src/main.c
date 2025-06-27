#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "calc.h"


int main(int argc, char **argv) {
    float num1, num2;

    if (argc == 2 && strcmp(argv[1], help_command) == 0) {
        help_info();
        exit(EXIT_FAILURE);
    }

    if (argc != 4) {
        fprintf(stderr, "Error: Invalid commands\n");
        help_info();
        exit(EXIT_FAILURE);
    }

    char *end1;
    num1 = strtof(argv[2], &end1);
    if (*end1 || errno == ERANGE) {
        fprintf(stderr, "Error: Invalid argument, it must be a number\n");
        exit(EXIT_FAILURE);
    }

    char *end2;
    num2 = strtof(argv[3], &end2);
    if (*end2 || errno == ERANGE) {
        fprintf(stderr, "Error: Invalid argument, it must be a number\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], addition) == 0) {
        printf("%.2f + %.2f = %.2f\n", num1, num2, add_nums(num1, num2));
    } else if (strcmp(argv[1], subtraction) == 0) {
        printf("%.2f - %.2f = %.2f\n", num1, num2, sub_nums(num1, num2));
    } else if (strcmp(argv[1], multiplication) == 0) {
        printf("%.2f * %.2f = %.2f\n", num1, num2, mul_nums(num1, num2));
    } else if (strcmp(argv[1], division) == 0) {
        if (num2 == 0) {
            printf("Error: division by 0!\n");
            exit(EXIT_FAILURE);
        }
        printf("%.2f / %.2f = %.2f\n", num1, num2, div_nums(num1, num2));
    } else if (strcmp(argv[1], power_numbers) == 0) {
        pow_nums(num1, num2);
    } else {
        fprintf(stderr, "Error: Invalid command\n");
        help_info();
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
