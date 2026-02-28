#include<stdio.h>

void print_binary(int n);

int main(void)
{
    
    print_binary(13);

    return 0;
}

void print_binary(int n)
{
    if(n > 1) print_binary(n / 2);

    printf("%d", n % 2);
}