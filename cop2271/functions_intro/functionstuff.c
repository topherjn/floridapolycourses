#include<stdio.h>

int f(int num);

int main(void)
{
    printf("%d\n", f(2));

    return 0;
}

int f(int number)
{
    return number * number;
}

