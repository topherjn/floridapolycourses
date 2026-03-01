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
    /* base case */
    if(num <= 1) return 1;

    /* recursive part */
    return num * factorial(num - 1);
}
