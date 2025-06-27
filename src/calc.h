#ifndef CALC_H
#define CALC_H

//The commands
#define addition "add"
#define subtraction "sub"
#define multiplication "mul"
#define division "div"
#define power_numbers "pow"
#define help_command "--help"

float add_nums(float a, float b);
float sub_nums(float a, float b);
float mul_nums(float a, float b);
float div_nums(float a, float b);
float pow_nums(float a, float b);
void help_info(void);

#endif
