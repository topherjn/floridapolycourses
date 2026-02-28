#include<stdio.h>

int factorial(int num);

int main(void)
{
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("%d! = %d\n", num, factorial(num));

    return 0;
}

int factorial(int num)
{
    if(num <= 1) return 1;

    return num * factorial(num - 1);
}
