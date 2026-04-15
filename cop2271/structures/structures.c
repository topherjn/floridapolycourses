#include<stdio.h>

struct fraction
{
    int numerator;
    int denominator;
};

int main(void)
{
    
    struct fraction half;

    half.numerator = 1;
    half.denominator = 2;

    printf("%d/%d\n", half.numerator, half.denominator);

    return 0;
}