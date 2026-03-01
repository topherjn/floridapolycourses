#include<stdio.h>

void print_binary(int n);

int main(void)
{
    int decimal_number = 0;

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimal_number);
    
    print_binary(decimal_number);

    return 0;
}

void print_binary(int n)
{
    if(n > 1) print_binary(n / 2);

    printf("%d", n % 2);
}